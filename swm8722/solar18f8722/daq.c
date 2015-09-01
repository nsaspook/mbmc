/* Read analog voltage and current inputs */
#include "daq.h"

// ADC channel, number of adc sample to average, cal offset, cal correction factor, result divisor, raw ADC data without corrections

uint32_t ADC_get(uint8_t chan, uint16_t samples, uint16_t offset, uint8_t correct, int16_t div, uint8_t raw)
{
	static uint16_t i; // used for fast 128 and slow sample loops >256
	static uint32_t result;

	SetChanADC(chan);
	Delay10TCYx(ADC_CHAN_DELAY);
	result = 0;
	for (i = 0; i < samples; i++) {
		ConvertADC();
		while (BusyADC());
		result += (uint32_t) ReadADC();
	}
	result /= samples;
	if (raw) return result;
	result = result * (uint32_t) (offset - ADC_NULL + correct); //      voltage correction factors
	if (div <= 1) return result;
	return(uint32_t) (result / (uint32_t) div);
}

/* switch to chan 10 (shorted to ground) to reset ADC measurement cap to zero before next measurement */
void ADC_zero(void)
{
	zero_ref = ADC_get(ADC_CH10, 1, 0, 0, 1, TRUE);
}

void ADC_read(void) // update all voltage/current readings and set load current in 'currentload' variable
{ // ADC is opened and config'd in main
	static uint32_t Vin = 0, rawp1 = 0, rawp2 = 0, rawp3 = 0, vbatol_t = 0, solar_t = 0;

	ClrWdt(); // reset the WDT timer
	ADC_zero();
	vbatol_t = ADC_get(ADC_CH0, ADC_SAMP_F, ADC0_OFF, adc_cal[0], 100, FALSE); // controller bus voltage
	s_crit(HL); // turn off inte
	R.systemvoltage = vbatol_t;
	e_crit();

	ADC_zero();
	solar_t = ADC_get(ADC_CH1, ADC_SAMP_S, ADC1_OFF, adc_cal[1], 100, FALSE); // CC output voltage
	s_crit(HL); // turn off  inte
	R.ccvoltage = solar_t;
	e_crit();

	ADC_zero();
	// very long measurement sample time to get several PWM cycles from CC
	Vin = ADC_get(ADC_CH5, ADC_SAMP_S, ADC5_OFF, adc_cal[5], 1, TRUE); // RF0  for input current AMP300, battery current
	a300 = Vin; // raw ADC value
	Vin = Vin - (AMP300_OF - ADC_NULL + adc_cal[12]); // set zero NULL0 point
	current_t = (int32_t) Vin * (ADC5_OFF - ADC_NULL + adc_cal[5]);
	if (ABSL(current_t) < AMPZ)
		current_t = 0; // zero bit noise
	current_t = (int32_t) ((float) current_t / 10.0); // tenths of an amp
	current_t = (int32_t) ((float) current_t / (float) AMP300_SEN);
	current_t = (int32_t) lp_filter((float) current_t, LP_CURRENT, TRUE); // use digital filter for current
	if (a300 == NULL0) current_t = 0; // if sensor disconnected (zero) read zero current

	ADC_zero();
	rawp1 = ADC_get(ADC_CH11, ADC_SAMP_S, ADC3_OFF, adc_cal[3], 100, FALSE); // input PV voltage, CHANGED to ANA11, the calibration data is still in adc3

	ADC_zero();
	rawp2 = ADC_get(ADC_CH4, ADC_SAMP_F, ADC4_OFF, adc_cal[4], 100, FALSE); // battery 1, RA4 is digital input RA5 for A/D AN4.

	ADC_zero();
	rawp3 = ADC_get(ADC_CH6, ADC_SAMP_F, ADC6_OFF, adc_cal[6], 100, FALSE); // battery 2, RF1  for A/D AN6.

	s_crit(HL);
	R.inputvoltage = rawp1; // set input PV voltage monitor line
	R.primarypower[B0] = 0; // NULL0 battery
	R.primarypower[B1] = rawp2; // this is battery 1, the primary power storage cell.
	R.primarypower[B2] = rawp3; // this is battery 2, the backup power storage cell
	e_crit();

	ADC_zero();
	// very long measurement sample time to get several PWM cycles from CC
	Vin = ADC_get(ADC_CH2, ADC_SAMP_S, ADC2_OFF, adc_cal[2], 1, TRUE); // for input current AMP50, PV current
	a50 = Vin; // raw ADC value
	Vin = Vin - (AMP50_OF - ADC_NULL + adc_cal[10]); // set zero NULL0 point
	currentin_t = (int32_t) Vin * (ADC2_OFF - ADC_NULL + adc_cal[2]);
	if (ABSL(currentin_t) < AMPZ)
		currentin_t = 0; // zero bit noise
	currentin_t = (int32_t) ((float) currentin_t / (float) 10.0); // tenths of an amp
	currentin_t = (int32_t) ((float) currentin_t / (float) AMP50_SEN);
	currentin_t = (int32_t) lp_filter((float) currentin_t, LP_CURRENTIN, TRUE); // use digital filter for current
	if (a50 == NULL0) currentin_t = 0; // if sensor disconnected read zero

	ADC_zero();
	Vin = ADC_get(ADC_CH9, ADC_SAMP_F, ADC9_OFF, adc_cal[9], 1, TRUE); // thermistor channel
	s_crit(HL);
	R.thermo_batt = Vin;
	therm = Vin;
	R.thermo_batt -= THERMO_OFF;
	R.thermo_batt = (int32_t) (((float) R.thermo_batt * (float) THERMO_SEN)*10.0); // tenths of C
	if ((R.thermo_batt > 1100) || (R.thermo_batt <-500)) R.thermo_batt = Temp_ZERO; // check limits 110C/-50C , default to 25C if out of limits
	e_crit();

	ADC_zero();
	// very long measurement sample time to get several PWM cycles from CC
	Vin = ADC_get(ADC_CH8, ADC_SAMP_S, ADC8_OFF, adc_cal[8], 1, TRUE); // for charger current AMP50
	a50c = Vin;
	Vin = Vin - (AMP50c_OF - ADC_NULL + adc_cal[11]); // set zero NULL0 point
	currentcharger_t = Vin * (ADC8_OFF - ADC_NULL + adc_cal[8]);
	if (ABSL(currentcharger_t) < AMPZ)
		currentcharger_t = 0; // zero bit noise
	currentcharger_t = currentcharger_t / 10; // tenths of an amp
	currentcharger_t = currentcharger_t / AMP50c_SEN;
	currentcharger_t = (int32_t) lp_filter((float) currentcharger_t, LP_CURRENTCHARGER, TRUE);
	if (a50c == NULL0) currentcharger_t = 0; // if sensor disconnected read zero
	s_crit(HL); // turn off int
	R.currentcharger = currentcharger_t;
	R.currentcharger = 0; //FIXME NO SENSOR CONNECTED

	R.current = current_t;
	if (currentin_t < 0) currentin_t = 0; // suppress neg input currents
	R.currentin = currentin_t;
	C.currentload = R.current; // assume no charging first
	if ((CCS.boc == B1) || (CCS.boc == B2)) C.currentload = R.currentin + R.current; // find the current flow on the load when the battery is also in circuit
	if (C.currentload < 0) C.currentload = 0; // no neg inverter currents
	if (SIM_MODE) do_sim(); // set test data
	if (CCS.boc == B0) R.currentin = 0; // set to zero if nothing is connected for amploc zero drift fix
	if (CCS.boi == B1) { // Calc the Inverter batteries current flows
		if (CCS.boc == B1 || B_GANGED) {
			cell[B1].current = R.current;
			cell[B2].current = 0;
		}
		if (CCS.boc == B2) {
			cell[B1].current = C.currentload;
			cell[B2].current = (-R.currentin); // make it neg
			if (B_GANGED) cell[B2].current = 0; // all current is from the B1 ganged cell
		}
		if ((CCS.boc > B2) || (CCS.boc == 0)) {
			cell[B1].current = C.currentload;
			cell[B2].current = 0;
		}
	} else { // CCS.boi=2
		if (CCS.boc == B1) {
			cell[B1].current = (-R.currentin); // make it neg
			cell[B2].current = C.currentload;
		}
		if (CCS.boc == B2) {
			cell[B1].current = 0;
			cell[B2].current = R.current;
		}
		if ((CCS.boc > B2) || (CCS.boc == 0)) {
			cell[B1].current = 0;
			cell[B2].current = C.currentload;
		}
	}
	e_crit();
	ADC_zero(); // ground ADC input
	ClrWdt(); // reset the WDT timer
}

