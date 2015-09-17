/* High and Low ISR codes, some glue routines */
#include "mbmc_vector.h"

#pragma	tmpdata	ISRHtmpdata
#pragma interrupt tick_handler   nosave=section (".tmpdata")

void tick_handler(void) // This is the high priority ISR routine
{
	static uint8_t c1, c2;
	static uint8_t ZAP = FALSE, vc_count = NULL0;
	static uint8_t worker_timer = WORKSEC;
	static uint16_t hirez_tmp0 = NULL0, hirez_tmp1 = NULL0;
	static union Timers timer;

	_asm nop _endasm // asm code to disable compiler optimizations
	V.highint_count++; // high int counter
	hirez_tmp0 = (uint16_t) TMR0L;
	hirez_tmp0 += (uint16_t) (TMR0H << SHIFT8); // load high byte in tmp counter

	if (PIR2bits.EEIF) { // EEPROM write complete flag
		V.eeprom_count++; // just keep count
		MPULED = !MPULED; //  flash led
		PIR2bits.EEIF = LOW;
	}

	if (PIE1bits.ADIE && PIR1bits.ADIF) { // ADC conversion complete flag
		V.adc_count++; // just keep count
		//           	TIMESIG=R_OFF;         							// set output bit to zero
		PIR1bits.ADIF = LOW;
	}

	if (INTCONbits.TMR0IF) { // check timer0 irq 1 second timer int handler
		//check for TMR0 overflow
		INTCONbits.TMR0IF = LOW; //clear interrupt flag
		/*	reset the profile counts */
		hirez_count[0] = hirez_count[2]; // copy high int counts into save var
		hirez_count[2] = NULL0; // zero high int counts
		hirez_count[1] = hirez_count[3]; // copy low int counts into save var
		hirez_count[3] = NULL0; // zero low int counts
		hirez_count[4] = hirez_count[5]; // copy low int counts into save var
		hirez_count[5] = NULL0; // zero low int counts

		timer.lt = TIMEROFFSET; // Copy timer value into union
		TMR0H = timer.bt[HIGH]; // Write high byte to Timer0
		TMR0L = timer.bt[LOW]; // Write low byte to Timer0

		hirez_tmp0 = (uint16_t) TMR0L; // reload the profile start var count
		hirez_tmp0 += (uint16_t) (TMR0H << SHIFT8); // load high byte in tmp counter

		P.TIMERFLAG = TRUE;
		if (fast_ticks > 10) fast_ticks = real_ticks; // measure low ints per second
		real_ticks = NULL0; // reset low int counter
		PIR2bits.TMR3IF = LOW; // clear possible timer3 int flag
		timer.lt = TIMER3REG; // Save the 16-bit value in local,  reset fast counter reg to sync
		TMR3H = timer.bt[HIGH]; // Write high byte to Timer3 High byte
		TMR3L = timer.bt[LOW]; // Write low byte to Timer3 Low byte

		XON_XOFF = FALSE; // reset rs-232 flowcontrol to stop data hangs.
		LINK.tx_cps = tx_tmp; // update host link CPS data
		LINK.rx_cps = rx_tmp;
		tx_tmp = 0;
		rx_tmp = 0;

		if (DIPSW2 == HIGH) { // set number of batteries to 2 or 4
			battnum = HISTBATTNUM;
		} else {
			battnum = MAXBATT;
		}

		MPULED = !MPULED; //  flash led
		V.timerint_count++; // set 1 second clock counter.
		if (CCMODE == ABSORP_M) B.absorp_time++; // keep time in state
		display_count++; // display VC screen  display timer
		if (display_count > DISPSEC) { // turn off LCD after DISPSEC seconds
			//					D_UPDATE=FALSE;
		}
		// PV reload logic / check before DAYCLOCK is updated (needs work)
		//				if (P.SYSTEM_STABLE && !SDC0.DAYCLOCK && (R.inputvoltage > SOLARDOWN)) PVLOAD=R_ON;		//  load down the PV input
		if (P.SYSTEM_STABLE && SDC0.DAYCLOCK && ((R.inputvoltage < LOADLOW) || (R.inputvoltage > CHRG_HIGH))) {
			if (LOADNOTFAN || !P.COOLING) PVLOAD = R_OFF; //  unload the PV input
		}

		/* daily housekeeping routines */
		if (((!SDC0.DAYCLOCK) && (R.inputvoltage > SOLARUP)) && P.SYSTEM_STABLE && (solarup_delay++ >= SUPDELAY) && CHARGERL) { // store sun up time
			dayclockup = V.timerint_count;
			solarup_delay = NULL0;
			SDC0.DAYCLOCK = TRUE;
			glitch_count = NULL0;
			SDC0.harvest.e_total += SDC0.harvest.energy;
			SDC0.harvest.c_total += SDC0.harvest.charger;
			SDC0.harvest.u_total += SDC0.harvest.usage;
			SDC0.harvest.prev_energy = SDC0.harvest.energy;
			SDC0.harvest.prev_charger = SDC0.harvest.charger;
			SDC0.harvest.prev_usage = SDC0.harvest.usage;
			SDC0.harvest.energy = NULL0;
			SDC0.harvest.charger = NULL0;
			SDC0.harvest.usage = NULL0;
			B.yesterday = B.today;
			B.today = NULL0;
			B.diversion = NULL0;
			alarm_buffer[almctr].bn = CCS.boc;
			alarm_buffer[almctr++].alm_num = 13;
			alarm_codes.alm_flag = TRUE;
			if ((uint8_t) hist[CCS.boi].bsoc <= (uint8_t) HELP_SOC) { // check for low soc,  TKS to BILL @ NAWS for the idea
				if (DIPSW4 == HIGH) {
					alarm_buffer[almctr].bn = CCS.boc;
					alarm_buffer[almctr++].alm_num = 11;
					alarm_codes.alm_flag = TRUE;
					if (!DIPSW8 && !DIVERSION_set) DIVERSION = R_OFF; // don't override the switch
					if (R.currentin < CHARGER_MIN) {
						c_on = V.timerint_count;
						CHARGERL = R_ON;
						PVLOAD = R_OFF;
						P.MORNING_HELP = TRUE;
						alarm_buffer[almctr].bn = hist[CCS.boi].bsoc;
						alarm_buffer[almctr++].alm_num = 5;
						alarm_codes.alm_flag = TRUE;
					}
				}
			}
			P.UPDATE_EEP = TRUE;
		}
		if (solarup_delay > (SUPDELAY + 1)) {
			solarup_delay = NULL0; // this should not be needed but is a failsafe
		}
		if ((V.timerint_count - dayclockup) > DAYDELAY) P.FORCEDAY = TRUE; // Force the End of Day after 24 hours of operation (Charger or external power source)

		if (SDC0.DAYCLOCK && P.MORNING_HELP && P.SYSTEM_STABLE) { // turn off charger after morning boost
			if (((V.timerint_count - dayclockup) > HELP_TIME) && (hist[CCS.boi].bsoc >= HELP_SOC)) {
				c_off = V.timerint_count;
				CHARGERL = R_OFF;
				P.MORNING_HELP = FALSE;
				solarup_delay = NULL0;
				alarm_buffer[almctr].bn = hist[CCS.boi].bsoc;
				alarm_buffer[almctr++].alm_num = 6;
				alarm_codes.alm_flag = TRUE;
			}
		}

		if (((SDC0.DAYCLOCK) && (R.inputvoltage < SOLARDOWN) && P.SYSTEM_STABLE) || P.FORCEDAY) { // store sun down time or after 24 hour run
			if (LOADNOTFAN || !P.COOLING) PVLOAD = R_OFF; // charge load relay/off at end of day
			if ((V.timerint_count - dayclockup) > DARKDELAY) { // Try not to short cycle
				if ((V.timerint_count - dayclockup - DARKDELAY) > DARKDELAY) { // make sure it's really dark
					dayclockdown = V.timerint_count;
					SDC0.DAYCLOCK = FALSE;
					if (P.FORCEDAY) {
						P.FORCEDAY = FALSE;
						dayclockup = V.timerint_count;
					}
					solarup_delay = NULL0;
					P.SAVE_DAILY = TRUE; // Flag to save data outside of the ISR daily
					if (LOADNOTFAN || !P.COOLING) PVLOAD = R_OFF;
					hist[B1].aho += AH_DAY_LOSS1; // default daily Ah discharge batt1
					hist[B2].aho += AH_DAY_LOSS2; // default daily Ah discharge batt2
					hist[B1].ahop += AH_DAY_LOSS1; // default daily Ah discharge batt1
					hist[B2].ahop += AH_DAY_LOSS2; // default daily Ah discharge batt2
					B.watercounter = cell[B1].cycles + cell[B2].cycles + cell[B3].cycles + cell[B4].cycles;
					if ((B.watercounter - B.watercounter_prev) >= BATTWATER) { //check for the next step in charge time
						alarms.mbmc_alarm.absorp = 1;
					}
					alarm_buffer[almctr].bn = CCS.boc;
					alarm_buffer[almctr++].alm_num = 8;
					alarm_codes.alm_flag = TRUE;
				}
			}
		}

		// check for charger on with high input voltage on array or too much current when on
		if ((R.currentin > MAX_SAFEAMPS) || (P.SYSTEM_STABLE && (!CHARGERL) && (R.inputvoltage > CHRG_HIGH) && (!cell[CCS.boc].critical) && (CCS.boc != B0))) {
			c_off = V.timerint_count;
			CHARGERL = R_OFF; // save grid power because PV is online and providing excess power
			solarup_delay = NULL0;
			alarm_buffer[almctr].bn = CCS.boc;
			alarm_buffer[almctr++].alm_num = 7;
			alarm_codes.alm_flag = TRUE;
		}

		/* cycled LCD display screens */
		if (worker_timer-- <= 1) { // check worker thread go flag
			P.WORKERFLAG = TRUE;
			TIMESIG = !TIMESIG;
			worker_timer = WORKSEC;

			if (DISPLAY_MODE) {
				vc_count++;
				if (vc_count >= VC_MAX) vc_count = NULL0;
				switch (vc_count) {
				case VS0:
					dsi = VC0;
					break;
				case VS1:
					dsi = VC1;
					break;
				case VS2:
					dsi = VC2;
					break;
				default:
					dsi = VC0;
					break;
				}
			}
		}

		/* C40 led status routines , find state of C40 charge controller by counting/timing the LED */
		if (ccled_flag.seconds-- < 1) { // count blink ticks in CCLEDBLINK seconds
			ccled_flag.ticks = ccled_flag.count;
			ccled_flag.count = NULL0;
			if (SIM_MODE) ccled_flag.ticks = CCFOURBLINKS;
			ccled_flag.seconds = CCLEDBLINK;
			ccled_flag.online = FALSE;
			CCMODE = IDLE_M; // no blinks

			if (ccled_flag.ticks >= CCONEBLINK) {
				ccled_flag.online = TRUE;
				CCMODE = BULK_M;
			}
			if (ccled_flag.ticks >= CCFOURBLINKS) {
				CCMODE = ABSORP_M;
				if (R.ccvoltage > BATTABSORP) {
					if (CCS.boi == CCS.boc) {
						absorp_current = R.current;
					} else {
						absorp_current = -R.currentin;
					}
				}
			}
		}

		if (((ccled_flag.ticks >= CCLEDSOLID) && ccled_flag.flag)
			&& (CCMODE != IDLE_M) && ((R.ccvoltage > VCP) && P.SYSTEM_STABLE)) { // C40 led status routine (LED-lit,charging state and solar at correct voltage)
			// overkill but lets really be sure
			if ((cctimer < CCFLOATTIME) && (CCS.pick == CCS.boc)) {
				cctimer = CCLEDTIME; // keep in float loop until "pick_batt" goes elsewhere
			}
			CCMODE = FLOAT_W; // in float with possible wait time
			if (cctimer-- < 2) {
				CCMODE = FLOAT_M; // don't wait in float
				cctimer = 1;
			}
		} else {
			cctimer = CCLEDTIME;
			if (ccled_flag.ticks >= CCFOURBLINKS) { // we are not in float so save the current absorp current value
				if (R.ccvoltage > BATTABSORP) {
					if (CCS.boi == CCS.boc) {
						absorp_current = R.current;
					} else {
						absorp_current = -R.currentin;
					}
				}
			}
		}

		if (absorp_current > 0) absorp_current = 0; // only use charging data

		if (CCLED == S_ON)
			ccled_flag.flag = TRUE; // set led on flag if LED is lit during the 1 second timer check

		if (((C.currentload > INVERTERON) || (R.currentin > GASSING)) && VENTENABLE) {
			VENTFAN = R_ON; // system is active, clear the air
			venttimer = VENTTIME;
		} else {
			if (venttimer-- < 0) // check for zero
				if (VENTFAN == R_ON) {
					alarm_buffer[almctr].bn = CCS.boi;
					alarm_buffer[almctr++].alm_num = 26;
					alarm_codes.alm_flag = TRUE;
					check_alarm(CCS.boi, " ventfan OFF "); // send alarm codes to terminal if alm_flag is set
					VENTFAN = R_OFF;
				}
		}

		// check auto logger timer for SD CARD block write
		if (loggertime-- < HIGH) { // check for zero
			battbuffer.flag = TRUE;
			ZAP = TRUE;
			loggertime = LOGGERTIME;
		}

		/* battery monitor action routines */
		if (P.SYSTEM_STABLE
			&& ((((R.primarypower[B1] > BATTCRIT) && (R.primarypower[B1] < BATTFLAT))
			&& (cell[B1].valid == cell[B0].valid))
			|| (((R.primarypower[B2] > BATTCRIT) && (R.primarypower[B2] < BATTFLAT))
			&& (cell[B2].valid == cell[B0].valid)))
			) { // check for low battery condition not disconnected battery

			if (P.PRIPOWEROK) { // went from good to bad
				/*	do something?	*/
			}
			//	    P.PRIPOWEROK = FALSE; // set software flag and trigger HOUSE power charger/generator
			if (DIPSW4 == HIGH) {
				if (R.currentin < CHARGER_MIN) {
					c_on = V.timerint_count;
					CHARGERL = R_ON; // RB0 is external battery charger/generator relay
					PVLOAD = R_OFF;
					alarm_buffer[almctr].bn = CCS.boc;
					alarm_buffer[almctr++].alm_num = 1;
					alarm_codes.alm_flag = TRUE;
				}
			}
		} else {
			if ((R.primarypower[CCS.boi] > BATTFRESH) && (cell[CCS.boi].valid == cell[B0].valid)) { // if battery is full recharged
				if (!P.PRIPOWEROK) { // went from bad to good
					/*	do something?	*/
				}
				P.PRIPOWEROK = TRUE;
			}
		}

	}

	// Serial port communications to the host and terminal
	//
	/* start with data_ptr pointed to address of data, data_len to length of data in bytes, data_pos to 0 to start at the beginning of data block */
	/* then enable the interrupt and wait for the interrupt enable flag to clear
	/* send buffer and count xmit data bytes for host link */
	if (PIE1bits.TX1IE && PIR1bits.TX1IF) { // send data to host USART
		V.mbmcdata_count++; // total data sent counter
		V.c1tx_int++;
		tx_tmp++; // count for 1 second
		if (mbmcflag.data_pos >= mbmcflag.data_len) { // buffer has been sent
			if (TXSTA1bits.TRMT) { // last bit has been shifted out
				PIE1bits.TX1IE = LOW; // stop data xmit
			}
		} else {
			TXREG1 = *mbmcflag.data_ptr; // send data and clear PIR1bits.TX1IF
			mbmcflag.data_pos++; // move the data pointer
			mbmcflag.data_ptr++; // move the buffer pointer position
		}
	}

	/* Get the character received from the USART */
	if (PIR1bits.RC1IF) { // is data from network 9n1 port
		V.c1rx_int++; // total count
		rx_tmp++; // count for 1 second
		if (RCSTA1bits.OERR) {
			RCSTA1bits.CREN = LOW; // clear overrun
			RCSTA1bits.CREN = HIGH; // re-enable
		}

		/* clear com1 interrupt flag */
		// a read clears the flag
		c1 = RCREG1; // read data from port1 and clear PIR1bits.RC1IF

		if (!RCSTA1bits.RX9D && P.SYSTEM_STABLE) { // data from host
			if (UTC_flag && (netdword_pos < NTP_SIZE)) { // The data is a UTC time structure
				netd.netdbyte[netdword_pos] = c1; // copy data from serial port to var
				netdword_pos++; // move to next position
				if ((netdword_pos >= NTP_SIZE) && UTC_flag) { // check for all 4 bytes
					if (netd.netdword > CHECK_DATE) { // check if it's a good date
						utctime = netd.netdword; // set local controller UTC to NTP
						if (UTC_ok) {
							time_skew = time_skew_base - (utctime - V.timerint_count); // find the diff (with network latency)
						} else {
							time_skew_base = utctime - V.timerint_count; // set the baseline count for internal clock drift
						}
						UTC_ok = TRUE;
					}
					UTC_flag = FALSE;
					netdword_pos = 0;
				}
			}
		}

		/* Host comm routines, bit nine set Receive Commands */
		if (RCSTA1bits.RX9D && P.SYSTEM_STABLE) {
			if (!HOST_BUSY) {
				HOST_BUSY = TRUE;
				switch (c1) {
				case HOST_REQ:
					mbmcflag.mbmc_cmd = HOST_REQ;
					mbmcflag.host_timeout == NULL0;
					break;
				case HOST_CMD_UTC_S:
					mbmcflag.mbmc_cmd = HOST_CMD_UTC_S;
					netdword_pos = 0;
					UTC_flag = TRUE;
					break;
				case HOST_REAL:
					mbmcflag.mbmc_cmd = HOST_REAL;
					break;
				case HOST_CELL:
					mbmcflag.mbmc_cmd = HOST_CELL;
					break;
				case HOST_HIST:
					mbmcflag.mbmc_cmd = HOST_HIST;
					break;
				case HOST_SDC0:
					mbmcflag.mbmc_cmd = HOST_SDC0;
					break;
				case HOST_CMD_F:
					P.FORCEOUT = TRUE; // received F command from host, set flag on controller.
					mbmcflag.mbmc_cmd = HOST_CMD_F;
					break;
				case HOST_CMD_V:
					c_on = V.timerint_count;
					CHARGERL = R_ON;
					PVLOAD = R_OFF;
					alarm_buffer[almctr].bn = CCS.boc;
					alarm_buffer[almctr++].alm_num = 15;
					alarm_codes.alm_flag = TRUE;
					if (!CHARGERL) {
					} else {
						P.CHARGEROVERRIDE = FALSE;
					}
					CCS.alert = FALSE;
					mbmcflag.mbmc_cmd = HOST_CMD_V;
					break;
				case HOST_CMD_v:
					c_off = V.timerint_count;
					CHARGERL = R_OFF;
					alarm_buffer[almctr].bn = CCS.boc;
					alarm_buffer[almctr++].alm_num = 14;
					alarm_codes.alm_flag = TRUE;
					P.CHARGEROVERRIDE = FALSE;
					CCS.alert = FALSE;
					mbmcflag.mbmc_cmd = HOST_CMD_v;
					break;
				case HOST_CMD_D: // Diversion on
					DIVERSION_set = TRUE;
					mbmcflag.mbmc_cmd = HOST_CMD_D;
					break;
				case HOST_CMD_d: // Diversion off
					DIVERSION_set = FALSE;
					mbmcflag.mbmc_cmd = HOST_CMD_d;
					break;
				case HOST_CMD_SOC:
					SYNCSOC = TRUE; // received * command from host, set flag on controller, non-interactive.
					mbmcflag.mbmc_cmd = HOST_CMD_SOC;
					break;
				case HOST_ACK:
					HOST_COMM = FALSE;
					HOST_BUSY = FALSE; // doing nothing so just clear the flag
					break;
				default:
					HOST_COMM = FALSE;
					HOST_BUSY = FALSE; // doing nothing so just clear the flag
					break;
				}
			}
		}
	}

	/* start with data_ptr pointed to address of data, data_len to length of data in bytes, data_pos to 0 to start at the beginning of data block */
	/* then enable the interrupt and wait for the interrupt enable flag to clear
	/* send buffer and count xmit data bytes for terminal link */
	if (PIE3bits.TX2IE && PIR3bits.TX2IF) {
		if (mbmc_dumpflag.data_pos >= mbmc_dumpflag.data_len) { // buffer has been sent
			if (TXSTA2bits.TRMT) { // last bit has been shifted out
				PIE3bits.TX2IE = LOW; // stop data xmit
			}
		} else {
			TXREG2 = *mbmc_dumpflag.data_ptr; // send data and clear PIR1bits.TX1IF
			V.c2_int++;
			mbmc_dumpflag.data_pos++; // move the data pointer
			mbmc_dumpflag.data_ptr++; // move the buffer pointer position
		}
	}

	/* User terminal comm 8n1 routines */
	if (PIR3bits.RC2IF) { // is data from user command/dump terminal port
		/* clear com2 interrupt flag */
		// a read clears the flag
		V.c2_int++;
		if (RCSTA2bits.OERR) {
			RCSTA2bits.CREN = LOW; //      clear overrun
			RCSTA2bits.CREN = HIGH; // re-enable
		}

		c2 = RCREG2; // read from host port2 and clear PIR3bits.RC2IF
		c2raw = c2; // set terminal input char.
		switch (c2) {
		case 'A': // send complete status string.
			battbuffer.flag = TRUE;
			ZAP = TRUE;
			break;
		case 'E': // switch to #2 battery in FAIL-SAFE mode
			if (P.FAILSAFE) {
				CCOUTOPENSW = R_OFF;
				SOLAROFF = R_OFF;
				if (LOADNOTFAN || !P.COOLING) PVLOAD = R_OFF;
				BCRELAYS = 0xFF;
				BAT1 = R_OFF; // battery #1 relay/on
				CHRG1 = R_OFF; // charge #1 relay/off
				BAT2 = R_ON; // battery #2 relay/off
				CHRG2 = R_ON; // charge #2 relay/on
				CCS.boc = B2;
			}
			break;
		case 'F': // set charge break flag
			P.FORCEOUT = TRUE;
			break;
		case '?': // Set boc to 100% SOC
			SYS_HELP = TRUE;
			break;
		case '*': // Set boc to 100% SOC
			SYNC_SOC = TRUE;
			break;
		case '#': // Display system data on rs-232 terminal
			SYS_DATA = TRUE;
			break;
		case '@': // Display system data on rs-232 terminal
			MOD_DATA = TRUE;
			break;
		case '!': // Hold monitor processing
			P.HOLD_PROC = TRUE;
			break;
		case '^': // set AMPLOC sensor zero flag
			P.RESET_ZEROS = TRUE;
			break;
		case 'g': // set ADC gain flag
			SET_ADC = TRUE;
			break;
		case 'T': // Tweak charge run parameters
			TWEAK = TRUE;
			break;
		case 'G': // GANGED mode toggle
			GANGED_MODE = TRUE;
			break;
		case 'Y':
		case 'y': // set key flag
			YNKEY = YES_M;
			break;
		case 'N':
		case 'n': // set key flag
			YNKEY = NO_M;
			break;
		case 'H': // set SD card dump flag
			SDD0.type = 'H'; // full data dump
			if (!battbuffer.busy) {
				SDD0.dumping = !SDD0.dumping;
			} else {
				SDD0.dumping = FALSE;
			}
			break;
		case 'h': // set SD card dump flag
			SDD0.type = 'h'; // last 1000 records dump
			if (!battbuffer.busy) {
				SDD0.dumping = !SDD0.dumping;
			} else {
				SDD0.dumping = FALSE;
			}
			break;
		case 'V': // turn external charger on
			c_on = V.timerint_count;
			CHARGERL = R_ON;
			PVLOAD = R_OFF;
			alarm_buffer[almctr].bn = CCS.boc;
			alarm_buffer[almctr++].alm_num = 15;
			alarm_codes.alm_flag = TRUE;
			CCS.alert = FALSE;
			break;
		case 'v': // turn external charger off
			c_off = V.timerint_count;
			CHARGERL = R_OFF;
			alarm_buffer[almctr].bn = CCS.boc;
			alarm_buffer[almctr++].alm_num = 14;
			alarm_codes.alm_flag = TRUE;
			P.CHARGEROVERRIDE = FALSE;
			CCS.alert = FALSE;
			break;
		case 'D': // turn diversion on
			DIVERSION_set = TRUE;
			break;
		case 'd': // turn diversion off
			DIVERSION_set = FALSE;
			break;
		case 'K': // lockup controller in loop force WDT timeout
			while (TRUE);
			break;
		case 'B': // select battery 1,2,3,4,0=array data
			batttype.position++;
			if (batttype.position > 4) {
				batttype.position = 0;
			}
			batttype.busy = TRUE;
			break;
		case 'P': // SIM "PV voltage on"
			SIM_FLAG = 0b00000001;
			break;
		case 'p': // SIM "PV voltage off"
			SIM_FLAG = 0b00000010;
			break;
		case 'O': // SIM ""
			SIM_FLAG = 0b00000100;
			break;
		case 'o': // SIM ""
			SIM_FLAG = 0b00001000;
			break;
		case 'w': // clear watering counter flag
			alarms.mbmc_alarm.absorp = 0;
			B.watercounter_prev = cell[B1].cycles + cell[B2].cycles + cell[B3].cycles + cell[B4].cycles; // need a new starting point
			B.watercounter = B.watercounter_prev;
			break;
		case 'W': // set watering counter flag
			alarms.mbmc_alarm.absorp = 1;
			break;
		case 'Z': // clear command flags
			ZAP = TRUE;
			break;
		default:
			if ((c2 >= 0x30) && (c2 <= 0x39)) { // return number
				keynum = c2;
			}
			if (batttype.busy) { // battery selected. what operation?
				if (c2 == 'C') { // does nothing yet
					battbuffer.good = FALSE;
				} // clear battery eeprom data
				if ((c2 == 'S') || (c2 == 'M') || (c2 == 'L')) { // moved write code out of ISR
					P.SET_BATT = TRUE;
					battbuffer.good = FALSE;
				}
			}
			break;
		}
		if (ZAP) { // clear command flags
			batttype.busy = FALSE;
			batttype.flag = FALSE;
			batttype.good = FALSE;
			batttype.length = 0;
			batttype.position = 0;
			ZAP = FALSE;
		}
	};

	/* Control button/power status routines */
	if (INTCON3bits.INT1IF) {
		//        HIDLED = R_ON;
		INTCON3bits.INT1IF = LOW;
	}

	if (INTCON3bits.INT3IF) {
		//        HIDLED = R_ON;
		INTCON3bits.INT3IF = LOW;
	}

	if (INTCONbits.RBIF) { // PORT B int handler
		INTCONbits.RBIF = LOW;
		b_read = EXTIO;
		b_read = EXTIO; // double read to make sure
		V.buttonint_count++;
		P.D_UPDATE = TRUE;
		display_count = NULL0;

		if (!HID1) {
			DISPLAY_MODE = FALSE;
			P.BLANK_LCD = TRUE;
			HIDLED = R_OFF;
		}
		if (HID2 && !HID1) { // both must be pressed, 1 first then 2
			DISPLAY_MODE = TRUE;
			P.BLANK_LCD = TRUE;
			HIDLED = R_ON;
		}

		if (!STFU) {
			ALARMOUT = R_OFF;
			HIDLED = R_OFF;
			P.POWER_UNSTABLE = FALSE;
			UTC_ok = FALSE; // DEBUG test code
		}
		if (PERKOSWI) {
			PERKOSW_R = TRUE;
		} else {
			PERKOSW_R = FALSE;
		}
	}
	// PWM4 ISR routines, ONLY FOR TESTING
	if (PIE3bits.TMR4IE && PIR3bits.TMR4IF) { // PWM4 post int
		/* clear timer4 interrupt flag */
		PIR3bits.TMR4IF = LOW;
		V.pwm4int_count++;
	}

	hirez_tmp1 = (uint16_t) TMR0L;
	hirez_tmp1 += (uint16_t) (TMR0H << SHIFT8); // load high byte in tmp counter
	hirez_count[2] += (hirez_tmp1 - hirez_tmp0); // how many counts we were in routines
}
#pragma	tmpdata

