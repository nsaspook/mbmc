/* External device and battery power control */
#include "power.h"

/* function to stop fast switching of charger power, c_on and c_off are global static veriables */

/* 'sw' is the OFF/ON toggle/ 'now' is the timed action toggle YES/NO, the state of the CHARGERL output latch is returned */
uint8_t charger_power(uint8_t sw, uint8_t now)
{
	if (sw == ON) {
		if (now == YES) { // Do it now
			if (CHARGERL == R_OFF) { // if off then on
				alarm_buffer[almctr].bn = CCS.boc;
				alarm_buffer[almctr++].alm_num = 21;
				alarm_codes.alm_flag = TRUE;
				check_alarm(CCS.boi, " charger1 "); // send alarm codes to terminal if alm_flag is set
			}
			if (!AC_OFF_U) { // check for utility power
				CHARGERL = R_ON;
				s_crit(HL);
				c_on = V.timerint_count;
				e_crit();
			}
		} else { // Wait to stop power glitching
			if (((c_on - c_off) > C_TIME) || (c_off == NULL0)) { // wait if charger was just shut off.
				if (CHARGERL == R_OFF) { // if off then on
					alarm_buffer[almctr].bn = CCS.boc;
					alarm_buffer[almctr++].alm_num = 21;
					alarm_codes.alm_flag = TRUE;
					check_alarm(CCS.boi, " charger2 "); // send alarm codes to terminal if alm_flag is set
				}
				if (!AC_OFF_U) { // check for utility power
					CHARGERL = R_ON;
					s_crit(HL);
					c_on = V.timerint_count;
					e_crit();
				}
			}
		}
	} else {
		if (now == YES) { // Do it now
			if (CHARGERL == R_ON) { // if on then off
				alarm_buffer[almctr].bn = CCS.boi;
				alarm_buffer[almctr++].alm_num = 22;
				alarm_codes.alm_flag = TRUE;
				check_alarm(CCS.boi, " charger3 "); // send alarm codes to terminal if alm_flag is set
			}
			CHARGERL = R_OFF;
			s_crit(HL);
			c_off = V.timerint_count;
			e_crit();
		} else {
			if (((c_off - c_on) > C_TIME) || (c_on == NULL0)) { // wait if charger was just turned on.
				if (CHARGERL == R_ON) { // if on then off
					alarm_buffer[almctr].bn = CCS.boi;
					alarm_buffer[almctr++].alm_num = 22;
					alarm_codes.alm_flag = TRUE;
					check_alarm(CCS.boi, " charger4 "); // send alarm codes to terminal if alm_flag is set
				}
				CHARGERL = R_OFF;
				s_crit(HL);
				c_off = V.timerint_count;
				e_crit();
			}
		}
	}
	return CHARGERL;
}

/* function to stop fast switching of diversion power, d_on and d_off are global static variables */

/* 'sw' is the OFF/ON toggle/ 'now' is the timed action toggle YES/NO, the state of the DIVERSION output latch is returned */
uint8_t divert_power(uint8_t sw, uint8_t now, uint8_t status_code)
{
	if (DIPSW8 || SIM_MODE || DIVERSION_set) { // just turn on "FORCE" DIVERSION and return it's status
		if (DIVERSION == R_OFF) {
			alarm_buffer[almctr].bn = CCS.boc;
			alarm_buffer[almctr++].alm_num = 10;
			alarm_codes.alm_flag = TRUE;
			check_alarm(CCS.boi, " divert2 "); // send alarm codes to terminal if alarm_flag is set
		}
		DIVERSION = R_ON;
		return DIVERSION;
	}

	if (AC_OFF_I && DIVERSION == R_ON) { /* the inverter has tripped while diversion is running */
		if (DIVERSION == R_ON) { // if on then off
			alarm_buffer[almctr].bn = CCS.boi + (status_code << 4);
			alarm_buffer[almctr++].alm_num = 11;
			alarm_codes.alm_flag = TRUE;
			check_alarm(CCS.boi, " divert3 "); // send alarm codes to terminal if alm_flag is set
		}
		DIVERSION = R_OFF;
		return DIVERSION;
	}

	if (sw == ON) {
		s_crit(HL);
		d_on = V.timerint_count;
		e_crit();
		if (now == YES) { // Do it now
			if (!AC_OFF_I) {
				if (DIVERSION == R_OFF) { // if off then on
					alarm_buffer[almctr].bn = CCS.boi + (status_code << 4);
					alarm_buffer[almctr++].alm_num = 10;
					alarm_codes.alm_flag = TRUE;
					check_alarm(CCS.boi, " divert1 "); // send alarm codes to terminal if alarm_flag is set
				}
			}
		} else { // Wait to stop power glitching
			if (((d_on - d_off) > D_TIME) || (d_off == NULL0)) { // wait if diversion was just shut off.
				if (!AC_OFF_I) {
					if ((B.diversion <= PW_DIVERSION) && (B.today >= TODAY_Q) && (B.yesterday >= YESTER_Q)) { // check for good sunny weather
						if (DIVERSION == R_OFF) { // if off then on, log
							alarm_buffer[almctr].bn = CCS.boi + (status_code << 4);
							alarm_buffer[almctr++].alm_num = 10;
							alarm_codes.alm_flag = TRUE;
							check_alarm(CCS.boi, " divert2 "); // send alarm codes to terminal if alarm_flag is set
						}
						DIVERSION = R_ON; // check for inverter power
					}
				}
			}
		}
	} else {
		s_crit(HL);
		d_off = V.timerint_count;
		e_crit();
		if (now == YES) { // Do it now
			if (DIVERSION == R_ON) { // if on then off
				alarm_buffer[almctr].bn = CCS.boi + (status_code << 4);
				alarm_buffer[almctr++].alm_num = 11;
				alarm_codes.alm_flag = TRUE;
				check_alarm(CCS.boi, " divert3 "); // send alarm codes to terminal if alarm_flag is set
			}
			DIVERSION = R_OFF;
		} else {
			if (((d_off - d_on) > D_TIME) || (d_on == NULL0)) { // wait if diversion was just turned on.
				if (DIVERSION == R_ON) { // if on then off
					alarm_buffer[almctr].bn = CCS.boi + (status_code << 4);
					alarm_buffer[almctr++].alm_num = 11;
					alarm_codes.alm_flag = TRUE;
					check_alarm(CCS.boi, " divert4 "); // send alarm codes to terminal if alarm_flag is set
				}
				DIVERSION = R_OFF;
			}
		}
	}
	return DIVERSION;
}

void pv_pwm_set(int16_t limit) // set the PWM duty-cycle in the hardware PWM channel
{
	static int16_t duty_cycle;
	duty_cycle = (int16_t) ((float) MBMC.diversion.power * 10.23);
	if (limit != 0) {
		if (duty_cycle > limit) duty_cycle = limit;
	}
	SetDCPWM4(duty_cycle); // set PWM Duty Cycle [0..1023] for power
}

void pv_pwm_calc(float slope) // calc a duty-cycle from the PV power excess supply, CCEFF_DIFF is a global variable
{
	static int16_t CCEFF_DIFF_tmp;
	static float power_exp;

	power_exp = PWM_EXP + slope;
	CCEFF_DIFF_tmp = (int16_t) (99 - CCEFF); // power offset
	if ((CHARGERL == R_ON) && !PWMTEST) { // set all PWM to zero if charger is on and not testing
		pv_pwm_shutdown();
		CCEFF_DIFF_tmp = 0;
	}
	if (CCEFF_DIFF_tmp > PWM_LIMIT)
		CCEFF_DIFF_tmp = PWM_LIMIT;
	if (CCEFF_DIFF_tmp > PWM_SLOPE) {
		CCEFF_DIFF = (int16_t) lp_filter(pow((float) CCEFF_DIFF_tmp, power_exp), LP_PWM, TRUE); // control power
	} else {
		CCEFF_DIFF = (int16_t) lp_filter((float) CCEFF_DIFF_tmp, LP_PWM, TRUE); // control power
	}
	if (CCEFF_DIFF > 100)
		CCEFF_DIFF = 100; // limit max value to 100% power

}

void pv_pwm_shutdown(void)
{
	while (PIE1bits.TX1IE) {
	}; // don't update during host xmit
	MBMC.diversion.power = NULL0; // no power
	CCEFF_DIFF = NULL0; // shutdown the PWM system
	lp_filter(0.0, LP_PWM, (-1)); // zero control power filter
}

