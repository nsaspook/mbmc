/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*********************************************************************
 * MBMC	serial data network driver for TCPIP Demo App for PIC32 Ethernet Starter Kit
 * This code runs as the system master to the PIC18 solar monitor data ack system
 **********************************************************************/

#include <plib.h>				// Peripheral Library
#include "mbmc.h"
#include "crc8.h"
#include "TCPIP Stack/TCPIP.h"
#include <lega-c/time.h>
#include <limits.h>
#include <math.h>

#define	TRUE	1
#define	FALSE	0
#define MBMC_TIMEOUT	200000ul
#define	TI_TIME			15              // about 60 seconds
#define	MI_TIME			INT_MAX         // reset sample counter
#define DESIRED_BAUDRATE    	(38400)         //The desired BaudRate
#define CBUF_LENGTH 128					// MBMC serial command buffer      

void WriteString(const char *string);
int mbmc_getdata(WORD, BYTE *, DWORD);
void mbmc_updatechart(int);
int MBMCApp(void);
float dvdt_roc(int, int);
float lp_filter_diff(float, int, int);
void put_mbmc_serial_buf(char);
void init_mbmc_serial_buf(void);


int TIi = 0, MIi = 0, HRi = 0;
volatile DWORD utc_time, CCEFF, PVEFF, TOTEFF, time_outs = 0, crc_errors = 0;
struct mbmcdata mbmc_buffer;
struct mbmcchart chart[4];
struct SDCARD sdc0;
struct celltype cell[5];
struct histtype hist[5];
volatile struct mbmcflagtype mbmcflag;
volatile struct mbmccmdtype mbmccmd;
volatile struct datadefaulttype dd;
volatile struct hoststattype hoststat;
volatile struct remote_daq_data remote_daq;
struct mbmcstatustype mbmc_status = {0, FALSE, FALSE, FALSE, FALSE, FALSE};
union Alarm alarms;
struct tm *mbmctime;
time_t ltime;
volatile char cbuf[CBUF_LENGTH], Head, Tail; // Buffer has CBUF_LENGTH elements
unsigned short mbmc_crc;

