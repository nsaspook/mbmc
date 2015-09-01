/* SPI interface to SDCARD */
#include "sdspi.h"
#include <string.h>

#ifdef SDEBUG
#include <usart.h>
#define SDEBUGM(msg)  P2wait(); TXREG2 = msg
#else
#define SDEBUGM(msg)
#endif

void sd_select(void)
{
	SELECT();
}

void sd_deselect(void)
{
	DESELECT();
}

/*
 * CRC7 for commands Supported in SPI mode with an argument of 0 "stuff bits only"
 * CRC7 (As an 8bit value with bit zero "End bit" set)
 * Command (As an 8 bit value with bit 6 "transmission *bit" set)

Command.........Abbreviation............CRC7
CMD0............GO_IDLE_STATE...........0x95
CMD9............SEND_CSD................0xAf
CMD10...........SEND_CID................0x1B
CMD12...........STOP_TRANSMISSION.......0x61
CMD13...........SEND_STATUS.............0x0D
CMD27...........PROGRAM_CSD.............0xDB
CMD38...........ERASE...................0xA5
CMD55...........APP_CMD.................0x65
CMD58...........READ_OCR................0xFD

ACMD51..........SEND_SCR................0xC7
 */

uint16_t CRC16(uint8_t *data, uint16_t length)
{
	static uint16_t crc = 0;

	crc = 0;
	while (length--) {
		crc = (uint8_t) (crc >> SHIFT8) | (crc << SHIFT8);
		crc ^= *data++;
		crc ^= (uint8_t) (crc & 0xff) >> SHIFT4;
		crc ^= (crc << SHIFT8) << SHIFT4;
		crc ^= ((crc & 0xff) << SHIFT4) << SHIFT1;
	}

	return( crc);
}


/*-----------------------------------------------------------------------*/
/* Transmit a byte to MMC/SD via SPI  (Platform dependent)                  */

/*-----------------------------------------------------------------------*/

uint8_t xmit_spi(uint8_t dat)
{
	static uint8_t retry = 0;

	retry = 0;
	SSP1BUF = dat;
	do {
		ClrWdt();
		retry++;
		if ((uint8_t) retry >= (uint8_t) 100) {
			return SSP1BUF; // timeout
		}
	} while (!SSP1STATbits.BF);
	return SSP1BUF;
}


/*-----------------------------------------------------------------------*/
/* Receive a byte from MMC via SPI  (Platform dependent)                 */

/*-----------------------------------------------------------------------*/

uint8_t rcvr_spi(void)
{
	return xmit_spi(0xff);
}

/*-----------------------------------------------------------------------*/
/* Wait for card ready                                                   */

/*-----------------------------------------------------------------------*/

uint8_t wait_ready(void)
{
	static uint8_t res, retry = 0;

	retry = 0;
	do {
		ClrWdt();
		res = xmit_spi(0xFF);
		retry++;
		if (retry >= (uint8_t) 100) {
			return res; // timeout
		}
	} while ((res != (uint8_t) 0xFF));

	return res;
}


/*-----------------------------------------------------------------------*/
/* Send a command packet to MMC/SD Card                                          */

/*-----------------------------------------------------------------------*/