int16_t predict_energy(uint8_t mode) // use data collected to predict energy production/usage
{
	int16_t result;

	result = (-1);
	return result; // -1 failed, 0-100  precentage of energy in selected mode
}

/*  */
uint8_t pick_batt(uint8_t choice, uint8_t bn)
{
	static uint8_t boi = B0B, D_ON = LOW, D_OFF = LOW, C_MSG_STOP = FALSE;
	static uint8_t z = 0, pick = 0, alert_pick = 0;
	static uint32_t alert_clock = 0;
	static int32_t vloaded = 0;
	static float weight = 1.0;

	/*      look at cell and history data for next battery to charge or if all are good float on primary battery
	 *      choice is 0 for normal logic or 1-4 for battery to switch float to, 5 verbose
	 *      bn      = battery c40 is currently connected to, or 0
	 *      0       = float charge on primary if all charged
	 *      1-4     = battery to run full C40 charge sequence on
	 *      return  codes -1 = error, 0 = float, 1-4 charge this battery
	 */

	if ((bn > battnum) || (choice > battnum + 1)) {
		alarm_buffer[almctr].bn = choice;
		alarm_buffer[almctr++].alm_num = 23;
		alarm_codes.alm_flag = TRUE;
		check_alarm(bn, " pick_batt0 error "); // send alarm codes to terminal if alm_flag is set
		return(-1);
	}
	weight = MAXWEIGHT; // preload high value for picking
	pick = B0; // default B0
	idle_loop(); // idle time for isr

	/*              generate a weight value to decide who is next for charging      */
	ADC_read(); // refresh values
	for (z = 1; z <= battnum; z++) {

		if (cell[z].online && (cell[z].current > LOAD_CHECK)) {
			if (z > HISTBATTNUM) {
				vloaded = cell[z].voltage; // don't care for controller batteries
			} else {
				vloaded = R.primarypower[z]; // use current voltage to generate weight for 1&2 battery
			}
			if (vloaded < BATTADJ) { // battery voltage is very low under load
				hist[z].drate = (uint16_t) ((float) hist[z].rate * AHADJ); // adjust dynamic Ah rate to reduce battery capacity
				//		putrs2USART(lowbatt0);
			}
		}
		if (P.SYNCSOC && cell[z].cconline) { // check for # SOC SYNC command
			s_crit(HL);
			hist[z].udod = 0;
			hist[z].bsoc = 100;
			hist[z].ahi = 0;
			hist[z].ahir = 0;
			hist[z].aho = 0;
			hist[z].ahop = 0;
			hist[z].drate = 0;
			hist[z].rest_rate = 0; // stores energy in Ah than can be recovered by battery rest and other factors
			hist[z].rest_factor = RFACTOR; // Efficency factor of battery recovery
			// save starting values for cef_calc later
			B.start_ahi = hist[z].ahir; // uint32_t
			B.start_aho = hist[z].aho; // uint32_t
			B.start_ahu = hist[z].h[0]; // in tenth amp units (interger)
			P.SYNCSOC = FALSE;
			e_crit();
		}
		if ((hist[z].bsoc > 100) && (cell[z].cconline) && (R.currentin > 10)) { // if SOC while charging gets over 100 limit it to 100
			s_crit(HL);
			hist[z].udod = 0;
			hist[z].bsoc = 100;
			hist[z].aho = hist[z].ahi; // equalize
			if (hist[z].cef_calc <= CEF_RESET) { // reset current in/out balance if it's too far from normal charging
				hist[z].h[6] = 0; // reset Ah hist
				hist[z].h[0] = 0; // reset pAh hist
				hist[z].ahi = 0;
				hist[z].ahir = 0;
				hist[z].aho = 0;
				hist[z].ahop = 0;
				hist[z].rest_rate = 0; // stores energy in Ah than can be recovered by battery rest and other factors
				hist[z].rest_factor = RFACTOR; // Efficency factor of battery recovery
			}
			hist[z].drate = 0;
			hist[z].rest_rate = 0; // stores energy in Ah than can be recovered by battery rest and other factors
			hist[z].rest_factor = RFACTOR; // Efficency factor of battery recovery
			e_crit();
		}

		/* start calculation of battery selection weight for each power battery */
		cell[z].weight = (float) hist[z].bsoc * W_BASE_F; // battery selection weigth factor base
		cell[z].weight += (float) (cell[z].noload);

		if (CCMODE != FLOAT_W) { // use realtime data if floating charge, maybe faster switching to next battery
			cell[z].weight += (float) (cell[z].voltage); // just use the last tested data in charge cycle mode
		} else {
			if (z > HISTBATTNUM) {
				cell[z].weight += (float) (cell[z].voltage); // don't care for controller batteries
			} else {
				cell[z].weight += (float) (R.primarypower[z]); // use current voltage to generate weight for 1&2 battery
			}
		}
		// Use weight factors
		cell[z].weight -= (float) hist[z].h[4] * W_CYC_F; // charge cycles factor, age/usage
		cell[z].weight -= (float) hist[z].ah * W_AH_F; // pure Ah factor
		cell[z].weight -= (float) ((hist[z].ah * hist[z].esr) * W_IR_F); // internal resistance factor
		cell[z].weight -= (float) hist[z].udod * W_DOD_F; // user depth of discharge factor

		if (hist[z].udod > 100)
			cell[z].weight -= (INVPOINTS + INVPOINTS); // stop high discharge

		if (cell[z].id == 'S')
			cell[z].weight += SMALLCOMP; // Small Gell Cell  comp factor
		if (cell[z].id == 'M')
			cell[z].weight += MIDCOMP; // Small AGM Cell  comp factor
		if (z == B1) cell[z].weight -= PRIPOINTS; // points off  for primary battery
		if (z == B2) {
			if (B_GANGED || (DIPSW3 == HIGH)) cell[z].weight = MAXWEIGHT;
		}

		if (cell[z].weight > MAXWEIGHT)
			cell[z].weight = MAXWEIGHT; // limit values
		if (cell[z].weight < MINWEIGHT)
			cell[z].weight = MINWEIGHT; // limit values

		if (cell[z].online == TRUE) {
			if (R.primarypower[z] < INV_VOLT_LOW) cell[z].weight = LOWPOINTS;
			cell[z].weight -= INVPOINTS; // points off  for inverter battery
			if ((R.current > INV_LOADED) &&(CCS.boc != CCS.boi)) { // at large loads jump to the inverter battery
				cell[CCS.boi].weight = MINWEIGHT;
				cell[CCS.boi].critical = TRUE;
				CCS.alert = TRUE;
				cell[B0B].weight = MAXWEIGHT;
				cell[B0B].critical = FALSE;
				CCS.bn = CCS.boi;
			}
			if (cell[z].weight > MAXWEIGHT) cell[z].weight = MAXWEIGHT; // limit value
			if (cell[z].weight < MINWEIGHT) cell[z].weight = MINWEIGHT; // limit values
			if ((cell[z].weight < WCHARGER) && P.SYSTEM_STABLE) {
				if ((CHARGERL) == R_ON && !C_MSG_STOP) {
					term_time();
					putrs2USART(charger1); // alert of relay went from off to on
					C_MSG_STOP = TRUE;
					cell[z].critical = TRUE;
					CCS.boc = z;
				}
				if (CHARGERL == R_OFF)
					C_MSG_STOP = FALSE;
				if (DIPSW4 == HIGH) {
					divert_power(OFF, YES, 0);
					if (R.currentin < CHARGER_MIN) {
						charger_power(ON, NO); // CHARGERL = R_ON; // if the power to the inverter gets low, turn on the charger.
						PVLOAD = R_OFF;
						if (!C_MSG_STOP) {
							alarm_buffer[almctr].bn = z;
							alarm_buffer[almctr++].alm_num = NULL0;
							alarm_codes.alm_flag = TRUE;
						}
					}
				}
				check_alarm(CCS.boi, " pick_batt1 "); // send alarm codes to terminal if alm_flag is set
			}
		}
		if (z <= HISTBATTNUM) {
			s_crit(HL);
			if (((R.primarypower[z] < ALERTLOW) || (hist[z].bsoc < BSOCLOW)) || ((CCS.bn == z) && (CCS.alert))) {
				if (cell[z].weight > MAXWEIGHT)
					cell[z].weight = MAXWEIGHT; // limit value
				if (cell[z].weight < MINWEIGHT)
					cell[z].weight = MINWEIGHT; // limit values
				CCS.bn = z; // set to battery we wish to possibly charge next
				if ((CCS.boc != CCS.bn) && (cell[CCS.boc].weight > (cell[CCS.bn].weight + PLUSWEIGHT)) && (cell[CCS.bn].weight < LOWPOINTS)) {
					if (B_GANGED && (CCS.bn == B2)) { // stop bogus B2 alarms during ganged operation
						CCS.bn = B1; // force to only B1 during ganged
					} else {
						CCS.alert = TRUE; // force system to recheck battery status if in charge routine
						if (alert_pick == 0)
							alert_pick = CCS.bn; // keep battery ID LOCKED for alert until alert is cleared
						if ((R.inputvoltage < ALERTCHRG) && (DIPSW4 == HIGH)) {
							divert_power(OFF, YES, 0);
							if (R.currentin < CHARGER_MIN) {
								charger_power(ON, NO); // CHARGERL = R_ON; // only if solar power is low
								PVLOAD = R_OFF;
								alarm_buffer[almctr].bn = z;
								alarm_buffer[almctr++].alm_num = NULL0;
								alarm_codes.alm_flag = TRUE;
								check_alarm(CCS.boi, " pick_batt2 "); // send alarm codes to terminal if alm_flag is set
							}
						}
					}
				}
			}
			e_crit();
		}
		if (cell[z].dead) {
			alarm_buffer[almctr].bn = z;
			alarm_buffer[almctr++].alm_num = 9;
			alarm_codes.alm_flag = TRUE;
			check_alarm(z, " pick_batt0 "); // possible dead battery
			battalarm(0, z, 0);
			if (dead_times < 8)
				cell[z].weight = DEADWEIGHT; // try pick the bad battery for charging
			else
				cell[z].weight = MAXWEIGHT;
		}

		s_crit(HL);
		if (cell[z].weight < weight) {
			pick = z; // select battery from factors
			weight = cell[z].weight; // set for next cell to compare
		}
		e_crit();

		if ((pick == B2) && B_GANGED) {
			CCS.bn = B1;
			pick = B1;
			weight = cell[B1].weight; // clone B1
		}

		if (choice == battnum + 1) {
			if (z == 1) {
				term_time();
				sprintf(bootstr2, " Pick Battery:");
				puts2USART(bootstr2);
			}
			sprintf(bootstr2, " Bat #%u, P%i, W%li, Cell W%li:", z, pick, (int32_t) weight, (int32_t) cell[z].weight); // display weight factors
			puts2USART(bootstr2);
		}
	}

	if (cell[B1].online)
		boi = B1;
	if (cell[B2].online)
		boi = B2;
	if (cell[boi].online && ((!cell[boi].cconline) || (!DIVERSION))) { // update real battery voltage if loaded and not charging
		cell[boi].voltage = R.primarypower[boi];
	}

	s_crit(HL);
	/* try to stop extra alerts with a delay timer */
	if (CCS.alert || (alert_clock != 0)) {
		if (alert_clock == 0)
			alert_clock = V.timerint_count; // start the alert timer
		if (V.timerint_count - alert_clock > ALERT_TIME) { // alert timer done
			alert_clock = 0; // use normal picks again
		} else {
			pick = alert_pick; // LOCK pick and bn
			CCS.bn = pick;
			if (choice == battnum + 1) {
				sprintf(bootstr2, " \x1b[7mALERT\x1b[0m ", pick); // display lowest weight factor
				puts2USART(bootstr2);
			}
		}
	} else {
		alert_pick = 0; // UNLOCK the alert battery
	}
	CCS.pick = pick;
	e_crit();

	if (R.thermo_batt < PV_TEMP_VMP) {
		hist[boi].pv_eff = (int32_t) ((R.currentin * R.inputvoltage) * 100 / PVP_MAX);
		hist[boi].tot_eff = (int32_t) ((C.currentload) * R.primarypower[boi]) * 100 / PVP_MAX;
	} else {
		hist[boi].pv_eff = (int32_t) ((R.currentin * R.inputvoltage) * 100 / PVP_MAX_TEMP);
		hist[boi].tot_eff = (int32_t) ((C.currentload) * R.primarypower[boi]) * 100 / PVP_MAX_TEMP;
	}

	sprintf(bootstr2, "P B%i,W%li, SD%lu        ", pick, (int32_t) cell[pick].weight, SDC0.sdpos); // display lowest weight factor
	LCD_VC_puts(VC1, DS0, YES);
	sprintf(bootstr2, "PVE %li, INVE %li            ", (int32_t) hist[boi].pv_eff, (int32_t) hist[boi].tot_eff); // display weight factors
	LCD_VC_puts(VC1, DS1, YES);
	voltfpi(hist[B1].ahop, f1); // display pf amps
	voltfpi(hist[B1].ahi, f2);
	voltfpi(hist[B2].ahop, f3); // display pf amps
	voltfpi(hist[B2].ahi, f4);
	sprintf(bootstr2, "%s,%s %s,%s           ", f1, f2, f3, f4);
	LCD_VC_puts(VC1, DS2, YES);
	voltfpi((int32_t) SDC0.harvest.energy, f1);
	voltfpi((int32_t) SDC0.harvest.e_total + SDC0.harvest.energy, f2); // running total
	voltfpi((int32_t) SDC0.harvest.prev_energy, f3);
	sprintf(bootstr2, "PWh %s,%s,%s                       ", f1, f3, f2); // input power history
	LCD_VC_puts(VC2, DS0, YES);
	voltfpi((int32_t) SDC0.harvest.usage, f1);
	voltfpi((int32_t) SDC0.harvest.u_total + SDC0.harvest.usage, f2); // running total
	voltfpi((int32_t) SDC0.harvest.prev_usage, f3);
	sprintf(bootstr2, "IWh %s,%s,%s                       ", f1, f3, f2); // output power history
	LCD_VC_puts(VC2, DS1, YES);
	sprintf(bootstr2, "B1 %u %iA %iA,%i,%i                       ", hist[B1].bsoc, hist[B1].h[1] / 10, hist[B1].h[2] / 10, hist[B1].h[4], hist[B1].h[5]); // battery 1 history
	LCD_VC_puts(VC2, DS2, YES);
	if (!B_GANGED) {
		sprintf(bootstr2, "B2 %u %iA %iA,%i,%i                       ", hist[B2].bsoc, hist[B2].h[1] / 10, hist[B2].h[2] / 10, hist[B2].h[4], hist[B2].h[5]); // battery 2 history
	} else {
		sprintf(bootstr2, "B2&B1 are GANGED                       "); // battery 2 history
		if ((pick == B2) && (CCS.boi == B1)) {
			CCS.bn = B1;
			pick = B1;
		}
	}
	LCD_VC_puts(VC2, DS3, YES);

	if (choice == battnum + 1) {
		sprintf(bootstr2, " : Picked %i\r\n", pick); // display lowest weight factor
		puts2USART(bootstr2);
	}

	check_alarm(pick, " pick_batt4 "); // send alarm codes to terminal if alm_flag is set

	ahfp(C.currentload, f3);

	// the set of conditions to start diverting power
	B.d_code = 0;
	if (R.inputvoltage > SOLARUP)
		B.d_code = 1;
	if (B.r_soc[boi] >= DSOC_L)
		B.d_code += 2;
	if (R.primarypower[boi] > DVOLTAGE)
		B.d_code += 4;
	if (B.diversion <= PW_DIVERSION)
		B.d_code += 8;

	if (B.d_code == 15) {
		D_OFF = LOW;
		sprintf(bootstr2, "Inv %sA, %u CCLED, D        ", f3, ccled_flag.ticks); // display weight factors
		LCD_VC_puts(VC1, DS3, YES);

		if ((D_ON++ > BATTCHECK) && ((B.r_soc[boi] >= DSOC_H))) {
			if (DIPSW7 == LOW) { // if set divert power to external load
				if (CHARGERL == R_OFF) divert_power(ON, NO, B.d_code); // Switch on power to extra loads but not when charging (waste)
			} else {
				divert_power(OFF, YES, B.d_code);
			}
			D_ON = LOW;
		}
	} else {
		D_ON = LOW;
		sprintf(bootstr2, "Inv %sA, %u CCLED, no D         ", f3, ccled_flag.ticks); // display weight factors
		LCD_VC_puts(VC1, DS3, YES);

		if (D_OFF++ > 30 || (R.primarypower[boi] < DVOLTAGE)) { // turn off quickly at low voltage
			divert_power(OFF, (R.primarypower[boi] < DVOLTAGE), B.d_code); // Turn off extra loads
			D_OFF = LOW;
		}
	}

	return pick; // battery to charge
}