#pragma	tmpdata	ISRLtmpdata
#pragma interruptlow work_handler   nosave=section (".tmpdata")

void work_handler(void) // This is the low priority ISR routine, the high ISR routine will be called during this code section
{
	static uint8_t hmin = 0, H_tmp = 0;
	static uint8_t z, boc = 0, boi = 0, pwm_delay = 0; // battery on c40, battery on inverter
	static int32_t ai, ao, an, abl, aop, D_tmp;
	static uint16_t hirez_tmp0 = 0, hirez_tmp1 = 0;
	static union Timers timer;

	_asm nop _endasm // asm code to disable compiler optimizations

	hirez_tmp0 = (uint16_t) TMR0L;
	hirez_tmp0 += (uint16_t) (TMR0H << SHIFT8); // load high byte in tmp counter
	V.lowint_count++; // low int trigger entropy counter
	if ((V.lowint_count % 200) == NULL0) MPULED = !MPULED; //  flash led

	if (PIR2bits.TMR3IF) { //      Timer3 int handler
		PIR2bits.TMR3IF = LOW; // clear int flag
		timer.lt = TIMER3REG; // Save the 16-bit value in local
		TMR3H = timer.bt[HIGH]; // Write high byte to Timer3 High byte
		TMR3L = timer.bt[LOW]; // Write low byte to Timer3 Low byte
		V.clock50++;
		real_ticks++;
		if (almctr > MAXALM - 2) almctr = MAXALM - 2; // check for alarm message overrun.

		if (P.SYSTEM_STABLE) { // wait until we are really running
			alarms.mbmc_alarm.utility = AC_OFF_U;
			alarms.mbmc_alarm.inverter = AC_OFF_I;
			if (AC_OFF_I || AC_OFF_U) { // We want to check for possible power faults like the inverter shutting off rapidly because of voltage faults
				if (P.GLITCH_CHECK) {
					P.GLITCH_CHECK = FALSE;
					glitch_count++;
					alarm_buffer[almctr].bn = CCS.boi; // glitch code, AC power loss
					if (AC_OFF_U) {
						alarm_buffer[almctr++].alm_num = 16; // Utility message
					} else {
						alarm_buffer[almctr++].alm_num = 19; // Only Inveter message
					}
					alarm_buffer[almctr++].alm_num = 17; // Power off
					alarm_codes.alm_flag = TRUE;
				}
			} else {
				if (!P.GLITCH_CHECK) {
					P.GLITCH_CHECK = TRUE;
					glitch_count++;
					alarm_buffer[almctr].bn = CCS.boi; // glitch code, AC power online
					if (AC_OFF_U) {
						alarm_buffer[almctr++].alm_num = 16;
					} else {
						alarm_buffer[almctr++].alm_num = 19;
					}
					alarm_buffer[almctr++].alm_num = 18; //  Power on
					alarm_codes.alm_flag = TRUE;
				}
			}

			if (glitch_count >= MAX_GLITCH) { // Check if we have too many power glitches in one day
				P.POWER_UNSTABLE = TRUE; // the flag causes the system to shutdown the PV charging system and signals a major possible problem
				if (ALARMOUT == R_OFF) { // only if the alarm is not already on
					ALARMOUT = R_ON; // possible trouble with AC power
					alarm_buffer[almctr].bn = 2; // glitch code, glitch_count triggered alarm
					alarm_buffer[almctr++].alm_num = 16;
					alarm_codes.alm_flag = TRUE;
				}
				glitch_count = MAX_GLITCH - 2; // reset the trigger to the edge
			}
		}

		if (P.WORKERFLAG && P.SYSTEM_STABLE) { // WORKSEC time, update SOC/Ah data for batteries [1..2] 0 is the NULL0 battery
			P.WORKERFLAG = FALSE;
			worker_count++;
			/* Network timeout routines */
			if (mbmcflag.host_timeout++ > 2) {
				mbmcflag.cmd_timeout = TRUE;
				mbmcflag.host_timeout = HOST_TIMEOUT;
			}
			boc = B0; // set charger and inverter values to 0 NULL0 battery
			boi = B0;

			if (DIPSW5 == HIGH) { // hardware GANGED MODE, check DIPSW first, can be overridden in software or PERKO switch
				if (!GANG_OVERRIDE) B_GANGED = TRUE;
			} else {
				if (!GANG_OVERRIDE) B_GANGED = FALSE;
			}

			/*	check the battery charger inverter configuration */
			if (PERKOSW_R || (DIPSW3 == HIGH)) { // inverter battery switch position, DIPSW3 forces boi=1
				cell[B1].online = TRUE;
				cell[B2].online = FALSE;
				boi = B1;
			} else {
				cell[B1].online = FALSE;
				cell[B2].online = TRUE;
				boi = B2;
				B_GANGED = FALSE; // PERKO switch overrides DIPSW and clears software override
				GANG_OVERRIDE = FALSE;
			}

			/* setup configuration data */
			if (B_GANGED) {
				hist[B1].ah = B12_GANGEDAH;
			} else {
				hist[B1].ah = B1AH; // config battery cap in Ah, 1.0 A units
			}

			if (((R.thermo_batt > COOL_ON) && (R.thermo_batt < COOL_MAX)) || (R.currentin >= CC_HIGHPOWER)) { // set the overtemp cooling flag
				P.COOLING = TRUE;
			} else {
				if (((R.thermo_batt) < COOL_OFF) && (R.currentin < CC_HIGHPOWER)) P.COOLING = FALSE;
			}

			if (P.COOLING && (COOLFAN == R_OFF)) {
				COOLFAN = R_ON; // it's getting hot hot hot!!
				alarm_buffer[almctr].bn = CCS.boi;
				alarm_buffer[almctr++].alm_num = 24;
				alarm_codes.alm_flag = TRUE;
			}



			/* See if a real battery is being charged */
			if (cell[B1].cconline) boc = B1;
			if (cell[B2].cconline) boc = B2;
			if (cell[B3].cconline) boc = B3;
			if (cell[B4].cconline) boc = B4;

			/* update global charger and inverter flags */
			CCS.boi = boi; // [1..2]
			CCS.boc = boc; // [0..4]
			if (boc > HISTBATTNUM) boc = B0; // [0--2] set to zero just for these routines so updates are on the NULL0 battery or the primary energy cells

			/* Load data input history array */
			buth[hmin].bvi = R.primarypower[boc];
			buth[hmin].bvo = R.primarypower[boi];
			buth[hmin].bii = R.currentin;
			buth[hmin].bio = R.current;
			buth[hmin].bil = C.currentload;
			buth[hmin].boc = boc;
			buth[hmin].boi = boi;

			/* NULL0 battery setup */
			if (boc == B0) { // when charging cells 3&4 don't use this current on inverter Ah calcs
				buth[hmin].bii = B0; // if other than 1 or 2 make it zero for updates
			}

			/* start power calcs */
			/* Energy havest routines */
			if (cell[B1].current < 0) { // battery power in/out
				hist[B1].kwi -= (int32_t) (cell[B1].current * R.primarypower[B1]) / 360;
			} else {
				hist[B1].kwo += (int32_t) (cell[B1].current * R.primarypower[B1]) / 360;
			}

			if (cell[B2].current < 0) { // battery power in/out
				hist[B2].kwi -= (int32_t) (cell[B2].current * R.primarypower[B2]) / 360;
			} else {
				hist[B2].kwo += (int32_t) (cell[B2].current * R.primarypower[B2]) / 360;
			}

			if (CHARGERL == LOW) { // if charger relay is on update charger energy else update the PV array energy
				SDC0.harvest.charger += (int32_t) (R.currentin * R.inputvoltage) / 3600; // shift result right 1 zero with '3600'
				if (!AC_OFF_U && (R.inputvoltage < CHARGER_MINV)) { // check for good utility power and for proper charger output voltage
					if (cdelay++>CHARGER_DELAY) { // wait a bit before charger reset
						H_tmp = INTCONbits.GIEH;
						INTCONbits.GIEH = LOW;
						c_off = V.timerint_count; // this gets updated in the high ISR so we protect reads in the low ISR
						INTCONbits.GIEH = H_tmp;
						CHARGERL = R_OFF; // The charger should be on but is not, so turn off the signal to reset a possible overload.
						alarm_buffer[almctr].bn = CCS.boc;
						alarm_buffer[almctr++].alm_num = 20;
						alarm_codes.alm_flag = TRUE;
					}
				} else {
					cdelay = NULL0;
				}
			} else { // We are not on the charger so update solar harvest
				SDC0.harvest.energy += (int32_t) (R.currentin * R.inputvoltage) / 3600; // shift result right 1 zero with '3600'
				B.today = (uint8_t) ((float) SDC0.harvest.energy / (float) PW_MAX); // This is the harvest quality factor from: 0 to 125
				if (B.today > MAX_Q) B.today = MAX_Q; // check for merged days
				if (B.yesterday == 0) B.yesterday = B.today;
			}

			/* AC Power transfer relay routines */
			if ((C.currentload) > NULL0) { // make sure the result will be positive then if AC diversion relay is on update power to transfer box
				SDC0.harvest.usage += (int32_t) ((C.currentload) * R.primarypower[boi]) / 3600; // shift result right 1 zero with '3600'
				if (DIVERSION == R_ON) {
					D_tmp = (int32_t) ((C.currentload) * R.primarypower[boi]) / 3600; // shift result right 1 zero with '3600'
					SDC0.harvest.diversion += D_tmp;
					B.diversion += D_tmp; // todays diversion power
				}
			}

			/* battery history update routines */
			for (z = 1; z <= HISTBATTNUM; z++) { // battery history [1..2]
				if (!cell[z].online) { // default discharging for cells not on the inverter
					hist[z].aho += (int32_t) (((float) DCURRENT * (float) 100.0) / (float) 360.0);
					hist[z].ahop += (int32_t) ((((float) DCURRENT * (float) 100.0) * (hist[z].peukert_adj)) / (float) 360.0);

					ao = hist[z].aho;
					aop = hist[z].ahop;
					ai = hist[z].ahi;
					an = (ai - aop) / 100; // convert to tenth amp units
					hist[z].h[0] = (int16_t) an; // cumulative battery Ah cc and inv pf

					an = (ai - ao) / 100; // convert to tenth amp units
					hist[z].h[6] = (int16_t) an; // cumulative battery Ah cc and inv (real)

					if (an < (int16_t) hist[z].h[1]) {
						hist[z].h[1] = (int16_t) an; // lowest discharge ever
						hist[z].h[3] = (int16_t) ((int16_t) an + hist[z].h[3]) / 2; // avg discharge
					}
					if (an < (int16_t) hist[z].h[2]) hist[z].h[2] = (int16_t) an; // lowest discharge this cycle
				}
			}

			/* worker routine counters updates */
			hist[buth[hmin].boc].samplei++;
			hist[buth[hmin].boi].sampleo++;

			/* power update cleanup */
			hist[B0].kwi = 0; // set NULL0 battery to zero
			hist[B0].kwo = 0;

			/* use tmp vars for calcs */
			ahi_tmp = (int32_t) (((float) buth[hmin].bii * (float) 100.0) / (float) 360.0); // PV Ah current in 0.001 amp units
			aho_tmp = (int32_t) (((float) buth[hmin].bil * (float) 100.0) / (float) 360.0); // Inverter Ah load current in 0.001 A units
			ahop_tmp = (int32_t) ((((float) buth[hmin].bil * (float) 100.0) * (hist[boi].peukert_adj)) / (float) 360.0); // adjusted Inverter Load current

			/* Ah in real "with no battery correction" */
			hist[buth[hmin].boc].ahir += (int32_t) ahi_tmp; // update raw value without CEF

			if (hist[buth[hmin].boi].rest_rate >= RFACTOR_BANK) { // Rest Reserve Recovery Bank is filling up
				if (RFACTOR_RATE > hist[buth[hmin].boi].rest_rate) { // check for overflow
					hist[buth[hmin].boi].rest_rate -= RFACTOR_RATE; // slowly put some if it back into the battery Ah from the recovery bank
				} else {
					hist[buth[hmin].boi].rest_rate = 0; // overflow so set to zero
				}
				hist[buth[hmin].boi].ahi += RFACTOR_RATE; // add X mA back into the batery charge every 10 seconds
			} else {
				hist[buth[hmin].boi].rest_rate = 0; // completely empty bank at low current drains
			}

			/* update hist values for net currents in/out balance from battery */
			if (boi == boc) { // if both charging and running the inverter on same battery use the current sensor on the battery to calc battery amps in/out
				if (buth[hmin].bio < NULL0) { // (neg) means current charging battery
					abl = -(buth[hmin].bio); // convert to positive value for inflow of current into battery
					hist[buth[hmin].boc].ahi += (int32_t) ((((float) abl * 100.0) / 360.0) * (float) hist[boc].cef); // comp charge current
					if (CCMODE == ABSORP_M) B.absorp_ahi += (int32_t) ((((float) abl * 100.0) / 360.0) * (float) hist[boc].cef); // comp charge current also
				} else { // (pos) means battery supplying current
					abl = buth[hmin].bio; // positive value, so add to outflow of current from battery
					hist[buth[hmin].boi].aho += (int32_t) (((float) abl * 100.0) / 360.0); // Inverter Battery Load current
					ao = (int32_t) ((((float) abl * 100.0) * (hist[boi].peukert_adj)) / (float) 360.0); // Adjusted Inverter battery Load current
					hist[buth[hmin].boi].ahop += ao;
					if ((uint8_t) hist[buth[hmin].boi].bsoc >= (uint8_t) RFACTOR_BSOC) { // Rest Reserve Recovery
						if (hist[buth[hmin].boi].peukert_adj > Perk_ADJ_FL) { // start banking
							hist[buth[hmin].boi].rest_rate += (uint16_t) (((int32_t) ao * (int32_t) hist[buth[hmin].boi].rest_factor) / (int32_t) RFACTOR_MAX); // rest recovery Ah
						}
					}
				}
			} else { //	update split charger/inverter using currentin and currentload
				/* update battery on charger */
				hist[buth[hmin].boc].ahi += (int32_t) ((((float) buth[hmin].bii * 100.0) / 360.0) * (float) hist[boc].cef); // for battery on charger
				if (CCMODE == ABSORP_M) B.absorp_ahi += (int32_t) ((((float) buth[hmin].bii * 100.0) / 360.0) * (float) hist[boc].cef); // for battery on charger also
				/* update battery on Inverter */
				if (aho_tmp > NULL0) { // zero check for battery of Inverter
					hist[buth[hmin].boi].aho += aho_tmp; // Inverter Battery load current
					hist[buth[hmin].boi].ahop += ahop_tmp; // Inverter Battery load current  (with peukert factor)
					if ((uint8_t) hist[buth[hmin].boi].bsoc >= (uint8_t) RFACTOR_BSOC) { // Rest Reserve Recovery
						if (hist[buth[hmin].boi].peukert_adj > Perk_ADJ_FL) { // start banking
							hist[buth[hmin].boi].rest_rate += (uint16_t) (((int32_t) ahop_tmp * (int32_t) hist[buth[hmin].boi].rest_factor) / (int32_t) RFACTOR_MAX); // rest recovery Ah  (with peukert factor)
						}
					}

				}
			}
			if (hist[buth[hmin].boc].ahir < NULL0) hist[buth[hmin].boc].ahir = NULL0; // check for neg currents
			if (hist[buth[hmin].boc].ahi < NULL0) hist[buth[hmin].boc].ahi = NULL0; // check for neg currents
			if (hist[buth[hmin].boi].aho < NULL0) hist[buth[hmin].boi].aho = NULL0; // check for neg currents
			if (hist[buth[hmin].boi].ahop < NULL0) hist[buth[hmin].boi].ahop = NULL0; // check for neg currents

			/* setup temp vars for history array */
			ao = hist[buth[hmin].boi].aho;
			aop = hist[buth[hmin].boi].ahop;
			ai = hist[buth[hmin].boc].ahi;

			/* Ah balance routines */
			if (boi == boc) { // calc Ah usage from in/out balances (same battery)
				an = (ai - aop) / 100; // convert to 0.1A units
				// use a300 sensor current for net current + or - value.
				hist[buth[hmin].boi].h[0] = (int16_t) an; // cumulative battery 0.1A Ah cc and inv (pf)

				an = (ai - ao) / 100; // convert to 0.1A amp units
				// use a300 sensor current for net current + or - value.
				hist[buth[hmin].boi].h[6] = (int16_t) an; // cumulative battery 0.1A Ah cc and inv (real)
			} else { // split battery in/out
				ao = hist[buth[hmin].boc].aho;
				aop = hist[buth[hmin].boc].ahop;
				ai = hist[buth[hmin].boc].ahi;

				an = (ai - aop) / 100; // convert to 0.1A units
				hist[buth[hmin].boc].h[0] = (int16_t) an; // add charge to battery (pf)

				an = (ai - ao) / 100; // convert to 0.1A amp units
				hist[buth[hmin].boc].h[6] = (int16_t) an; // add charge to battery (real)

				ao = hist[buth[hmin].boi].aho;
				aop = hist[buth[hmin].boi].ahop;
				ai = hist[buth[hmin].boi].ahi;

				an = (ai - aop) / 100; // convert to 0.1A units
				hist[buth[hmin].boi].h[0] = (int16_t) an; // remove charge from battery (pf)

				an = (ai - ao) / 100;
				hist[buth[hmin].boi].h[6] = (int16_t) an; // remove charge from battery (real)
			}
		} // end of worksec functions

		if (!PIE1bits.TX1IE) { // don't update during host xmit
			// PWM Duty Cycle logic control
			MBMC.diversion.power_control = 0; // reset control bits

			if (((R.currentin * R.inputvoltage) / 10000) > PWM_POWER) MBMC.diversion.power_control |= PWM_FLAG_OK;

			if ((MBMC.diversion.power_control & PWM_FLAG_OK) && ((R.inputvoltage > PWMHIGH) || (CCMODE == ABSORP_M) || ((CCMODE == FLOAT_W) || (CCMODE == FLOAT_M))) && ((CHARGERL == R_OFF) || PWMTEST)) {
				MBMC.diversion.power = (uint8_t) CCEFF_DIFF;
			} else {
				if (MBMC.diversion.power > 1) {
					if (!pwm_delay++) MBMC.diversion.power = MBMC.diversion.power / 2; // no power, slowly
				} else {
					MBMC.diversion.power = 0; // no power
				}
				if ((CHARGERL == R_ON) && !PWMTEST) { // set all PWM to zero if charger is on and not testing
					MBMC.diversion.power = 0; // no power
					CCEFF_DIFF = 0;
				}
			}
			if (SIM_FLAG & 0b00001000) { // PWM SIM testing
				SIM_FLAG &= 0b11110011; // reset PWM SIM flags
			}
			if (SIM_FLAG & 0b00000100) MBMC.diversion.power = 33;
		}
		/* C40 led status counting routines */
		if (CCLED == S_ON) ccled_flag.count++; // bink speed routine
		if (CCLED == S_OFF && ccled_flag.flag) { // led on flag was set but now LED signal is OFF
			ccled_flag.flag = FALSE;
		}

		if (battbuffer.flag && battbuffer.good) { // check flags for buffer with data and time to log data: true
			battbuffer.flag = FALSE;
			battbuffer.position = 0;
			battbuffer.busy = TRUE;
		}

		if (battbuffer.busy && battbuffer.good && !SDD0.dumping) { // send data at timer3 irq rate
			if (battbuffer.position < battbuffer.length) {
				battbuffer.copy = FALSE;
				MPULED = !MPULED; //  flash led
				battbuffer.position = battbuffer.length; // just set the buffer for the SD card log
			} else {
				status_count++;
				battbuffer.busy = FALSE;
				battbuffer.copy = TRUE;
			}
		}
	}

	hirez_tmp1 = (uint16_t) TMR0L;
	hirez_tmp1 += (uint16_t) (TMR0H << SHIFT8); // load high byte in tmp counter
	hirez_count[3] += (hirez_tmp1 - hirez_tmp0); // how many counts we were in routines
}
#pragma	tmpdata

