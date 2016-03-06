#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
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

//#define	__MBMCCONFIG_H

/* TESTING DEFINES */
#define	RUNSIM	FALSE			// use ADC test data instead of the real inputs
// * P		SIMULATE PV power on
// * p		SIMULATE PV power off
// * O		SIMULATE PWM 33%
// * o		SIMULATE PWM off
#define PWMTEST FALSE			// PWM debug flag

// Controller network ID
#define __MBMC_ID	1

/* PV user data parameters */
/* PV array defines for energy tracking */
/* array spec V,I,P	*/
/*  KYOCERA KD135GX-LFBS one, SHARP ND-123UJF one,NE-80EJEA two, SUNFORCE 15W panels five
 *  ~500 Watts total
 * http://ecmweb.com/green-building/highs-and-lows-photovoltaic-system-calculations
 * Vadj = Vmp ? {100% + [(Tmod - 25?C) ? TC Vmp]}
	where,
	Vadj is the temperature adjusted voltage
	Vmp is the module?s rated maximum power voltage
	Tmod is the temperature of the PV module
	25?C is the STC condition we must adjust from
	TC Vmp = Temperature correction factor in %/?C
 *
 *  Less than 6 in. of space between the module and roof surface: Tmod = Ambient + 35?C.
	More than 6 in. of space between the module and roof surface: Tmod = Ambient + 30?C.
	PV array mounted on a top of pole or elevated ground mount: Tmod = Ambient + 25?C.
	Tmod = 37?C +35?C = 72?C
 */

#define A_VMP		17300.0 	// array voltage at power max, millivolts units, 25c
#define A_VMP_TEMP      A_VMP/0.80      // Hot voltage value, 37c
#define	A_IMP		267.05  	// array current at power max,  0.1 A units
#define	A_SSC		294.45  	// array short circuit current, 0.1 A units
#define	PVP_MAX		4619965ul 	// max possible power in milliWatts*10, 25c
#define	PVP_MAX_TEMP	3695972ul 	// max possible power in milliWatts*10, 37c
#define PW_MAX		(PVP_MAX_TEMP/10ul)*16ul	// mAh for a full 16hr day and full power at 37c
#define PW_DIVERSION    PW_MAX/6        // the most power sent to diversion per day in auto
#define PV_TEMP_VMP     340l            // Voltage derate temp for Vmp

/* Charge Controller limit in 0.1A units */
#define MAX_SAFEAMPS    425             // Max safe current for the C40 controller +6%

/* Battery Ah caps	in 1.0A units */
#define MAXBATT		4		// the number of batteries to keep charged, 2 or 4
#define B1AH		208     	// FLA costco GC2
#define	B2AH		208    		// FLA costco CG2
#define B3AH		24      	// AGM cell, if these are changed for S to M or back the EEPROM must be reset with SW1
#define	B4AH		24      	// AGM cell
#define B1ID		'L'     	// FLA costco GC2
#define	B2ID		'L'    		// FLA costco CG2
#define B3ID		'M'      	// AGM cell, if these are changed for S to M or back the EEPROM must be reset with SW1
#define	B4ID		'M'      	// AGM cell
#define B12_GANGEDAH    B1AH+B2AH       // with perko switch on both power batteries.
#define	PerkC1		1.25    	// Peukert Comp Batt #1
#define PerkC2		1.25		// Peukert Comp Batt #2
#define	DF		1.0     	// discharge floor of battery total Ah, normally 1.0  reduce below 1.0 to reserve Ah capacity
#define KW_VOLTS        122l            // Volts for initial power calc in .kwo, set in noload_soc()
#define USER_DOD        1.0/0.5         // Percent of battery cap that we normally use. 1.0 is a full discharge, 2.0 50% discharge
#define CONT_DOD        0.4             // Controller power batteries
#define SOC_DF		40		// SOC below this is a full discharge for record keeping
#define SOC_FF          90              // SOC above this is a full recharge for record keeping
#define SOC_FR          25              // SOC for data reset at CC float while charging.
#define SOC_FRESH	90		// static SOC value
#define SOC_FULL	100		// static SOC value
#define SOC_VCOMP       12800ul         // use rest voltage SOC below this on battery not on inverter or charging
#define	HELP_TIME	7200		// charger boost time for morning help (seconds)
#define	DUALLOAD	TRUE		// Have low and high current loads for battery testing.
#define CHARGER_MINV    12000ul         // if the voltage is less than this the charger is not operating
#define CHARGER_DELAY   20              // time delay in worksecs before resetting the charger if it trips
/* Alarm and logging */
#define MAX_GLITCH	12		// AC power on/off limit, at this point we sound the alarm and start to fix the problem (hopefully)
// for module data update testing
#define	MODEL_UPDATE    TRUE            // update the model database from runtime data
// Battery discharge action parameters
#define	WCHARGER	20000.0 	// turn on charger if battery weight on inverter is below this point
#define ALERTLOW	11000ul		// set alert flag in pick_batt at this level
#define ALERTCHRG	12000ul		// turn on external charger at this level during a battery alert
#define BSOCLOW		20			// when battery SOC less that this, really start making it next on the charge list
#define	HELP_SOC	30u      	// state of charge to begin charger help in morning
#define	CHARGER_MIN	20ll		// current from PV must be less that this to turn on utility battery charger
// Battery absorption time parameters
#define MIN_ABSORP      10800ul         // time in seconds for absorption phase.
#define CC_RESET_MAX	3				// Max amount of times to reset the Charge controller after float to rebulk
// PWM gain feedback control
#define PWM_EXP			1.65			// CCEFF_DIFF -> x^y <- PWM_EXP
/* End user parameters */
#endif /* CONFIG_H_INCLUDED */