int MBMCApp(void)
{
	static DWORD do_once = FALSE;
	BYTE *data_buf;


	if (!do_once) {
		mbmcflag.data_timeout = 0;
		mbmcflag.rx_9bit = FALSE;
		mbmcflag.tx_9bit = FALSE;
		init_mbmc_serial_buf();
		remote_daq.new = FALSE;
		remote_daq.read = FALSE;
		remote_daq.offline = TRUE;

		mPORTDClearBits(BIT_2); // Turn off RD2 on startup.
		mPORTDSetPinsDigitalOut(BIT_2); // Make RD2 as output.
		mPORTDClearBits(BIT_1); // Turn off RD1 on startup.
		mPORTDSetPinsDigitalOut(BIT_1); // Make RD1 as output.
		mPORTDClearBits(BIT_0); // Turn off RD0 on startup.
		mPORTDSetPinsDigitalOut(BIT_0); // Make RD0 as output.

		UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY);
		UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
		UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
		UARTSetDataRate(UART1, GetPeripheralClock(), DESIRED_BAUDRATE);
		UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));


		UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);
		UARTSetFifoMode(UART2, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
		UARTSetLineControl(UART2, UART_DATA_SIZE_9_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
		UARTSetDataRate(UART2, GetPeripheralClock(), DESIRED_BAUDRATE);
		UARTEnable(UART2, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

		// Configure UART1 RX Interrupt
		INTEnable(INT_SOURCE_UART_RX(UART1), INT_ENABLED);
		INTSetVectorPriority(INT_VECTOR_UART(UART1), INT_PRIORITY_LEVEL_2);
		INTSetVectorSubPriority(INT_VECTOR_UART(UART1), INT_SUB_PRIORITY_LEVEL_0);

		// Configure UART2 RX Interrupt
		INTEnable(INT_SOURCE_UART_RX(UART2), INT_ENABLED);
		INTSetVectorPriority(INT_VECTOR_UART(UART2), INT_PRIORITY_LEVEL_2);
		INTSetVectorSubPriority(INT_VECTOR_UART(UART2), INT_SUB_PRIORITY_LEVEL_0);

		mbmcflag.host_ack = HOST_ACK + MASK9BIT; // this is for ACK only, not for commands
		mbmccmd.cmd = HOST_CMD_UTC_S;
		mbmccmd.ready = FALSE;
		// set a place keeper buffer
		mbmcflag.data_ptr = (BYTE*) & dd.data_default;
		mbmcflag.data_len = 4;
		mbmcflag.data_pos = 0;

		utc_time = SNTPGetUTCSeconds();
		ltime = utc_time;
		chart[0].pos = chart[1].pos = chart[2].pos = chart[3].pos = 0; // init the chart arrays
		chart[0].avg = chart[1].avg = chart[2].avg = chart[3].avg = 0.0;
		chart[0].gap = 10; // 24 min
		chart[1].gap = 200; //  8 hours
		chart[2].gap = 600; // 24 hours
		chart[3].gap = 200; //  8 hours eff chart
		// Let interrupt handler do the work
		mbmc_status.seq = 0; // checking
		do_once = TRUE;
	}

	if (mbmc_status.seq == 0) {
		if (mbmccmd.cmd == HOST_CMD_UTC_S || mbmccmd.cmd == HOST_SDC0) {
			data_buf = (BYTE*) & utc_time;
		} else {
			data_buf = (BYTE*) & dd.data_default;
		}
		if (mbmccmd.ready) { // we have something to send
			switch (mbmccmd.cmd) {
			case HOST_CMD_UTC_S: // sent UTC time to controller
				if (mbmc_getdata(mbmccmd.cmd, (BYTE*) data_buf, 4) == 0) {
					mbmc_status.seq++;
					mbmc_status.cmd_valid = TRUE;
					mbmccmd.ready = FALSE; // command has been sent and reply has been received
				} else {
					mbmc_status.cmd_valid = FALSE;
				};
				break;
			case HOST_SDC0: // request SD card header from controller
				if (mbmc_getdata(mbmccmd.cmd, (BYTE*) & sdc0, sizeof(sdc0)) == 0) {
					mbmc_status.seq++;
					mbmc_status.cmd_valid = TRUE;
					mbmccmd.ready = FALSE; // command has been sent and reply has been received
				} else {
					mbmc_status.cmd_valid = FALSE;
				};
				break;
			default: // all other commands
				if (mbmc_getdata(mbmccmd.cmd, (BYTE*) data_buf, 4) == 0) {
					mbmc_status.seq++;
					mbmc_status.cmd_valid = TRUE;
					mbmccmd.ready = FALSE; // command has been sent and reply has been received
				} else {
					mbmc_status.cmd_valid = FALSE;
				};
			}
		} else { // no command to send, so just say all is good
			mbmc_status.seq++;
			mbmc_status.cmd_valid = TRUE;
		};
	}

	if (mbmc_status.seq == 1) {
		if (mbmc_getdata(HOST_REAL, (BYTE*) & mbmc_buffer.ccvoltage, sizeof(mbmc_buffer)) == 0) {
			mbmc_status.seq++;
			mbmc_crc = (UINT16) mbmc_buffer.crc;
			mbmc_buffer.crc = CHECKMARK_CRC; //set 32 bit CRC value
			if (crc16_ccitt((unsigned char*) &mbmc_buffer.ccvoltage, (unsigned int) sizeof(mbmc_buffer)) == mbmc_crc) {
				mbmc_status.real_valid = TRUE;
			} else {
				crc_errors++;
				mbmc_status.seq = 0; // crc error, reset sequence counter
				mPORTDToggleBits(BIT_0);
				mbmc_status.real_valid = mbmc_status.cell_valid = mbmc_status.hist_valid = mbmc_status.cmd_valid = FALSE;
			}
		} else {
			mbmc_status.real_valid = FALSE;
		};
	}

	if (mbmc_status.seq == 2) {
		if (mbmc_getdata(HOST_CELL, (BYTE*) & cell, sizeof(cell)) == 0) {
			mbmc_status.seq++;
			mbmc_status.cell_valid = TRUE;
		} else {
			mbmc_status.cell_valid = FALSE;
		};
	}

	if (mbmc_status.seq == 3) {
		if (mbmc_getdata(HOST_HIST, (BYTE*) & hist, sizeof(hist)) == 0) {
			mbmc_status.seq++;
			mbmc_status.hist_valid = TRUE;
		} else {
			mbmc_status.hist_valid = FALSE;
		};
	}

	if (mbmc_status.real_valid && mbmc_status.cell_valid && mbmc_status.hist_valid && mbmc_status.cmd_valid) {
		mbmc_status.seq = 0; // all data transfered, reset sequence counter
		mPORTDToggleBits(BIT_0);
		mbmc_status.real_valid = mbmc_status.cell_valid = mbmc_status.hist_valid = mbmc_status.cmd_valid = FALSE;
		if (mbmc_buffer.ports.NEWDATA) remote_daq.read = TRUE; // main controller has updated data
		alarms.alarm_byte = mbmc_buffer.ports.ALARM;
		//		remote_daq.read = TRUE;	// DEBUG
		//	job loop
		PVEFF = hist[mbmc_buffer.boi].pv_eff;
		TOTEFF = hist[mbmc_buffer.boi].tot_eff;
		if ((mbmc_buffer.ccvoltage == 0) || (mbmc_buffer.inputvoltage == 0)) {
			CCEFF = 0;
		} else {
			CCEFF = (mbmc_buffer.ccvoltage * 100) / mbmc_buffer.inputvoltage;
		}
		// constrain the values
		if (CCEFF > 100) CCEFF = 100;
		if (CCEFF < 0) CCEFF = 0;
		if (PVEFF < 0) PVEFF = 0;
		if (TOTEFF < 0) TOTEFF = 0;
		if (TIi++ >= TI_TIME) { // once every min
			TIi = 0;
			utc_time = SNTPGetUTCSeconds();
			ltime = utc_time;
			if (((ltime - remote_daq.rawtime) > 120) && remote_daq.new) { // remote date timeout, new means remote connected once
				remote_daq.remotecurrent = remote_daq.voltagedrop = remote_daq.inputvoltage = remote_daq.inputcurrent = 0; // set to all zeros
				remote_daq.offline = TRUE;
			}
			mbmccmd.cmd = HOST_CMD_UTC_S;
			mbmccmd.ready = TRUE;
			mbmc_updatechart(MIi);
			if (MIi++ >= MI_TIME) {
				MIi = 0;
			}
		}
		dvdt_roc(mbmc_buffer.currentload, 0);
		dvdt_roc(mbmc_buffer.inputvoltage, 1);
		dvdt_roc(mbmc_buffer.currentin, 2);

		return 1;
	}

	return 0;
}

/*	move data received in the mbmc_buffer to the correct chart display array */
void mbmc_updatechart(int point)
{
	int cindex, dindex;

	mbmc_buffer.UTC = utc_time; // timestamp the data with host time
	if (hist[1].bsoc == 100) hist[1].bsoc = 99; // reduce char array size
	if (hist[2].bsoc == 100) hist[2].bsoc = 99;
	for (cindex = 0; cindex < 4; cindex++) { // check the chart arrays
		if ((point % chart[cindex].gap) == 0) { // do we save this data point?
			if (chart[cindex].pos >= MBMC_CHART_POINTS) { // check if FIFO needed
				chart[cindex].pos = MBMC_CHART_POINTS; // safety check
				for (dindex = 1; dindex < MBMC_CHART_POINTS; dindex++) {
					chart[cindex].data[dindex - 1] = chart[cindex].data[dindex]; // shift down to tail
				}
				if (cindex < 3) {
					chart[cindex].data[MBMC_CHART_POINTS - 1] = mbmc_buffer; // place data at head
				} else {
					chart[cindex].data[MBMC_CHART_POINTS - 1].pick = PVEFF; // chart 4 data
					chart[cindex].data[MBMC_CHART_POINTS - 1].boi = TOTEFF;
					chart[cindex].data[MBMC_CHART_POINTS - 1].boc = CCEFF;
					chart[cindex].data[MBMC_CHART_POINTS - 1].primarypower_B1 = (DWORD) hist[1].bsoc;
					if (mbmc_buffer.DIPSW & 0b00010000) { //GANGED
						chart[cindex].data[MBMC_CHART_POINTS - 1].primarypower_B2 = 0;
					} else {
						chart[cindex].data[MBMC_CHART_POINTS - 1].primarypower_B2 = (DWORD) hist[2].bsoc;
					}
				}
			} else { // add it to the array and pos++
				if (cindex < 3) {
					chart[cindex].data[chart[cindex].pos] = mbmc_buffer;
				} else {
					chart[cindex].data[chart[cindex].pos].pick = PVEFF; // chart 4 data
					chart[cindex].data[chart[cindex].pos].boi = TOTEFF;
					chart[cindex].data[chart[cindex].pos].boc = CCEFF;
					chart[cindex].data[chart[cindex].pos].primarypower_B1 = (DWORD) hist[1].bsoc;
					if (mbmc_buffer.DIPSW & 0b00010000) { //GANGED
						chart[cindex].data[MBMC_CHART_POINTS - 1].primarypower_B2 = 0;
					} else {
						chart[cindex].data[MBMC_CHART_POINTS - 1].primarypower_B2 = (DWORD) hist[2].bsoc;
					}
				}
				chart[cindex].pos++; // move to next array point
			}
			chart[cindex].edate = chart[cindex].data[chart[cindex].pos - 1].UTC;
			chart[cindex].sdate = chart[cindex].data[0].UTC;
		}
	}
}

float lp_filter_diff(float new_val, int cn, int chan_zero) // low pass/peak filter, slow rate of change down to zero, LPCHAN channels, value reset
{
	static float smooth[DIFFCHAN] = {0.0};
	float lp_speed, x;

	if ((cn >= DIFFCHAN) || (cn < 0)) return new_val;
	if (fabsf(new_val) < fabs(smooth[cn])) {
		lp_speed = 0.0315; // 1/32
	} else {
		lp_speed = 0.666; // fast
	}

	x = ((smooth[cn]*100.0) + (((new_val * 100.0)-(smooth[cn]*100.0)) * lp_speed)) / 100.0;
	smooth[cn] = x;
	if (chan_zero == 1) { // init value
		x = new_val;
		smooth[cn] = new_val;
	}
	if (chan_zero == (-1)) { // reset and return zero
		x = 0.0;
		smooth[cn] = 0.0;
	}
	return x;
}

/* written as a state machine for the TCPIP stack app */
int mbmc_getdata(WORD host_cmd, BYTE *data_ptr, DWORD data_len)
{
	int ret, i; // in progress return code
	static DWORD mbmc_getdata_status = FALSE;

	ret = 1;
	if (!mbmc_getdata_status) {
		mbmcflag.host_cmd = host_cmd + MASK9BIT; // make command 9 bit high
		mbmcflag.data_ptr = data_ptr;
		mbmcflag.data_len = data_len;
		mbmcflag.data_pos = 0;
		mbmcflag.mbmc_done = FALSE; // allow data into buffer
		mbmcflag.host_done = FALSE; // clear the command completed flag

		while (!UARTTransmitterIsReady(UART2));
		WriteUART2(mbmcflag.host_cmd);
		while (!UARTTransmissionHasCompleted(UART2)); // not too fast
		mbmc_status.cmdsent++;
		mbmc_status.sent++;

		if (host_cmd == HOST_CMD_UTC_S || host_cmd == HOST_SDC0) {
			for (i = 0; i < data_len; i++) { // send 4 bytes from data_ptr (UTC time, ETC ...)
				while (!UARTTransmitterIsReady(UART2));
				WriteUART2(data_ptr[i]);
				while (!UARTTransmissionHasCompleted(UART2)); // not too fast
				mbmc_status.sent++;
			}
		}

		mbmcflag.data_timeout = 0;
		mbmc_getdata_status = TRUE;
	}

	if (mbmcflag.host_done) {
		mbmc_getdata_status = FALSE;
	} else {
		mbmcflag.data_timeout++;
	}

	if (mbmcflag.host_done && (mbmcflag.data_timeout < MBMC_TIMEOUT)) { // received reply
		while (!UARTTransmitterIsReady(UART2));
		WriteUART2(mbmcflag.host_ack);
		while (!UARTTransmissionHasCompleted(UART2)); // not too fast
		mbmc_status.acksent++;
		mbmc_status.sent++;
		mbmc_getdata_status = FALSE; // we are done
		mPORTDClearBits(BIT_2);
		mbmcflag.data_timeout = 0; // reset timer
		remote_daq.timeout = FALSE;
		ret = 0; // completed return code
	}

	if ((mbmcflag.data_timeout >= MBMC_TIMEOUT)) { // timed out
		mPORTDToggleBits(BIT_0); // blinks if timing out.
		mPORTDClearBits(BIT_2);
		mbmc_getdata_status = FALSE; // we are done but
		mbmcflag.data_timeout = 0; // reset timer
		remote_daq.timeout = TRUE;
		time_outs++;
		ret = (-1); // we had an error
	}

	return(ret);
}

// UART 2 interrupt handler
// it is set at priority level 2

void __ISR(_UART_2_VECTOR, ipl2) IntUart2Handler(void)
{
	static WORD rx9data;
	// Is this an RX interrupt?
	if (INTGetFlag(INT_SOURCE_UART_RX(UART2))) {
		hoststat.usart2_rxint++;
		rx9data = ReadUART2();
		mbmc_status.received++;

		if ((rx9data & MASK9BIT) != 0) { // check for bit 9
			mbmcflag.rx_9bit = TRUE; // set command  flag
			mbmc_status.cmdreceived++;
		} else {
			mPORTDToggleBits(BIT_2); // data LED
			mbmcflag.data_timeout = 0; // reset timer
			mbmcflag.rx_9bit = FALSE; // clear command flag

			if (!mbmcflag.mbmc_done) { // we need more data
				mbmcflag.data_ptr[mbmcflag.data_pos] = (BYTE) rx9data; // move received data into buffer
				if (mbmcflag.data_pos++ >= mbmcflag.data_len) { // the data buffer is filled to data_len
					mbmcflag.mbmc_done = TRUE; // data block has been received
					// set a place keeper buffer
					mbmcflag.data_ptr = (BYTE*) & dd.data_default;
					mbmcflag.data_len = 4;
					mbmcflag.data_pos = 0;
				}
			}
		}
	}

	if (mbmcflag.rx_9bit) {
		if (rx9data == mbmcflag.host_ack) {
			mbmc_status.ackreceived++;
			mbmcflag.host_done = TRUE;
			mbmcflag.data_timeout = 0; // reset timer
		}
	}
	// Clear the RX interrupt Flag
	if (!UARTReceivedDataIsAvailable(UART2)) INTClearFlag(INT_SOURCE_UART_RX(UART2));



	// We don't care about TX2 interrupt
	if (INTGetFlag(INT_SOURCE_UART_TX(UART2))) {
		hoststat.usart2_txint++;
		INTClearFlag(INT_SOURCE_UART_TX(UART2));
	}
}

// UART 1 interrupt handler
// it is set at priority level 2

void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void)
{
	static WORD rx9data;
	// Is this an RX interrupt?
	if (INTGetFlag(INT_SOURCE_UART_RX(UART1))) {
		hoststat.usart1_rxint++;
		rx9data = ReadUART1();
		put_mbmc_serial_buf((char) rx9data); // put received data in buffer

		// Clear the RX interrupt Flag
		INTClearFlag(INT_SOURCE_UART_RX(UART1));

	}

	// We don't care about TX1 interrupt
	if (INTGetFlag(INT_SOURCE_UART_TX(UART1))) {
		hoststat.usart1_txint++;
		INTClearFlag(INT_SOURCE_UART_TX(UART1));
	}

}