void idle_loop(void) // idle processe to allow for better isr triggers and background networking
{
	uint16_t crc;

	if (idleflag) return; // don't call if already running before
	idleflag = TRUE;
	if (HOST_BUSY) {
		if (!HOST_COMM) { // start of transmission so setup buffer
			mbmcflag.data_pos = 0; // reset the data position counter
			mbmcflag.data_ptr = (BYTE*) & MBMC; // default data
			mbmcflag.data_len = 1; // default len

			switch (mbmcflag.mbmc_cmd) {
			case HOST_REQ:
				// nothing, this is the default mcmb_cmd
				break;
			case HOST_CMD_UTC_S:
				// data will be copied to the controller time_utc counter
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			case HOST_REAL:
				mbmcflag.data_ptr = (BYTE*) & MBMC;
				mbmcflag.data_len = sizeof(MBMC);
				MBMC.crc = CHECKMARK_CRC; // load with 32 bit CRC value
				crc = crc16_ccitt((uint8_t*) & MBMC.ccvoltage, (uint16_t) sizeof(MBMC));
				MBMC.crc = (uint32_t) crc; // reload with 16bit crc value and send
				break;
			case HOST_CELL:
				mbmcflag.data_ptr = (BYTE*) & cell;
				mbmcflag.data_len = sizeof(cell);
				break;
			case HOST_HIST:
				mbmcflag.data_ptr = (BYTE*) & hist;
				mbmcflag.data_len = sizeof(hist);
				break;
			case HOST_SDC0:
				mbmcflag.data_ptr = (BYTE*) & SDC0;
				mbmcflag.data_len = sizeof(SDC0);
				break;
			case HOST_CMD_F:
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			case HOST_CMD_V:
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			case HOST_CMD_v:
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			case HOST_CMD_D:
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			case HOST_CMD_d:
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			case HOST_CMD_SOC:
				mbmc_cmd_reply = 1;
				mbmcflag.data_ptr = (BYTE*) & mbmc_cmd_reply;
				mbmcflag.data_len = sizeof(mbmc_cmd_reply);
				break;
			default:
				break;
			}
			HOST_COMM = TRUE; // set the transmit flag
		}

		// RS-232 link
		if (!PIE1bits.TX1IE) {
			TXSTA1bits.TX9D = LOW; // clear bit 9 for data
			PIE1bits.TX1IE = HIGH; // enable int to start xmit interrupt driven process for length of buffer
		}
		if (mbmcflag.data_pos >= mbmcflag.data_len) { // buffer has been sent
			TXSTA1bits.TX9D = HIGH; // set bit 9 for command
			P1wait();
			TXREG1 = HOST_ACK; // send ack in manual mode
			PIE1bits.TX1IE = HIGH; // enable int for count updates
			V.mbmcdata_count++;
			P1wait();
			TXSTA1bits.TX9D = LOW;
			mbmcflag.cmd_timeout = FALSE; // there is another system
			if (mbmcflag.mbmc_cmd == HOST_REAL) {
				MBMC.ports.NEWDATA = FALSE;
			} else {
				mbmc_update();
			}
			mbmcflag.mbmc_cmd = HOST_REQ; // set to default cmd
			HOST_COMM = FALSE; // clear the transmit flag
			HOST_BUSY = FALSE; // clear the command flag
		}
	}
	if (DIPSW8 || DIVERSION_set) {
		if (DIVERSION == R_OFF) {
			alarm_buffer[almctr].bn = CCS.boc;
			alarm_buffer[almctr++].alm_num = 10;
			alarm_codes.alm_flag = TRUE;
		}
		DIVERSION = R_ON; // DIVERSION ON override switch
	}
	pv_pwm_set(0); // control PWM signal output
	if (P.SAVE_DAILY) save_daily();
	ClrWdt();
	idleflag = FALSE;
}

void P1wait(void)
{
	while (!TXSTA1bits.TRMT) {
	};
}

void P2wait(void)
{
	while (!TXSTA2bits.TRMT) {
	};
}