uint8_t send_cmd(uint8_t cmd, /* Command byte */
	uint32_t arg /* Argument */
	)
{
	static uint8_t n, res, ccrc[5], argc;

	if (cmd & 0x80) { /* ACMD<n> is the command sequense of CMD55-CMD<n> */
		cmd &= 0x7F;
		res = send_cmd(CMD55, 0);
		if (res > (uint8_t) 1)
			return res;
	}

	/* Select the card and wait for ready */
	DESELECT();
	SELECT();
	if (wait_ready() != 0xFF)
		return 0xFF;
	ccrc[0] = cmd;
	argc = arg;
	ccrc[1] = (uint8_t) (argc >> SHIFT24);
	ccrc[2] = (uint8_t) (argc >> SHIFT16);
	ccrc[3] = (uint8_t) (argc >> SHIFT8);
	ccrc[4] = (uint8_t) argc;
	/* Send command packet */
	xmit_spi(cmd); /* Command */
	xmit_spi((uint8_t) (arg >> SHIFT24)); /* Argument[31..24] */
	xmit_spi((uint8_t) (arg >> SHIFT16)); /* Argument[23..16] */
	xmit_spi((uint8_t) (arg >> SHIFT8)); /* Argument[15..8] */
	xmit_spi((uint8_t) arg); /* Argument[7..0] */
	n = (uint8_t) 0xFF; // fake crc7
	if (cmd == (uint8_t) CMD0)
		n = 0x95; /* CRC for CMD0(0) */
	if (cmd == (uint8_t) CMD8)
		n = 0x87; /* CRC for CMD8(0x1AA) */
	if (cmd == (uint8_t) CRC_ON_OFF)
		n = 0xAD;
	xmit_spi(n);

	/* Receive command response */
	if (cmd == (uint8_t) CMD12)
		rcvr_spi(); /* Skip a stuff byte when stop reading */
	n = 10; /* Wait for a valid response in timeout of 10 attempts */
	do
		res = rcvr_spi(); while ((res & 0x80) && --n);
	return res; /* Return with the response value */
}

void send_dummys(void)
{
	static uint8_t n;
	for (n = 10; n; n--)
		xmit_spi(0xff); /* 80 dummy clocks */
}

int16_t MMC_get_volume_info(void)
//****************************************************************************
{
	SDC0.sddetect = FALSE;
	if (!SDC0.sdinit) {
		if (!SDC0.sdinit) return ERR1; // no card after second try
	}
	vinf = &MMC_volume_Info; //Init the pointer;
	if (SDC0.sdtype == SDT6) { // SDHC size calc
		vinf->sector_count = (((uint32_t) csd[7] & 0x3F) << SHIFT16) | ((uint32_t) csd[8] << SHIFT8) | (uint32_t) csd[9];
		vinf->size_MB = (vinf->sector_count + 1) * SDBUFFERSIZE;
	} else { // SD/MMC size calc
		vinf->read_block_len = (uint32_t) 1 << (csd[5] & 0x0F); // sector size

		vinf->sector_count = (uint32_t) csd[6] & 0x03;
		vinf->sector_count <<= SHIFT8;
		vinf->sector_count += (uint32_t) csd[7];
		vinf->sector_count <<= SHIFT2;
		vinf->sector_count += (uint32_t) ((uint32_t) csd[8] & 0xc0) >> SHIFT6;

		vinf->sector_multiply = (uint32_t) csd[9] & 0x03;
		vinf->sector_multiply <<= SHIFT1;
		vinf->sector_multiply += (uint32_t) ((uint32_t) csd[10] & 0x80) >> SHIFT7;
		// work out the MBs
		// mega bytes in u08 == C_SIZE / (2^(9-C_SIZE_MULT))
		vinf->size_MB = (vinf->sector_count >> (9 - vinf->sector_multiply)) * (vinf->read_block_len / SDBUFFERSIZE);
	}

	vinf->serial = ((uint32_t) cid[9] << SHIFT24) + ((uint32_t) cid[10] << SHIFT16) + ((uint32_t) cid[11] << SHIFT8) + (uint32_t) cid[12]; // Serial Number
	// get the name of the card
	vinf->name[0] = cid[3];
	vinf->name[1] = cid[4];
	vinf->name[2] = cid[5];
	vinf->name[3] = cid[6];
	vinf->name[4] = cid[7];
	vinf->name[5] = 0x00; //end flag

	SDC0.sddetect = TRUE;
	return NULL;
}

/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */

/*-----------------------------------------------------------------------*/