void do_sim(void) // create baseline test data, call in a critical section to protect from ISR updates
{
	R.current = 0l;
	R.currentin = 0l;
	C.currentload = 50l;
	R.currentcharger = 0l;
	R.thermo_batt = 250l;
	R.systemvoltage = 12000ul;
	R.ccvoltage = 0ul;
	R.inputvoltage = 0ul;
	R.primarypower[B0] = 0; // NULL0 battery
	R.primarypower[B1] = 13200ul;
//	rawp2 = 13200ul;
	cell[B1].voltage = 13200l;
	cell[B1].noload = 13400l;
	R.primarypower[B2] = 13200ul;
//	rawp3 = 13200ul;
	cell[B2].voltage = 13200l;
	cell[B2].noload = 13400l;
	P.POWER_UNSTABLE = FALSE;
	P.PRIPOWEROK = TRUE;
	if (SIM_FLAG & 0b00000001) {
		R.current = 100l;
		R.currentin = 100l;
		C.currentload = 150l;
		R.currentcharger = 0l;
		R.thermo_batt = 250l;
		R.systemvoltage = 12000ul;
		R.ccvoltage = 13400ul;
		R.inputvoltage = 15500ul;
//		rawp1 = R.inputvoltage;
	}
	if (SIM_FLAG & 0b00000010) {
		R.current = 0l;
		R.currentin = 0l;
		C.currentload = 50l;
		R.currentcharger = 0l;
		R.thermo_batt = 250l;
		R.systemvoltage = 12000ul;
		R.ccvoltage = 0ul;
		R.inputvoltage = 0ul;
//		rawp1 = R.inputvoltage;
	}
	if (SIM_FLAG & 0b00000100);
	if (SIM_FLAG & 0b00001000);
}