void noload_soc(void) // create a SOC factor for just voltage on startup and calc a "real" value while running
{
	static float rate = 0.0, usage = 0.0, result = 0.0, soc = 0.0, r_soc = 0.0;
	static uint8_t z;
	static uint32_t voltage = 0;

	C.temp_drate = (int16_t) ((float) (R.thermo_batt - Temp_ZERO) * Temp_ADJ_FL); // Make a AH temp comp factor from the value of Temp_ZERO (in tenths of C)
	if (C.temp_drate > 2500)
		C.temp_drate = NULL0;
	if (C.temp_drate < -2500)
		C.temp_drate = NULL0;
	for (z = 1; z <= battnum; z++) {
		C.t_comp = (1000.0 + (float) C.temp_drate) / 1000.0; // loss/gain factor off 1.0 for 20C
		hist[z].rate = (uint16_t) (((float) hist[z].ah * DF) * C.t_comp); // derate battery by (Discharge Floor/Temp) factors
		if ((P.STATIC_SOC || (z > HISTBATTNUM))) { // only static voltage SOC update if real state not known for cells 1-2
			voltage = cell[z].voltage;
			if (z > HISTBATTNUM) {
				voltage += BFACTOR_DIODE; // comp for diode drops
			}

			Volts_to_SOC(voltage, z); // hist[z].bsoc set here

			//FIXME adjust the static SOC from  ESR parameters
			//	    hist[z].bsoc = hist[z].bsoc - (hist[z].esr - hist[z].h[10]); // use ESR history to bring down the SOC if they differ

			if (z <= HISTBATTNUM) { // only once for cells 1-2
				soc = (float) hist[z].bsoc; // load soc
				soc = soc / 100.0; // make it a fraction
				rate = (float) hist[z].rate; // comp'd battery cap in 1.0A unita
				usage = (rate - (rate * soc)) * 100.0; // convert to 1.0A units
				hist[z].ahi = 0;
				hist[z].ahir = 0;
				hist[z].aho = (int32_t) (usage * SS_RATE); // approx a usage from static voltage SOC, mAh
				if (hist[z].aho > ((int32_t) hist[z].rate * (int32_t) 1000))
					hist[z].aho = (int32_t) hist[z].rate * (int32_t) 1000; // mAh
				if (hist[z].aho < 0)
					hist[z].aho = 0;
				hist[z].kwo = (hist[z].aho * KW_VOLTS);
				hist[z].ahop = hist[z].aho; // set peuket to real
				if (P.STATIC_SOC) {
					ahfp(-(hist[z].ahop / 100), f3);
					sprintf(bootstr2, "B%i, Static Ah %s    ", z, f3); // static soc 			// display pf Ah usage
					LCD_VC_puts(VC0, z + 1, YES); // display on lines 2&3 for batteries 1&2
					wdttime(BATRUNF * 2);
				}
				result = ((rate + (usage / 10.0)) / rate) * 10.0; //FIXME needs a sanity check, compute SOC from usage rates
				if (result <= 0.0)
					result = 0.0; // don't go less than zero

				r_soc = (float) Get_RestSOC(z, P.STATIC_SOC, CLEAR_BLEND);
				hist[z].bsoc = (uint16_t) ((result * BVSOC_RATIO_C)+(r_soc * BVSOC_RATIO_V)); // Blend SOC methods
				soc_method[z] = 'S';
				if (P.STATIC_SOC) {
					term_time();
					sprintf(bootstr2, " Static Battery #%i V%li, V%li: Raw mAHO %li BSOC %i Ah Rate %i .\r\n", z, cell[z].noload, cell[z].voltage, hist[z].aho, hist[z].bsoc, hist[z].rate);
					puts2USART(bootstr2);
				}
			}
		} else { // code for calculated SOC of derated battery
			rate = (float) (hist[z].rate - hist[z].drate); // derated battery cap in 1.0A unita
			if (rate < 1.0)
				rate = 1.0;
			usage = (float) hist[z].h[0]; // usage/gain in 0.1A units/ USE Peukert adjusted amps
			result = ((rate + (usage / 10.0)) / rate) * 100.0; //FIXME needs a sanity check, compute SOC from usage rates
			if (result <= 0.0)
				result = 0.0; // don't go less than zero
			B.r_soc[z] = (uint8_t) result; // Ah counting results
			if (B.r_soc[z] > 101)
				B.r_soc[z] = hist[z].bsoc; //FIXME a sanity check
			if ((z != CCS.boi) && (z != CCS.boc) && (z <= HISTBATTNUM) && (R.primarypower[z] < SOC_VCOMP) && (hist[z].bsoc > BVSOC_MINC)) { // use rest voltage when possible
				Get_RestSOC(z, P.STATIC_SOC, DO_BLEND); // use rest voltage table for SOC, sets hist[z].bsoc in Get_RestSOC
				//hist[z].bsoc = hist[z].bsoc - (hist[z].esr - hist[z].h[10]); // use ESR history to bring down the SOC if they differ
				soc = (float) hist[z].bsoc; // load soc
				soc = soc / 100.0; // make it a fraction
				rate = (float) hist[z].rate; // comp'd battery cap in 1.0A unita
				usage = (rate - (rate * soc)) * 100.0; // convert to 1.0A units
				hist[z].aho = hist[z].ahi + (int32_t) (usage * SS_RATE); // approx a usage from static voltage SOC, mAh
				if (hist[z].aho > ((int32_t) hist[z].rate * (int32_t) 1000)) hist[z].aho = (int32_t) hist[z].rate * (int32_t) 1000; // convert to mAh units
				if (hist[z].aho < 0) hist[z].aho = hist[z].ahi;
				hist[z].kwo = (hist[z].aho * 120l);
				hist[z].ahop = hist[z].aho; // set peuket to real
				soc_method[z] = 'R';
			} else { //FIXME need to recal amp usage values
				r_soc = (float) Get_RestSOC(z, P.STATIC_SOC, MILD_BLEND);
				if (z != CCS.boc) {
					hist[z].bsoc = (uint16_t) ((result * BVSOC_RATIO_C)+(r_soc * BVSOC_RATIO_V)); // Blend SOC methods
					soc_method[z] = 'M';
				} else {
					if ((r_soc < result) && ((result - r_soc) > BVSOC_SKEW)) { // check for SOC method errors
						hist[z].bsoc = (uint16_t) ((result * BVSOC_RATIO_C)+(r_soc * BVSOC_RATIO_V)); // Blend SOC methods
						soc_method[z] = 'F';
					} else {
						if (cell[z].current <= BVSOC_CURRENT) {
							hist[z].bsoc = (uint16_t) result; // use only current counting for SOC when close to and charging
							soc_method[z] = 'C';
						} else { // blend when load exceeds PV current setpoint while charging.
							hist[z].bsoc = (uint16_t) ((result * BVSOC_RATIO_C)+(r_soc * BVSOC_RATIO_V)); // Blend SOC methods
							soc_method[z] = 'L';
						}
					}
				}
				if (hist[z].bsoc < SOC_FRESH) cell[z].fresh = FALSE;
				if (hist[z].bsoc > SOC_FULL) {
					hist[z].bsoc = SOC_FULL;
					hist[z].aho = hist[z].ahi; // equalize
				}
			}
		}
		if (z == B2) {
			if (B_GANGED) {
				hist[z].bsoc = hist[B1].bsoc; // sync SOC
				hist[z].aho = 0;
			}
		}
		if (hist[z].bsoc > SOC_FULL) {
			hist[z].bsoc = SOC_FULL;
			hist[z].udod = 0;
			hist[z].aho = hist[z].ahi; // equalize
		}
		if (z > HISTBATTNUM) {
			hist[z].udod = (uint16_t) ((float) (100 - hist[z].bsoc) * CONT_DOD);
		} else {
			hist[z].udod = (uint16_t) ((float) (100 - hist[z].bsoc) * USER_DOD);
		}
	}
	P.STATIC_SOC = FALSE; // use SOC routine next
}