int16_t disk_initialize()
{
	static uint8_t n, cmd, ocr[4], i;

	SDSAFE = S_OFF;
	SDC0.sdinit = FALSE;
	DESELECT();
	send_dummys(); /* 80 dummy clocks */
	SELECT();
	SDC0.sdtype = 0;
	send_cmd(CMD0, 0);

	if (send_cmd(CMD0, 0) == (uint8_t) HIGH) { /* Enter Idle state */

		if (send_cmd(CMD8, 0x1AA) == (uint8_t) HIGH) { /* SDC Ver2+ */
			for (n = 0; n < (uint8_t) 4; n++)
				ocr[n] = rcvr_spi(); /* Get trailng data of R7 resp */
			if ((ocr[2] == (uint8_t) 0x01) && (ocr[3] == (uint8_t) 0xAA)) { /* The card can work at vdd range of 2.7-3.6V */
				send_cmd(CRC_ON_OFF, 0); // no checking CRC, redundant
				while (send_cmd(ACMD41, 1UL << SHIFT30)); /* ACMD41 with HCS bit */

				wdttime(SDTIME); // wait for card to init
				SSP1CON1 = SSP1CON1 & 0xf0; // set to full speed FOSC_4
				if (send_cmd(CMD58, 0) == (uint8_t) NULL) { /* Check CCS bit in the OCR */
					for (n = 0; n < (uint8_t) 4; n++)
						ocr[n] = rcvr_spi();
					SDC0.sdtype = (ocr[0] & 0x40) ? SDT6 : SDT2;
				}
			}
		} else { /* SDC Ver1 or MMC */
			if (send_cmd(ACMD41, 0) <= (uint8_t) 1) {
				SDC0.sdtype = SDT2;
				cmd = ACMD41; /* SDC */
			} else {
				SDC0.sdtype = SDT1;
				cmd = CMD1; /* MMC */
			}
			while (send_cmd(cmd, 0)); /* Wait for leaving idle state */

			if (send_cmd(CMD16, SDBUFFERSIZE) == (uint8_t) NULL); /* Select R/W block length */
		}
		if (send_cmd(CMD9, 0) == (uint8_t) NULL) { // get CSD
			for (i = 0; i < (uint8_t) 16; i++)
				if (rcvr_spi() == 0xFE)
					break; // cheat, got data token
			for (n = 0; n < (uint8_t) 16; n++)
				csd[n] = rcvr_spi();

		}
		if (send_cmd(CMD10, 0) == (uint8_t) NULL) { // get CID
			for (i = 0; i < (uint8_t) 16; i++)
				if (rcvr_spi() == 0xFE)
					break; // cheat, got data token
			for (n = 0; n < (uint8_t) 16; n++)
				cid[n] = rcvr_spi();
		}
		send_dummys(); /* 80 dummy clocks */
	} else {
		return ERR1; //      no card
	}
	if (SDC0.sdtype != SDT6) {
		return ERR2; //      wrong type card
	}
	SDC0.sdinit = TRUE;
	SDSAFE = S_ON;
	return NULL;
}

void wipe_sdbuffer(void)
{
	memset(block_buffer, 0, SDBUFFERSIZE);
}

/************************** MMC/SHDC Write Block **************************************/

int16_t mmc_write_block(uint32_t block_number)
{
	static int16_t retry, i, nsec, ssm;
	static uint8_t tmp;
	static uint32_t block_tmp;

	SDSAFE = S_OFF;
	SDEBUGM('W');
	ClrWdt(); // reset the WDT timer
	block_tmp = block_number;
	if (SDC0.sdtype != SDT6) { // use byte style blocks for SD cards
		block_tmp = block_tmp << SHIFT9;
	}

	DESELECT();
	send_dummys();
	SELECT();
	retry = 0;
	do {
		if (SDC0.sdtype == SDT6) {
			tmp = send_cmd(CMD24, block_tmp); // send sdhc write block, arg is block number
			SDEBUGM('6');
		} else {
			tmp = send_cmd(CMD25, block_tmp); // send sd multi write block, arg is block number
			SDEBUGM('2');
		}
		retry++;
		if (retry == 100) {
			DESELECT();
			SDEBUGM('E');
			return ERR1; // write command error
		}
		ClrWdt(); // reset the WDT timer
	} while (tmp != (uint8_t) NULL);
	send_dummys();

	if (SDC0.sdtype == SDT6) {
		xmit_spi(0xFE); // send single block token

		for (i = 0; i < SDBUFFERSIZE; i++) {
			xmit_spi(block_buffer[i]); // send data to card
		}
		xmit_spi(0xFF); // dummy CRC16
		xmit_spi(0xFF);
		if ((rcvr_spi() & 0x1f) != (uint8_t) 0x05) {
			DESELECT();
			SDEBUGM('E');
			return ERR1;
		}
		while (rcvr_spi() != 0xff); // wait
		DESELECT(); // set SS = 1 (off)
		SDEBUGM('w');
		SDSAFE = S_ON;
		return NULL;
	} else {
		ssm = vinf->read_block_len / SDBUFFERSIZE;
		for (nsec = 1; nsec <= ssm; nsec++) {
			xmit_spi(0b11111100); // send multi block token
			for (i = 0; i < SDBUFFERSIZE; i++) {
				xmit_spi(block_buffer[i]); // send data to card
			}
			xmit_spi(0xFF); // dummy CRC16
			xmit_spi(0xFF);
			if ((rcvr_spi() & 0x1f) != (uint8_t) 0x05) {
				DESELECT();
				SDEBUGM('E');
				return ERR1;
			}
			while (rcvr_spi() != 0xff); // wait
		}
		xmit_spi(0b11111101); // stop tran token
		while (rcvr_spi() != 0xff); // wait
		DESELECT(); // set SS = 1 (off)
		SDEBUGM('w');
		SDSAFE = S_ON;
		return NULL;
	}
}

