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

#define	__MBMCCONFIG_H

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
 */
#define A_VPM		17300.0 	// array voltage at power max, millivolts units
#define	A_IPM		267.05  	// array current at power max,  0.1 A units
#define	A_SSC		294.45  	// array short circuit current, 0.1 A units
#define	PV_MAX		4619965ul 	// max possible power in milliWatts*10
#define AH_MAX		(PV_MAX/10ul)*16ul	// mAh for a full 16hr day and full power

/* Battery Ah caps	in 1.0A units */
#define MAXBATT		4			// the number of batteries to keep charged, 2 or 4
#define B1AH		225     	// FLA costco GC2
#define	B2AH		225    		// FLA costco CG2
#define B3AH		9      		// gell cell
#define	B4AH		9      		// gell cell
#define	PerkC1		1.26    	// Peukert Comp Batt #1
#define PerkC2		1.26		// Peukert Comp Batt #2
#define	DF		0.5     	// discharge floor of battery total Ah, normally 1.0, reduce below 1.0 to reserve Ah capacity
#define SOC_DF		60		// SOC below this is a full discharge for record keeping
#define SOC_FRESH	80		// static SOC value
#define SOC_FULL	100		// static SOC value
#define	HELP_TIME	7200    	// charger boost time for morning help (seconds)
#define	DUALLOAD	TRUE		// Have low and high current loads for battery testing.
#define CHARGER_MINV    12000ul         // if the voltage is less than this the charger is not operating
#define CHARGER_DELAY   20              // time delay in worksecs before resetting the charger if it trips
/* Alarm and logging */
#define MAX_GLITCH	12			// AC power on/off limit, at this point we sound the alarm and start to fix the problem (hopefully)
// for module data update testing
#define	MODEL_UPDATE    TRUE	// update the model database from runtime data
// Battery discharge action parameters
#define	WCHARGER	20000.0 	// turn on charger if battery weight on inverter is below this point
#define ALERTLOW	11000ul		// set alert flag in pick_batt at this level
#define ALERTCHRG	12600ul		// turn on external charger at this level during a battery alert
#define BSOCLOW		55			// when battery SOC less that this, really start making it next on the charge list
#define	HELP_SOC	60u      	// state of charge to begin charger help in morning
#define	CHARGER_MIN	20ll		// current from PV must be less that this to turn on utility battery charger
// Battery absorption time parameters
#define MIN_ABSORP      7200ul         // time in seconds for absorption phase.
#define CC_RESET_MAX	2		// Max about of times to reset the Charge controller after float to rebulk
// PWM gain feedback control
#define PWM_EXP		1.65		// CCEFF_DIFF -> x^y <- PWM_EXP
/* End user parameters */