void set_adc_gain(void) // set ADC gains
{
	uint8_t adc_index, z;

	ADC_read(); // update all values
	display_system();
	putrs2USART(adcg0);
	YNKEY = WAIT_M;
	keynum = NULL0;
	while ((YNKEY == WAIT_M) && (keynum == NULL0)) {
		idle_loop();
	}
	if (YNKEY != WAIT_M) {
		putrs2USART(adcg2);
		return;
	}

	adc_index = (uint8_t) keynum - (uint8_t) 0x30; // convert to binary number
	if (adc_index > ADC_INDEX) {
		putrs2USART(adcg2);
		return;
	}

	YNKEY = WAIT_M;


	while (YNKEY == WAIT_M) {
		sprintf(bootstr2, "\n\r Selected ADC %u for calibration.", adc_index);
		puts2USART(bootstr2);
		putrs2USART(adcg3);
		YNKEY = WAIT_M;
		c2raw = NULL0;
		while (c2raw == NULL0) {
			idle_loop();
		}
		if (YNKEY == NO_M) {
			putrs2USART(adcg2);
			return;
		}
		if ((c2raw == 'Q') || (c2raw == 'q')) {
			putrs2USART(adcg2);
			return;
		}
		if (c2raw == 'M') adc_cal[adc_index] += 5;
		if (c2raw == 'L') adc_cal[adc_index] -= 5;
		if (c2raw == 'm') adc_cal[adc_index]++;
		if (c2raw == 'l') adc_cal[adc_index]--;
		c2raw = NULL0;
		ADC_read(); // update all values
		display_system();
	}

	putrs2USART(adcg4);
	for (z = 0; z < ADC_SLOTS; z++) {
		write_data_eeprom(adc_cal[z], ADC_SLOTS, z, 8);
	}

	putrs2USART(adcg1);
}