/************************** MMC/SDHC Read Block **************************************/

/**** Reads a SDBUFFERSIZE Byte block from the MMC  ****/

int16_t mmc_read_block(uint32_t block_number)
{
	static int16_t retry, i, nsec, ssm;
	static uint8_t tmp;
	static uint32_t block_tmp;

	SDSAFE = S_OFF;
	SDEBUGM('R');
	ClrWdt(); // reset the WDT timer
	block_tmp = block_number;
	if (SDC0.sdtype != SDT6) { // use byte style blocks for SD cards
		block_tmp = block_tmp << SHIFT9;
	}

	DESELECT();
	send_dummys();
	SELECT();
	retry = 0;
	do {
		if (SDC0.sdtype == SDT6) {
			tmp = send_cmd(CMD17, block_tmp); // send sdhc read single block command
			SDEBUGM('6');
		} else {
			tmp = send_cmd(CMD18, block_tmp); // send sdhc read single block command
			SDEBUGM('2');
		}
		retry++;
		if (retry == 1000) {
			DESELECT();
			SDEBUGM('E');
			return ERR1; // write command error
		}
		ClrWdt(); // reset the WDT timer
	} while (tmp != (uint8_t) NULL);

	retry = 0;
	do {
		tmp = rcvr_spi();
		retry++;
		if (retry == 1000) {
			DESELECT();
			SDEBUGM('E');
			return ERR1; // receive command error
		}
	} while (tmp != (uint8_t) 0xfe); // got data token

	if (SDC0.sdtype == SDT6) {
		for (i = 0; i < SDBUFFERSIZE; i++) {
			block_buffer[i] = rcvr_spi(); // send data to card
		}
		rcvr_spi(); // CRC16 bytes that are not needed
		rcvr_spi();
		DESELECT(); // set SS = 1 (off)
		send_dummys(); // give mmc the clocks it needs to finish off
		SDEBUGM('r');
		SDSAFE = S_ON;
		return NULL;
	} else {
		ssm = vinf->read_block_len / SDBUFFERSIZE;
		for (nsec = 1; nsec <= ssm; nsec++) {
			for (i = 0; i < SDBUFFERSIZE; i++) {
				block_buffer[i] = rcvr_spi(); // send data to card
			}
			rcvr_spi(); // CRC16 bytes that are not needed
			rcvr_spi();
		}
		// send stop tran
		tmp = send_cmd(CMD12, block_tmp); // send sdhc read single block command
		rcvr_spi();
		while (rcvr_spi() == (uint8_t) NULL); // wait
		DESELECT(); // set SS = 1 (off)
		send_dummys(); // give mmc the clocks it needs to finish off
		SDEBUGM('r');
		SDSAFE = S_ON;
		return NULL;
	}
}

void init_sdspi(void)
{
	SSP1CON1bits.SSPEN = LOW; // clear SPI1 EN for init
	PIE1bits.SSP1IE = LOW; // disable interrupts for sure

	OpenSPI1(SPI_FOSC_64, MODE_00, SMPEND);
	SSP1CON1 |= SPI_FOSC_64; // set clock to low speed

}