void Cycle_Update(uint16_t t_soc, uint8_t bn)
{
	if (t_soc < SOC_DF)
		hist[bn].h[5]++; // full discharge cycles
	if (hist[bn].bsoc >= SOC_FF) {
		hist[bn].h[4]++; // inc full charge hist data
		B.equal++;
	}

	if ((bn == B1) && B_GANGED) {
		hist[B2].h[4]++; // inc full charge hist data
		hist[B2].h[5]++; // full discharge cycles
	}
}

uint8_t ChargeBatt(uint8_t bn, uint8_t FCHECK, uint8_t TIMED)
{
	static uint32_t BATCHARGE = 3600, timetemp = 0, newdate = 0, cycles_tmp = 0;
	static int32_t voltage_slope = 0;
	static int16_t CCEFF_tmp = 0;
	static uint8_t ccs_t = 0, use_dual_load = DUALLOAD, z = 0, CC_DONE = FALSE, dual_cv_slow = 16;
	static uint16_t t_esr = 0, load_i1 = 0, load_i2 = 0, t_soc = 0;
	uint8_t ccreset, cv_set = FALSE;

	CC_DONE = FALSE; // reset the done flag
	esr_delta = 1957.0; // set the old data flag value
	if (!FCHECK) { // We are charging
		term_time();
		sprintf(bootstr2, " Battery %i ", bn);
		puts2USART(bootstr2);
		putrs2USART(chrgcode8);
		pv_pwm_shutdown(); // kill power to PV PWM system
		ccreset = CC_RESET_MAX; // max number of C40 resets to increase absorp time
		smooth[LP_CCEFF] = 100.0; // preset value pv to cc eff factor
		CCEFF = (int16_t) lp_filter(100.0, LP_CCEFF, FALSE); // update lp_filterfilter
		// reset model data for battery
		if ((bn <= HISTBATTNUM) && (model_update)) {
			for (z = 0; z <= 3; z++) {
				bmt[bn - 1].soc[z].flags = NULL0;
			}
		}
	} else {
		if (hist[bn].btest != 0) { // btest count has been updated
			s_crit(HL); // must e_crit() before return in IF statement
			timetemp = V.timerint_count - hist[bn].btest;
			if (V.timerint_count < (hist[bn].btest + BTEST_DELAY)) { // check for short time between rechecks
				e_crit();
				term_time();
				sprintf(bootstr2, " Battery test skipped, last checked %lu seconds ago.\r\n", timetemp);
				puts2USART(bootstr2);
				return NULL0; // just return quickly
			} // ok for recheck so update the time
			e_crit();
		}
		s_crit(HL); // reduce crit
		hist[bn].btest = V.timerint_count; // load timer count at start of charging time
		e_crit();
	}

	if ((bn < 1) || (bn > battnum)) {
		sprintf(bootstr2, "\r\n ******1 ChargeBatt bn out of range [1-2..4] %u BATTNUM=%u, CCS.bn %u, CCS.boc is %u ****\r\n", bn, battnum, CCS.bn, CCS.boc);
		puts2USART(bootstr2);
		return NULL0;
	}
	idle_loop();
	ResetC40(bn, FALSE, 0); // power cycle the C40 to make it start a new charge cycle

	if (!P.PRIPOWEROK) { // skip if we are in primary battery override charging.
		strncpypgm2ram(ds[DS0 + VC0].b, "OVERRIDE CHRG #1    ", LCD_W);
		LCD_VC_puts(dsi, DS0, NO);
		return ERR1;
	}

	ChargeRelayOn(bn, TRUE); // connect the battery charge wire to the load buss
	wdttime(BATRUNF);

	s_crit(HL);
	newdate = V.timerint_count;
	e_crit();
	if (((bn <= HISTBATTNUM) && (!(B_GANGED && (bn == B2)))) && (((newdate - cell[bn].date) > BATTREST) || (cell[bn].date == NULL0))) { // update ESR only at start or after the battery has rested after charging
		sprintf(bootstr2, "Test B%i %uAh,%c               ", bn, hist[bn].ah, cell[bn].id);
		LCD_VC_puts(VC0, DS0, YES);
		term_time();
		putrs2USART(chrgcode10);
		/*              battery test routine    */
		SOLAROFF = R_ON; // PV off before C40
		wdttime(BATRUNF);
		CCOUTOPENSW = R_ON; // charge voltage relay/off
		wdttime(BATRUNF);
		ADC_read(); // read unloaded battery voltage from charge line.
		if (bn <= HISTBATTNUM) {
			cell[bn].noload = R.primarypower[bn]; // set unloaded battery voltage
		} else {
			cell[bn].noload = R.ccvoltage; // set unloaded battery voltage
		}
		if (bn > HISTBATTNUM & cell[bn].id == 'S')
			cell[bn].noload += GELL_R_COMP;
		if (bn > HISTBATTNUM & cell[bn].id == 'M')
			cell[bn].noload += AGM_R_COMP;
		BATLOAD = R_ON; // battery load relay/on
		wdttime(BATTEST); // drain the battery
		if (!P.SYSTEM_STABLE) wdttime(BATTEST); // drain the battery MORE
		ADC_read(); // read loaded battery voltage from charge line.
		if (bn <= HISTBATTNUM) {
			cell[bn].voltage = R.primarypower[bn]; // set first loaded battery voltage
		} else {
			cell[bn].voltage = R.ccvoltage; // set first loaded battery voltage
		}
		if (bn > HISTBATTNUM & cell[bn].id == 'S')
			cell[bn].voltage += GELL_R_COMP;
		if (bn > HISTBATTNUM & cell[bn].id == 'M')
			cell[bn].voltage += AGM_R_COMP;

		hist[bn].esr = NULL0;
		if (use_dual_load) {
			load_i1 = cell[bn].voltage / BLOAD1; // find current 0.1 A units
			if (cell[bn].noload > cell[bn].voltage) {
				t_esr = ((cell[bn].noload - cell[bn].voltage)*100) / load_i1; // find resistance causing voltage drop (sorta)
			} else {
				t_esr = 1962;
			}
			if ((t_esr > 1000) || (t_esr <= 0)) { // check for sane values
				t_esr = 999;
			}
			hist[bn].esrp = t_esr;
			ADC_read(); // read  battery voltages.
			term_time();
			sprintf(bootstr2, " Battery%i LV%limV, BV%limV, CV%limV, I1 %i0mA ESR-PRE R%i.\r\n", bn, cell[bn].noload, R.primarypower[bn], cell[bn].voltage, load_i1, hist[bn].esrp);
			puts2USART(bootstr2);
			BATLOAD_HI = R_ON; // battery load relay/on
			wdttime(BATTEST_SLOPE); // drain the battery
			ADC_read(); // read  battery voltages.
			if (bn <= HISTBATTNUM) {
				voltage_slope = R.primarypower[bn]; // set unloaded battery voltage
			} else {
				voltage_slope = R.ccvoltage; // set unloaded battery voltage
			}
			term_time();
			sprintf(bootstr2, " Battery%i Slope Voltage %limV.\r\n", bn, voltage_slope);
			puts2USART(bootstr2);
			wdttime(BATTEST); // drain the battery
			if (!P.SYSTEM_STABLE)
				wdttime(BATTEST); // drain the battery MORE
			ADC_read(); // read loaded battery voltage from charge line.
			if (bn <= HISTBATTNUM) {
				load_i2 = R.primarypower[bn] / ((BLOAD1 * BLOAD2) / (BLOAD1 + BLOAD2)); // find current 0.1 A units
				hist[bn].esr = ((cell[bn].voltage - R.primarypower[bn])*100) / (load_i2 - load_i1); // find resistance causing voltage drop (sorta)
			} else {
				load_i2 = R.ccvoltage / ((BLOAD1 * BLOAD2) / (BLOAD1 + BLOAD2)); // find current 0.1 A units
				hist[bn].esr = ((cell[bn].voltage - R.ccvoltage)*100) / (load_i2 - load_i1); // find resistance causing voltage drop (sorta)
			}
			if ((hist[bn].esr > 1000) || (hist[bn].esr <= 0)) { // check for sane values
				hist[bn].esr = 1957;
			}
			if (hist[bn].esr < hist[bn].h[10])
				hist[bn].h[10] = hist[bn].esr; // check for lowest esr
			esr_delta = ((float) ((int32_t) t_esr - (int32_t) hist[bn].esr)) / ((float) ((int32_t) t_esr + (int32_t) hist[bn].esr)); // the change in esr with resistance
			ADC_read(); // read  battery voltages.
			term_time();
			sprintf(bootstr2, " Battery%i LV%limV, BV%limV, CV%limV, SV%limV, I1 %i0mA, I2 %i0mA ESR R%i ESR-DELTA %li.\r\n", bn, cell[bn].voltage, R.primarypower[bn], R.ccvoltage, voltage_slope - R.primarypower[bn], load_i1, load_i2, hist[bn].esr, (int32_t) (esr_delta * 1000.0));
			puts2USART(bootstr2);
		} else {
			load_i1 = cell[bn].voltage / BLOAD1; // find current 0.1 A units
			if (cell[bn].noload > cell[bn].voltage) {
				hist[bn].esr = ((cell[bn].noload - cell[bn].voltage)*100) / load_i1; // find resistance causing voltage drop (sorta)
			} else {
				hist[bn].esr = 1962;
			}
			if ((hist[bn].esr > 1000) || (hist[bn].esr <= 0)) { // check for sane values
				hist[bn].esr = 999;
			}
			if (hist[bn].esr < hist[bn].h[10])
				hist[bn].h[10] = hist[bn].esr; // check for lowest esr
			term_time();
			sprintf(bootstr2, " Battery%i V%limV, V%limV ESR  R%i.\r\n", bn, cell[bn].noload, cell[bn].voltage, hist[bn].esr);
			puts2USART(bootstr2);
		}
	} else {
		if (bn > HISTBATTNUM) { // fill in for gell cells
			ADC_read(); // read unloaded battery voltage from charge line.
			if (cell[bn].id == 'S') {
				cell[bn].noload = R.ccvoltage += GELL_ESR_COMP; // set unloaded battery voltage
			} else {
				cell[bn].noload = R.ccvoltage += AGM_ESR_COMP; // set unloaded battery voltage
			}
			cell[bn].voltage = cell[bn].noload; // set loaded battery voltage
			hist[bn].esr = (uint16_t) ((float) 150.0 * (4600.0 / (float) (cell[bn].voltage - 8000.0))); // set static esr
			if (hist[bn].esr < hist[bn].h[10])
				hist[bn].h[10] = hist[bn].esr; // check for lowest esr
			term_time();
			sprintf(bootstr2, " Untested Battery %i V%limV, V%limV ESR  R%i.\r\n", bn, cell[bn].noload, cell[bn].voltage, hist[bn].esr);
			puts2USART(bootstr2);
		}
		term_time();
		putrs2USART(chrgcode15);
	}
	s_crit(HL);
	term_time();
	putrs2USART(chrgcode7);
	cell[bn].date = V.timerint_count; // load timer count at start of charging time

	if (!cell[bn].critical && CHARGERL == R_OFF)
		cell[bn].critical = FALSE; // reset battery flags
	cell[bn].discharged = FALSE;
	cell[bn].dead = FALSE;

	if (B_GANGED && (bn == B2)) {
		cell[B2] = cell[B1]; // clone the cell data
	}

	if (cell[bn].voltage < BATTCRIT)
		cell[bn].critical = TRUE; // set battery flags
	if (cell[bn].voltage < BATTFLAT)
		cell[bn].discharged = TRUE;
	if (cell[bn].voltage < BATTLOW)
		cell[bn].dead = TRUE;
	if ((cell[bn].noload > cell[bn].voltage) && (cell[bn].noload - cell[bn].voltage) > BATTDROP) {
		cell[bn].dead = TRUE; // max voltage drop
		dead_times++;
	}

	if (cell[bn].voltage < hist[bn].h[7]) { // check current voltage is lower
		if (cell[bn].voltage > BATTLOW) { // check greater than dead
			hist[bn].h[7] = cell[bn].voltage; // update batt low  volts hist
		}
	}
	if (cell[bn].voltage > hist[bn].h[8]) { // check current voltage is greater
		if (cell[bn].voltage < BATTHIGH) { // check less than high
			hist[bn].h[8] = cell[bn].voltage; // update batt high volts hist
		}
	}
	e_crit();

	BATLOAD = R_OFF; // battery load relay/off
	BATLOAD_HI = R_OFF;
	wdttime(BATRUNF);
	CCOUTOPENSW = R_OFF; // charge voltage relay/on
	wdttime(BATRUNF);
	SOLAROFF = R_OFF; // PV back on
	wdttime(BATRUNF);
	/*              end battery test        */

	if (cell[bn].id == 'L')
		BATCHARGE = BATCHARGE_L; // set timer per battery type
	if (cell[bn].id == 'M')
		BATCHARGE = BATCHARGE_M;
	if (cell[bn].id == 'S')
		BATCHARGE = BATCHARGE_S;

	s_crit(HL);
	CCS.boc = bn; // [1..4]
	e_crit();
	if ((bn < 1) || (bn > battnum)) {
		sprintf(bootstr2, "\r\n ******2 ChargeBatt bn out of range [1-2..4] %u, CCS.bn %u, CCS.boc is %u ****\r\n", bn, CCS.bn, CCS.boc);
		puts2USART(bootstr2);
		return NULL0;
	}

	// save starting values for cef_calc later
	s_crit(HL);
	B.start_ahi = hist[bn].ahir; // The real input current (no cef) to the battery
	B.absorp_ahi = 0; // reset value of AHI during the absorption phase of charge
	B.absorp_time = 0; // reset absorption timer
	absorp_current = 0; // zero out end-amps data
	end_amps = (int32_t) ((float) hist[bn].rate * END_RATIO); // make a End-Amps from the adjusted battery rate
	if (cell[bn].id == 'M')
		end_amps = (int32_t) ((float) hist[bn].rate * END_RATIO_MED);
	if (cell[bn].id == 'S')
		end_amps = (int32_t) ((float) hist[bn].rate * END_RATIO_SM);
	B.start_aho = hist[bn].ahop; // use the adjusted load current
	B.start_ahu = hist[bn].h[0]; // the current balance of current in/out for the battery ,h[0] is in tenth amp units
	cycles_tmp = cell[bn].cycles;
	e_crit();

	if (!FCHECK) {
		t_soc = hist[bn].bsoc;
		hist[bn].h[11]++; // charge cycles
		if (B_GANGED && (bn == B1))
			hist[B2].h[11]++; // charge cycles
		term_time();
		putrs2USART(chrgcode12);
	}
	smooth[LP_PVVOLTAGE] = (float) R.inputvoltage; // preload filter with current voltage

	do { // this is the main charge loop
		idle_loop();
		s_crit(HL);
		timetemp = V.timerint_count;
		e_crit();
		if (P.POWER_UNSTABLE) {
			term_time();
			putrs2USART(chrgcode14);
			return 3; // exit from normal charge routine
		}

		if (!P.PRIPOWEROK) {
			term_time();
			putrs2USART(chrgcode6);
			return 2; // in override mode exit from normal charge routine
		}
		mkbsstring(); // read voltages from solar cells

		cell[bn].valid = cell[B0].valid;
		/*                      set cell[bn].voltage in battery test routine above      */
		cell[bn].charge = R.ccvoltage;

		if (FCHECK) {
			ChargeRelayOff(bn, FALSE);
			wdttime(BATRUNF);

			sprintf(bootstr2, "Tested B%i %uAh,%c                  ", bn,
				hist[bn].ah, cell[bn].id);
			LCD_VC_puts(VC0, DS0, YES);

			voltfp(cell[bn].noload, f1);
			voltfp(cell[bn].voltage, f2);
			sprintf(bootstr2, "B%i,%sV,%sV                 ", bn, f1, f2);
			LCD_VC_puts(VC0, DS1, YES);

			wdttime(BATRUNF);
			ALARMOUT = R_OFF;
			if (cell[bn].critical) {
				term_time();
				putrs2USART(chrgcode16);
			}
			term_time();
			putrs2USART(chrgcode11);
			return NULL0; // just checking so return
		}
		pick_batt(NO, NULL0);
		update_hist();
		update_cef(bn, FALSE);
		//	t_soc = hist[bn].bsoc;

		if (((cell[bn].voltage > BATTCRIT) && (!cell[bn].critical)) && !TIMED) { // very low voltage will force a full charge by batcount loop
			chrg_v = (uint32_t) lp_filter((float) R.ccvoltage, LP_CCVOLTAGE, FALSE); // use digital filter

			if (chrg_v > BATTHIGH) { // check for charge controller over-voltage
				ALARMOUT = R_ON;
				Cycle_Update(t_soc, bn);
				term_time();
				putrs2USART(chrgcode0);
				break;
			}

			chrg_v = (uint32_t) lp_filter((float) R.inputvoltage, LP_PVVOLTAGE, TRUE); // use digital filter
			if (chrg_v < SOLARLOW) { // input is too low to charge (normal)
				Cycle_Update(t_soc, bn);
				term_time();
				putrs2USART(" LOW VOLTS loop \r\n");
				term_time();
				putrs2USART(chrgcode1);
				break;
			}
		}

		chrg_v = (uint32_t) lp_filter((float) R.inputvoltage, LP_PVVOLTAGE, TRUE); // use digital filter
		if (SIM_MODE) chrg_v = R.inputvoltage;

		if (cell[bn].critical) {
			if (chrg_v < SOLARLOW) { // input is too low to charge (critical)
				Cycle_Update(t_soc, bn);
				term_time();
				putrs2USART(chrgcode4);
				break;
			}
		}

		if (P.FORCEOUT) { // Received FOURCEOUT from host, so exit
			P.FORCEOUT = FALSE;
			Cycle_Update(t_soc, bn);
			term_time();
			putrs2USART(chrgcode2);
			// init store model data for battery
			if ((bn <= HISTBATTNUM) && (model_update)) {
				for (z = 0; z <= 3; z++) {
					bmt[bn - 1].soc[z].flags = NULL0;
					bmt[bn - 1].soc[z].flags |= BMT_FLAG_7;
				}
			}
			break;
		}
		if (chrg_v < SOLARLOW) { // input is too low to charge (normal)
			Cycle_Update(t_soc, bn);
			term_time();
			putrs2USART(" MAIN loop \r\n");
			term_time();
			putrs2USART(chrgcode1);
			break;
		}

		if (B_GANGED && (chrg_v < GANGEDHIGH)) { // allow B2 to power the controller unless the voltage is too high
			if ((bn <= HISTBATTNUM) && (BAT2 == R_ON)) {
				BAT2 = R_OFF; // battery #2 relay/off, supply controller V
				term_time();
				putrs2USART(" Battery 2 connected to controller voltage buss\r\n");
			}
		} else {
			if (B_GANGED && (chrg_v > (GANGEDHYST)) && !cell[B3].critical && !cell[B4].critical) {
				if ((bn <= HISTBATTNUM) && (BAT2 == R_OFF)) {
					BAT2 = R_ON; // battery #2 relay/on, no controller V
					term_time();
					putrs2USART(" Battery 2 disconnected from controller voltage bus\r\n");
				}
			}
		}

		/*
		 * Dual controller battery charging
		 */
		if ((bn == B3) && ((chrg_v < DUAL_CV_LOW) || (R.systemvoltage < BATTCRIT))) {
			if (BAT4 == R_ON) {
				BAT4 = R_OFF; // battery #4 relay/off
				CHRG4 = R_OFF;
				term_time();
				putrs2USART(" Battery 4 disconnected from charger bus\r\n");
				cell[BAT4].cconline = FALSE;
				dual_cv_slow = 16;
			}
		} else {
			if ((bn == B3) && (chrg_v > DUAL_CV_HIGH) && (hist[bn].bsoc < DUAL_CV_BSOC)) { // try to charge both to save time
				if (!(--dual_cv_slow)) {
					dual_cv_slow = 2;
					if (BAT4 == R_OFF) {
						BAT4 = R_ON; // battery #4 relay/on
						CHRG4 = R_ON;
						cv_set = TRUE;
						term_time();
						putrs2USART(" Battery 4 connected to charger bus\r\n");
						cell[BAT4].cconline = TRUE;
					}
				}
			}
		}

		if (B_GANGED && (R.systemvoltage < BATTCRIT)) { // monitor controller batteries during ganged charging
			cell[B3].critical = TRUE; // set battery flags
			cell[B4].critical = TRUE; // set battery flags
			if ((bn <= HISTBATTNUM) && (BAT2 == R_ON)) {
				BAT2 = R_OFF; // battery #2 relay/off, supply controller V
				term_time();
				putrs2USART(" Battery 2 connected to controller voltage buss due to bus undervolt\r\n");
			}
		}
		s_crit(HL);
		ccs_t = CCS.bn;
		e_crit();
		if (CCS.alert && (bn != ccs_t)) { // Received alert from pick_batt, so exit
			CCS.alert = FALSE;
			sprintf(bootstr2, "\r\n ******3 Aborting, Charging battery %u,     Alert on battery CCS.bn %u,      CCS.boi is %u ****\r\n", bn, ccs_t, CCS.boi);
			puts2USART(bootstr2);
			sprintf(bootstr2, "\r\n ******3 Aborting  Charging weight  %lu, Alert weight %lu, Inverter weight %lu ****\r\n",
				(int32_t) cell[bn].weight, (int32_t) cell[ccs_t].weight, (int32_t) cell[CCS.boi].weight);
			puts2USART(bootstr2);
			s_crit(HL);
			CCS.bn = B0; // set to null battery
			e_crit();
			Cycle_Update(t_soc, bn);
			term_time();
			putrs2USART(runcode7);
			break;
		}

		if ((hist[bn].ahir > B.start_ahi) && !CC_DONE) {
			hist[bn].cef_calc = (float) (((float) ((float) B.start_ahu * 100.0)+(hist[bn].ahop - B.start_aho)) / (float) (CEF_DERATE * (float) (hist[bn].ahir - B.start_ahi))); // used Ah/charging Ah
			B.cef_raw = (int16_t) hist[bn].cef_calc;
			if (hist[bn].cef_calc < 0.0)
				hist[bn].cef_calc = -hist[bn].cef_calc; // make this positive
			if (hist[bn].cef_calc > CEF_OVER)
				hist[bn].cef_calc = CEF_MSOC;
			if (hist[bn].cef_calc > CEF_MAX)
				hist[bn].cef_calc = CEF_MAX;
			if (hist[bn].cef_calc < CEF_MIN)
				hist[bn].cef_calc = CEF_MIN;
			if (CCMODE == ABSORP_M)
				hist[bn].cef_calc = CEF_HSOC;
		}

		if ((CCMODE == FLOAT_M) || (CCMODE == FLOAT_W)) { // in float charge signal from C40 controller
			if (ABSL(absorp_current) <= end_amps)
				ccreset = 0; // Don't reset CC if the battery is charged at 100% by end-amp value
			if ((cell[bn].id != 'S') && (B.absorp_time < MIN_ABSORP) && ccreset) {
				term_time();
				putrs2USART(chrgcode5);
				ResetC40(bn, TRUE, CC_RESET_MAX - (--ccreset)); // one less controller reset, count up reset times
				pv_pwm_shutdown(); // kill power to PV PWM system
				if (bn == CCS.boi) { // update some factors so we can divert power earlier if possible
					hist[bn].udod = 0; // depth of discharge to 100%
					hist[bn].bsoc = 100; // state of charge
					hist[bn].ahi = 0; // reset at full charge
					hist[bn].ahir = 0;
					hist[bn].aho = 0; // reset at full charge
					hist[bn].ahop = 0;
					hist[bn].rest_rate = 0; // completely empty rest reserve bank
				}
			}

			if (!CC_DONE && (CCMODE != IDLE_M)) { // only once per charge cycle
				ClrWdt(); // reset the WDT timer
				CC_DONE = TRUE;
				PVLOAD = R_OFF;
				term_time();
				if (CCMODE == FLOAT_M)
					putrs2USART(runcode6);
				if (CCMODE == FLOAT_W)
					putrs2USART(runcode8);
				wdttime(CHRGTIME); // sound alarm for a while
				ALARMOUT = R_OFF; // turn off relay
				cell[bn].fresh = TRUE;
				cell[bn].critical = FALSE;
				cell[bn].dead = FALSE;
				cell[bn].discharged = FALSE;

				s_crit(HL);
				if ((hist[bn].bsoc >= SOC_FR)) {
					if (hist[bn].ahir > B.start_ahi) {
						hist[bn].cef_calc = (float) ((float) (((float) B.start_ahu * 100.0)+(hist[bn].ahop - B.start_aho)) / (float) (CEF_DERATE * (float) (hist[bn].ahir - B.start_ahi))); // used Ah/total charging Ah
						B.cef_raw = (int16_t) hist[bn].cef_calc;
						if (hist[bn].cef_calc < 0.0) hist[bn].cef_calc = -hist[bn].cef_calc; // make this positive
						if (hist[bn].cef_calc > CEF_OVER) hist[bn].cef_calc = CEF_MSOC;
						if (hist[bn].cef_calc > CEF_MAX) hist[bn].cef_calc = CEF_MAX;
						if (hist[bn].cef_calc < CEF_MIN) hist[bn].cef_calc = CEF_MIN;
						if (CCMODE == ABSORP_M)
							hist[bn].cef_calc = CEF_HSOC;
					}
					hist[bn].h[4]++; // inc full charge hist data
					B.equal++;
					if ((bn == B1) && B_GANGED)
						hist[B2].h[4]++; // inc full charge hist data
					if (t_soc < SOC_DF) {
						hist[bn].h[5]++; // full discharge cycles
						if ((bn == B1) && B_GANGED)
							hist[B2].h[5]++; // full discharge cycles
					}

					hist[bn].h[6] = 0; // reset Ah hist on full charge.
					hist[bn].h[0] = 0; // reset pAh hist on full charge.
					hist[bn].h[2] = 0; // reset this cycle discharge hist
					hist[bn].udod = 0; // depth of discharge to 100%
					hist[bn].bsoc = 100; // state of charge
					hist[bn].drate = 0;
					hist[bn].ahi = 0; // reset at full charge
					hist[bn].ahir = 0;
					hist[bn].aho = 0; // reset at full charge
					hist[bn].ahop = 0;
					hist[bn].cef_save = hist[bn].cef; // save new cef value
					hist[bn].rest_rate = 0; // completely empty rest reserve bank
					hist[z].rest_factor = RFACTOR; // Efficency factor of battery recovery
					// init store model data for battery
					if ((bn <= HISTBATTNUM) && (model_update)) {
						for (z = 0; z <= 3; z++) { // set data flags
							bmt[bn - 1].soc[z].flags = 0;
							bmt[bn - 1].soc[z].flags |= BMT_FLAG_7;
						}
					}

					if ((cell[B1].fresh) && (cell[B2].fresh) && (!P.CHARGEROVERRIDE)) {
						charger_power(OFF, YES); // CHARGERL = R_OFF;
						alarm_buffer[almctr].bn = bn;
						alarm_buffer[almctr++].alm_num = 2;
						alarm_codes.alm_flag = TRUE;
						check_alarm(CCS.boi, " charge1 "); // send alarm codes to terminal if alm_flag is set
					} else {
						term_time();
						putrs2USART(runcode9);
					}
				}
				e_crit();
			}
			if (CCMODE == FLOAT_M) { // exit routine
				term_time();
				putrs2USART(chrgcode3);
				divert_power(OFF, YES, 0);
				cell[bn].critical = FALSE;
				break;
			}
			if ((R.inputvoltage < SOLARLOW) && (CCMODE != IDLE_M)) { // input is too low to charge (normal)
				term_time();
				putrs2USART(" FLOAT loop \r\n");
				term_time();
				putrs2USART(chrgcode1);
				break;
			}
		}

		s_crit(HL);
		newdate = V.timerint_count;
		e_crit();

		CCM = 'B'; // default charge controller mode is Bulk
		if (CCMODE == ABSORP_M)
			CCM = 'A'; // Absorp
		if ((CCMODE == FLOAT_W) || (CCMODE == FLOAT_M))
			CCM = 'F'; // Float
		if (R.ccvoltage < SOLARLOW)
			CCM = 'O'; // Off

		if (TIMED) { // this 'TIMED' should be the default with most calls
			CCEFF_tmp = (int16_t) ((R.ccvoltage * 100l) / R.inputvoltage);
			CCEFF = (int16_t) lp_filter((float) CCEFF_tmp, LP_CCEFF, TRUE); // slow down changes
			if (CCEFF > 99) {
				CCEFF = 99;
			}
			if (CCEFF < 0) {
				CCEFF = 0;
			}
			pv_pwm_calc(0.0); // find a duty-cycle for the pwm to use the excess power
			B.charge_time_left = ((((cell[bn].date + BATCHARGE) - newdate)) + 1);
			sprintf(bootstr2, "%c E%i B%i %s left         ", CCM, (int16_t) CCEFF, bn, hms((((cell[bn].date + BATCHARGE) - newdate)) + 1));
			LCD_VC_puts(VC0, DS0, YES);
		} else {
			CCEFF = 99; // just set
			CCEFF_DIFF = 0; // just set
			voltfp(cell[bn].noload, f1);
			voltfp(cell[bn].voltage, f2);
			B.charge_time_left = (newdate - cell[bn].date);
			sprintf(bootstr2, "C B%i %sV %sV %s         ", bn, f1, f2, hms((newdate - cell[bn].date)));
			LCD_VC_puts(VC0, DS0, YES);
		}
		voltfp(R.inputvoltage, f1);
		voltfp(R.ccvoltage, f2);
		ahfp(R.currentin, f3);
		sprintf(bootstr2, "P%5s,B%5s,%sA           ", f1, f2, f3);
		LCD_VC_puts(VC0, DS1, YES);
		wdttime(BATRUNF); // reset the WDT timer
		idle_loop();
		cell[bn].cycles = cycles_tmp + (newdate - cell[bn].date); // update charge time data
	} while (timetemp < (cell[bn].date + BATCHARGE));

	if (cv_set && (BAT4 == R_ON)) {
		BAT4 = R_OFF; // battery #4 relay/off
		CHRG4 = R_OFF;
		term_time();
		putrs2USART(" Battery 4 disconnected from charger bus\r\n");
		cell[BAT4].cconline = FALSE;
	}
	hist[bn].btest = NULL0;
	pv_pwm_shutdown(); // kill power to PV PWM system
	B.charge_time_left = NULL0;
	term_time();
	putrs2USART(chrgcode9);
	ALARMOUT = R_OFF; // turn off relay
	voltfp(R.ccvoltage, f2);
	sprintf(bootstr2, "Chrg done, B%i %sV                ", bn, f2);
	LCD_VC_puts(VC0, DS0, YES);
	ChargeRelayOff(bn, TRUE);
	wdttime(BATRUNF);
	s_crit(HL);
	hist[bn].btest = NULL0; // reset battery check time to force next test
	e_crit();
	Get_RestSOC(bn, TRUE, NO_BLEND); // set the loaded SOC value
	pick_batt(NO, NULL0);
	update_hist();
	return NULL0;
}