void zero_amploc(void) // set zero current setpoint from ADC reading from a50 a50c a300, write to EEPROM
{
	uint8_t z, E_SAVE = LATE;

	putrs2USART(zero0);
	YNKEY = WAIT_M;
	while (YNKEY == WAIT_M) {
		wdtdelay(10);
		idle_loop();
	}
	if (YNKEY == NO_M) {
		putrs2USART(zero2);
		return;
	}
	putrs2USART(zero4);
	adc_cal[10] = adc_cal[11] = adc_cal[12] = adc_cal[13] = ADC_NULL; // reset offsets to zero (ADC_NULL)
	// read adc data for zero setpoint

	SOLAROFF = R_ON;
	CCOUTOPENSW = R_ON;
	if (battnum > HISTBATTNUM) { // disconnect from controller power buss to get zero current in sensor
		BAT1 = R_ON;
		BAT2 = R_ON;
		CHRG1 = R_OFF;
		CHRG2 = R_OFF;
	}
	wdttime(BATRUNS); // wait for relays to remove PV input voltage

	ADC_read(); // a50=adc_[10], a50c=adc_cal[11], a300=adc_cal[12]
	SOLAROFF = R_OFF;
	CCOUTOPENSW = R_OFF;
	if (battnum > 3) { // reconnect to controller power buss
		BAT1 = R_OFF;
		BAT2 = R_OFF;
	}

	adc_cal[10] = (uint8_t) (ADC_NULL + (int16_t) ((int16_t) a50 - (int16_t) AMP50_OF));
	sprintf(bootstr2, "\n\r Zero offset %i, PV current %i, AMP50_OF %i", (int16_t) adc_cal[10], a50, AMP50_OF);
	puts2USART(bootstr2);

	//      no a50c sensor yet
	adc_cal[11] = (uint8_t) (ADC_NULL + (int16_t) ((int16_t) a50c - (int16_t) AMP50c_OF));
	sprintf(bootstr2, "\n\r Zero offset %i, Charger current %i, AMP50c_OF %i", (int16_t) adc_cal[11], a50c, AMP50c_OF);
	puts2USART(bootstr2);

	adc_cal[12] = (uint8_t) (ADC_NULL + (int16_t) ((int16_t) a300 - (int16_t) AMP300_OF));
	sprintf(bootstr2, "\n\r Zero offset %i, Inverter current %i, AMP300_OF %i", (int16_t) adc_cal[12], a300, AMP300_OF);
	puts2USART(bootstr2);

	for (z = 0; z < ADC_SLOTS; z++) {
		write_data_eeprom(adc_cal[z], ADC_SLOTS, z, 8);
	}
	putrs2USART(zero1);
	LATE = E_SAVE;
}

void zero_amploc_PV(void) // set zero current setpoint from ADC reading from a50, don't write to EEPROM
{

	adc_cal[10] = ADC_NULL; // reset offsets to zero (ADC_NULL)
	// read adc data for zero setpoint

	SOLAROFF = R_ON;
	CCOUTOPENSW = R_ON;
	wdttime(BATRUN); // wait for relays to remove PV input voltage
	ADC_read(); // a50=adc_[10], a50c=adc_cal[11], a300=adc_cal[12]
	SOLAROFF = R_OFF;
	CCOUTOPENSW = R_OFF;
	s_crit(HL);
	adc_cal[10] = (uint8_t) (ADC_NULL + (int16_t) ((int16_t) a50 - (int16_t) AMP50_OF));
	e_crit();
	term_time();
	putrs2USART(zero3);
}