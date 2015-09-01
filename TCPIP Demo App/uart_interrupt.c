/*********************************************************************
* MBMC	serial data network driver for TCPIP Demo App for PIC32 Ethernet Starter Kit
* This code runs as the system master to the PIC18 solar monitor data ack system
**********************************************************************/

#include <plib.h>					// Peripheral Library
#include "mbmc.h"
#include "TCPIP Stack/TCPIP.h"

#define MASK9BIT	0x0100
#define	TRUE	1
#define	FALSE	0
#define MBMC_TIMEOUT	20000000ul	
#define DESIRED_BAUDRATE    	(9600)      //The desired BaudRate
				


void 	WriteString(const char *string);
int		mbmc_getdata(WORD,BYTE *,DWORD);
int		MBMCApp(void);

struct	mbmcdata	mbmc_buffer;
struct	SDCARD		sdc0;
struct	celltype	cell[5];
struct	histtype	hist[5];
volatile	struct	mbmcflagtype	mbmcflag;
volatile	BYTE	data_default[2];
struct	mbmcstatustype	mbmc_status={0,FALSE,FALSE,FALSE,FALSE};


int MBMCApp(void)
{
	static	BYTE do_once=FALSE;

	if (!do_once) {
	mbmcflag.data_timeout=0;
	mbmcflag.rx_9bit=FALSE;
	mbmcflag.tx_9bit=FALSE;


	mPORTDClearBits(BIT_2); 		// Turn off RD2 on startup.
	mPORTDSetPinsDigitalOut(BIT_2);	// Make RD2 as output.
	mPORTDClearBits(BIT_1); 		// Turn off RD1 on startup.
	mPORTDSetPinsDigitalOut(BIT_1);	// Make RD1 as output.
	mPORTDClearBits(BIT_0); 		// Turn off RD0 on startup.
	mPORTDSetPinsDigitalOut(BIT_0);	// Make RD0 as output.


    UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART2, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART2, UART_DATA_SIZE_9_BITS | UART_PARITY_NONE | UART_STOP_BITS_1 );
    UARTSetDataRate(UART2, GetPeripheralClock(), DESIRED_BAUDRATE);
    UARTEnable(UART2, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

	// Configure UART2 RX Interrupt
	INTEnable(INT_SOURCE_UART_RX(UART2), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART2), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART2), INT_SUB_PRIORITY_LEVEL_0);

	mbmcflag.host_ack=HOST_ACK+MASK9BIT;
	mbmcflag.host_cmd=HOST_REQ+MASK9BIT;
	// set a place keeper buffer
	mbmcflag.data_ptr=(BYTE*)&data_default;
	mbmcflag.data_len=1;
	mbmcflag.data_pos=0;

	// Let interrupt handler do the work
	mbmc_status.seq=0;			// checking
		do_once=TRUE;
	}

		if (mbmc_status.seq == 0) {
				if (mbmc_getdata(HOST_REAL,(BYTE*)&mbmc_buffer.solar,sizeof(mbmc_buffer)) == 0) {
					mbmc_status.seq++;
					mbmc_status.real_valid=TRUE;
				} else {
					mbmc_status.real_valid=FALSE;
				};
		}

		if (mbmc_status.seq == 1) {
				if (mbmc_getdata(HOST_CELL,(BYTE*)&cell,sizeof(cell)) == 0) {
					mbmc_status.seq++;
					mbmc_status.cell_valid=TRUE;
				} else { 
					mbmc_status.cell_valid=FALSE;			
				};
		}

		if (mbmc_status.seq == 2) {
				if (mbmc_getdata(HOST_HIST,(BYTE*)&hist,sizeof(hist)) == 0) {
					mbmc_status.seq++;
					mbmc_status.hist_valid=TRUE;
				} else { 
					mbmc_status.hist_valid=FALSE;				
				};
		}

		if (mbmc_status.real_valid && mbmc_status.cell_valid && mbmc_status.hist_valid) {
			mbmc_status.seq=0;							// all data transfered, reset sequence counter
			mPORTDToggleBits(BIT_0);
			mbmc_status.real_valid = mbmc_status.cell_valid = mbmc_status.hist_valid = FALSE;
			return 1;
		}

	return 0;
}

