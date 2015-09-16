/* Switch on and off ISR enables */
#include "crit.h"

volatile void s_crit(uint8_t mode) // Start critical section of code that needs protection for the ISR
{ // remember old high and low int bits so they can be restored correctly
	static uint8_t H_tmp = 0; // keep track of time spent in critical section

	_asm nop _endasm // asm code to disable compiler optimizations
		LCRIT[CRITC] = INTCONbits.GIEL;
	if (mode & 0x2) INTCONbits.GIEL = LOW;
	HCRIT[CRITC] = INTCONbits.GIEH;
	if (mode & 0x1) INTCONbits.GIEH = LOW;
	critc_count++; // track counts
	CRITC++; // array nest level index
	if (CRITC > critc_level) critc_level = CRITC; // track nesting checking
	if ((uint8_t) CRITC == (uint8_t) CRITC1) { // only update at the first level
		H_tmp = INTCONbits.GIEH;
		INTCONbits.GIEH = LOW;
		hirez_0.bt[LOW] = TMR0L;
		hirez_0.bt[HIGH] = TMR0H; // load high byte in tmp counter
		if ((uint8_t) hirez_0.lt == (uint8_t) LOW) hirez_0.lt = 0xffff; // counter overflow
		INTCONbits.GIEH = H_tmp;
	}
}

volatile void e_crit(void) // End section of code that need protection from ISR
{
	static uint8_t H_tmp = 0;

	_asm nop _endasm // asm code to disable compiler optimizations
	if (CRITC) {
		CRITC--;
		if (!CRITC) { // only update at the first level
			H_tmp = INTCONbits.GIEH;
			INTCONbits.GIEH = LOW;
			hirez_1.bt[LOW] = TMR0L;
			hirez_1.bt[HIGH] = TMR0H; // load high byte in tmp counter
			if (!hirez_1.lt) hirez_1.lt = 0xffff; // counter overflow
			if (hirez_1.lt >= hirez_0.lt) hirez_count[5] += (hirez_1.lt - hirez_0.lt); // how many counts we were in routines
			INTCONbits.GIEH = H_tmp;
		}
		INTCONbits.GIEH = HCRIT[CRITC];
		INTCONbits.GIEL = LCRIT[CRITC];
	} else { // default to all interrupts on with overflow
		INTCONbits.GIEH = HIGH;
		INTCONbits.GIEL = HIGH;
		TXREG2 = '*'; // restore with no save, output to terminal port
	}
}

volatile void clear_crit(void)
{
	CRITC = NULL0;
	hirez_count[5] = NULL0;
	INTCONbits.GIEH = HIGH;
	INTCONbits.GIEL = HIGH;
}

void write_data_eeprom(uint8_t data, uint8_t count, uint16_t addr, uint16_t offset)
{
	//  eeprom data array: 0=CHECKMARK checksum, 1=length of array 2=start of array data, array offset, writes must be protected from ISR
	if (addr == NULL0) { // only write header when on addr 0
		s_crit(HL);
		Busy_eep();
		Write_b_eep(0 + offset, CHECKMARK); //      write checksum  at byte 0 of the offset
		Busy_eep();
		Write_b_eep(1 + offset, count); // length of data
		Busy_eep();
		e_crit();
	}
	s_crit(HL);
	Busy_eep();
	Write_b_eep(addr + 2 + offset, data); //  data
	Busy_eep();
	e_crit();
}

uint8_t read_data_eeprom(uint16_t addr, uint16_t offset)
{
	Busy_eep();
	return Read_b_eep(addr + offset);
}

void wipe_data_eeprom(uint16_t max_eeprom)
{
	static uint16_t z;

	for (z = 0; z < max_eeprom; z++) {
		s_crit(HL);
		Busy_eep();
		Write_b_eep(z, 0xff); // overwrite with all ones.
		Busy_eep();
		e_crit();
	}
}

// this should save daily data to  EEPROM/NETWORK or any process that needs daily status updates

uint8_t save_daily(void)
{
	static uint8_t z = 0;

	for (z = 0; z <= battnum; z++) {
		write_data_eeprom(hist[z].h[11], battnum, z, EEPROM_HIS); // total charge cycles
	}
	P.SAVE_DAILY = FALSE;
	return TRUE;
}