// if you need to extend the absorption time then reset the charger
// Power cycle the C40 to make it start a new charge cycle

void ResetC40(uint8_t bn, uint8_t save_relay, uint8_t resetno)

{
	uint8_t relays;
	term_time();
	relays = LATE;
	if (save_relay) {
		sprintf(bootstr2, " Saving Relay State 0X%X on Reset #%i : ", (int16_t) relays, (int16_t) resetno);
		puts2USART(bootstr2);
		LATE = 0xFF;
		wdttime(BATRUNF);
	}

	if (cell[bn].id == 'M') {
		sprintf(bootstr2, " Resetting Charge Controller on Battery %i, Absorp Current %li00mA, End Amps %li00mA.\r\n",
			bn, ABSL(absorp_current), (int32_t) ((float) hist[bn].rate * END_RATIO_MED));
	} else {
		sprintf(bootstr2, " Resetting Charge Controller on Battery %i, Absorp Current %li00mA, End Amps %li00mA.\r\n",
			bn, ABSL(absorp_current), (int32_t) ((float) hist[bn].rate * END_RATIO));
	}
	puts2USART(bootstr2);
	SOLAROFF = R_ON; // PV off before C40
	wdttime(BATRUNF);
	CCOUTOPENSW = R_ON; // disconnect battery to reset C40
	wdttime(BATRUNF);
	CCOUTOPENSW = R_OFF; // connect battery C40 before solar
	wdttime(BATRUNF);
	if (save_relay) { // wait until the C40 controller power cycles.
		pv_pwm_shutdown(); // kill power to PV PWM system
		wdttime(BATRUN);
		wdttime(BATRUN);
	}
	SOLAROFF = R_OFF; // PV back on
	CCMODE = IDLE_M; // reset the charge mode flag
	wdttime(BATRUNF);
	wdttime(BATRUN);
	if (save_relay) {
		LATE = relays;
		wdttime(BATRUNF);
		wdttime(BATRUN);
	}
}