//  RS232 receive buffer  for the telnet server
// cbuf length must be a factor of 2

void init_mbmc_serial_buf(void)
{
	Head = Tail = 0; // reset buffer pointers
}

void put_mbmc_serial_buf(char n)
{
	cbuf[(int) Head++] = n; // store at head, increment
	Head &= CBUF_LENGTH - 1; // fold over
	// Make sure Head never passes Tail
	if (Head == Tail) {
		Tail++;
		Tail &= (CBUF_LENGTH - 1);
	}
}

char get_mbmc_serial_buf(void)
{
	char n;
	if (Head == Tail) {
		return 0;
	}
	n = cbuf[(int) Tail++]; // get tail, increment
	Tail &= CBUF_LENGTH - 1; // fold over
	return n;
}

float dvdt_roc(int p_data, int d_index)
{
	float dvdt;
	time_t ltime = TickGetDiv256();
	static int pdata[16];
	static long tdata[16];
	static float sdata[16] = {100.0, 10.0, 100.0};

	if ((d_index < 0) || (d_index >= 16)) return 0.0;
	dvdt = ((float) (p_data - pdata[d_index])) / ((float) (ltime - tdata[d_index]));
	if (dvdt > 0.0) dvdt = dvdt * sdata[d_index]; // make sure it's a good number then scale it up a bit
	pdata[d_index] = p_data;
	tdata[d_index] = ltime;
	return lp_filter_diff(dvdt, d_index, 0);
}