/* written as a state machine for the TCPIP stack app */
int	mbmc_getdata(WORD host_cmd, BYTE *data_ptr, DWORD data_len)
{
	int	ret;									// in progress return code
	static	BYTE mbmc_getdata_status=FALSE;

	ret=1;
	if (!mbmc_getdata_status) {
		mbmcflag.host_cmd=host_cmd+MASK9BIT;	// make command 9 bit high
		mbmcflag.data_ptr=data_ptr;
		mbmcflag.data_len=data_len;
		mbmcflag.data_pos=0;
		mbmcflag.mbmc_done=FALSE;				// allow data into buffer
		mbmcflag.host_done=FALSE;				// clear the command completed flag

    	while(!UARTTransmitterIsReady(UART2));
		WriteUART2(mbmcflag.host_cmd);
    	while(!UARTTransmissionHasCompleted(UART2));
		mbmc_status.cmdsent++;
		mbmc_status.sent++;

		mbmcflag.data_timeout=0;
		mbmc_getdata_status=TRUE;
	}
	
	if (mbmcflag.host_done) {
		mbmc_getdata_status=FALSE;
	} else {
		mbmcflag.data_timeout++;		
	}

	if (mbmcflag.host_done &&  (mbmcflag.data_timeout <MBMC_TIMEOUT)) {				// received reply
        while(!UARTTransmitterIsReady(UART2));
		WriteUART2(mbmcflag.host_ack);
        while(!UARTTransmissionHasCompleted(UART2));
		mbmc_status.acksent++;
		mbmc_status.sent++;
		mbmc_getdata_status=FALSE;							// we are done
		mPORTDClearBits(BIT_1);								// turn off comm leds 
		mPORTDClearBits(BIT_2); 
		mbmcflag.data_timeout=0;				// reset timer
		ret=0;												// completed return code
	}

	if ((mbmcflag.data_timeout >=MBMC_TIMEOUT))  {									// timed out
		mPORTDToggleBits(BIT_0);				// blinks if timing out.
		mPORTDClearBits(BIT_1);					// turn off comm leds 
		mPORTDClearBits(BIT_2); 
		mbmc_getdata_status=FALSE;				// we are done but
		mbmcflag.data_timeout=0;				// reset timer
		ret=(-1);								// we had a error
	}

	return (ret);
}

// UART 2 interrupt handler
// it is set at priority level 2
void __ISR(_UART2_VECTOR, ipl2) IntUart2Handler(void)
{
	static	WORD	rx9data;
	// Is this an RX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_RX(UART2)))
	{
		rx9data=ReadUART2();
		mbmc_status.received++;

		if ((rx9data & MASK9BIT) != 0) {			// check for bit 9
			mbmcflag.rx_9bit=TRUE;					// set command  flag
			mbmc_status.cmdreceived++;
		} else {
			mPORTDToggleBits(BIT_2);				// data LED
			mbmcflag.data_timeout=0;				// reset timer
			mbmcflag.rx_9bit=FALSE;					// clear command flag

			if (!mbmcflag.mbmc_done) {									// we need more data
				mbmcflag.data_ptr[mbmcflag.data_pos] = (BYTE) rx9data;	// move received data into buffer
				if (mbmcflag.data_pos++ >= mbmcflag.data_len) {			// the data buffer is filled to data_len
					mbmcflag.mbmc_done=TRUE;							// data block has been received
					// set a place keeper buffer
					mbmcflag.data_ptr=(BYTE*)&data_default;
					mbmcflag.data_len=1;
					mbmcflag.data_pos=0;
				} else {												// nothing for now
				}
			}

		}

		if (mbmcflag.rx_9bit) {
			if (rx9data == mbmcflag.host_ack) {
				mbmc_status.ackreceived++;
				mPORTDToggleBits(BIT_1);			// command LED
				mbmcflag.host_done=TRUE;
				mbmcflag.data_timeout=0;			// reset timer
			}
		}
		// Clear the RX interrupt Flag
	    INTClearFlag(INT_SOURCE_UART_RX(UART2));

	}

	// We don't care about TX interrupt
	if ( INTGetFlag(INT_SOURCE_UART_TX(UART2)) )
	{
		INTClearFlag(INT_SOURCE_UART_TX(UART2));
	}
}

