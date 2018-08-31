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

// PIC18F8722 Configuration Bit Settings

#include <p18f8722.h>

// CONFIG1H
#pragma config OSC = HSPLL      // Oscillator Selection bits (HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Two-Speed Start-up disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = ON         // Watchdog Timer (WDT enabled)
#pragma config WDTPS = 4096     // Watchdog Timer Postscale Select bits (1:4096)

// CONFIG3L
#pragma config MODE = MC        // Processor Data Memory Mode Select bits (Microcontroller mode)
#pragma config ADDRBW = ADDR20BIT// Address Bus Width Select bits (20-bit Address Bus)
#pragma config DATABW = DATA16BIT// Data Bus Width Select bit (16-bit External Bus mode)
#pragma config WAIT = OFF       // External Bus Data Wait Enable bit (Wait selections are unavailable for table reads and table writes)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (ECCP2 input/output is multiplexed with RC1)
#pragma config ECCPMX = PORTE   // ECCP MUX bit (ECCP1/3 (P1B/P1C/P3B/P3C) are multiplexed onto RE6, RE5, RE4 and RE3 respectively)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RG5 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config BBSIZ = BB2K     // Boot Block Size Select bits (1K word (2 Kbytes) Boot Block size)
#pragma config XINST = ON      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit Block 1 (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit Block 2 (Block 2 (008000-00BFFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit Block 3 (Block 3 (00C000-00FFFFh) not code-protected)
#pragma config CP4 = OFF        // Code Protection bit Block 4 (Block 4 (010000-013FFFh) not code-protected)
#pragma config CP5 = OFF        // Code Protection bit Block 5 (Block 5 (014000-017FFFh) not code-protected)
#pragma config CP6 = OFF        // Code Protection bit Block 6 (Block 6 (01BFFF-018000h) not code-protected)
#pragma config CP7 = OFF        // Code Protection bit Block 7 (Block 7 (01C000-01FFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit Block 1 (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit Block 2 (Block 2 (008000-00BFFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit Block 3 (Block 3 (00C000-00FFFFh) not write-protected)
#pragma config WRT4 = OFF       // Write Protection bit Block 4 (Block 4 (010000-013FFFh) not write-protected)
#pragma config WRT5 = OFF       // Write Protection bit Block 5 (Block 5 (014000-017FFFh) not write-protected)
#pragma config WRT6 = OFF       // Write Protection bit Block 6 (Block 6 (01BFFF-018000h) not write-protected)
#pragma config WRT7 = OFF       // Write Protection bit Block 7 (Block 7 (01C000-01FFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR4 = OFF      // Table Read Protection bit Block 4 (Block 4 (010000-013FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR5 = OFF      // Table Read Protection bit Block 5 (Block 5 (014000-017FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR6 = OFF      // Table Read Protection bit Block 6 (Block 6 (018000-01BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR7 = OFF      // Table Read Protection bit Block 7 (Block 7 (01C000-01FFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not protected from table reads executed in other blocks)

#define	__MBMC_C			//	This is the main program

/*
 * This program controls and monitors solar power battery arrays on a 12vdc system
 * MBMC uses a simple expert machine to try and keep current the energy stored in a bank of batteries
 * The main physics functions are contained in the noload_soc, update_cef, ChargeBatt and pick_batt functions
 * Much work is needed to make the program flow logical but making it work first is the current effort
 * The network interface processor on a pic32 will be able to analyze the collected data for better control at some future point
 *
 * standard program units:
 * Voltage  in (uint32_t/uint16_t) millivolts,
 * Current in (int32_t) tenths of amps
 * Watts Power in (uint32_t)
 * Ah battery capacity (uint32_t) milliAh when in 32 bit variables/ (int16_t) tenths of Ah when in 16 bit variables for net in/out Ah balance usage h[0],h[6]
 *
 * R: structure, real values from measurements
 * C: structure, calculated values from measurements or programs
 * B: structure, battery parameters
 *
 * USART2 		Is the client comm port 38400
 * USART1		MBMC host network 38400
 * Timer0		1 second clock
 * TImer1		Not used
 * Timer2		Not used
 * Timer3		work thread , background I/O clock ~20HZ
 * TImer4		PWM Period clock

 * 0..11 analog channels are active
 * PORTA		analog inputs
 * adc0	systemvoltage					PIC Controller supply voltage to 5VDC regulator
 * adc1	ccvoltage					Charging voltage at battery from CC
 * adc2	currentin					50A AMPLOC sensor input from PV array
 * adc11		rawp1/inputvoltage		Voltage from PV array
 * adc4			rawp2/primarypower[B1]		Voltage a primary inverter battery
 * PORTB		external control i/o
 * PORTC0		C40 charge controller led input
 * PORTD		switch input
 * PORTE		battery/charge relays
 * PORTF						analog inputs
 * adc5	current					300A AMPLOC sensor battery output to inverter
 * adc6 rawp3/primarypower[B2]	Voltage for backup battery
 * adc8 currentcharger 			50A AMPLOC sensor on 15vdc 22A ps for external charger.
 * adc9 thermo_batt				thermistor input 10K at 25C RF4
 * adc10 Ground REF				zero adc charge cap
 * adc3  PLUS VREF				Using a external REF02AP 5 volt reference IC from TI/BB
 * adc_cal[10-13]				current sensors zero offset stored in eeprom 10=a50, 11=a50c, 12=a300, 14=future
 * cal table 98,123,ADC_NULL,161,119,ADC_NULL,ADC_NULL,ADC_NULL,ADC_NULL with checksum as last data item in adc_cal[]
 * PORTH0		run flasher led onboard.
 * PORTJ		load/input relays
 * PORTG		ESR load relay, Diversion PWM signal
 * 4x20 LCD status panel and led status lights.
 * currentload					The current going the power the inverter or other load.
 *
 *
 * nsaspook@nsaspook.com Copyright 2014
 * Fairview, Oregon
 * MMC-SD card routines from ELM-CHAN,www.captain.at,www.microchipc.com and others
 */

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

/*
 *
 * This application is designed for use with the
 * ET-BASE PIC8722 board, 4*20 LCD display and XANTREX C40 charge controller.
 *
 * RS-232 host commands 38400baud 8n1
 * A		send controller/battery status
 * B		select battery for modify commands, used with S M L
 * C		(NOT DONE YET)
 * D		Diversion on
 * d		Diversion off
 * E		When in FAIL-SAVE mode switch to second battery
 * F		Force current (none critical) charge routine to exit
 * G		Toggle GANGED mode  batteries B1@B2 banked mode
 * g 		Calibrate ADC voltages.
 * H		Dump all SD card data records to comm1 port
 * h		Dump last 1000 SD card data records to comm2 port
 * K		lockup controller causing WDT timer to reboot
 * S M L	modify selected battery type, example: ZBBMZ would set battery 2 to M type.
 * T		Tweak setting for active battery on charger
 * V		turn external charger on
 * v		turn external charger off
 * Z		reset command parser
 * ?		Send help menu to rs-232 terminal
 * $		fuse blown error. (NOT DONE YET)
 * ^		reset current sensor zero calibration
 * !		hold program in present date
 * *		set battery on CC to 100% SOC
 * #		display run data on terminal rs-232 port
 * @		display model data on terminal rs-232 port
 * P		SIMULATE PV power on
 * p		SIMULATE PV power off
 * O		SIMULATE PWM 33%
 * o		SIMULATE PWM off
 *
 */


//	***
//  0.2             solar charge monitor software.
//  0.3             add A/D inputs for voltage/current monitor.
//  0.4             program battery switching and charge monitor
//  0.5             interface and data functions
//  0.6             randomize battery charging
//  0.7             load testing solar
//  0.8             load testing battery
//  0.9             battery data collection
//  1.0             basic operation
//  1.1             refine timing and lcd display
//  1.2             DT relays nornally closed power
//  1.3             improve charge logic
//  1.4             display
//  1.5             better battery checks
//  1.6             setup number of batteries
//  1.7             monitor rawp1(cell) rawp2
//  1.8             monitor charging source(s)
//  1.9             fix battery flags and timers
//  2.0             timer0 isr for flasher and time
//  2.1             rs-232 comms
//  2.2             cleanup for first basic release
//  2.3             format LCD output
//  2.4             status report update for all systems
//  2.5             monitor primary battery #1 (primarypower on ad4)
//  2.6             refactor code
//  2.7             more software cleanup with defines
//  2.8             fix cut/paste error     in critical battery section, add auto data logging
//  2.9             current sensor code for AMPLOC AMP300 sensor
//  3.0             change PORTF usage to PORTB, we now use PORTF as analog inputs.
//  3.1             Change host port to com2 so we can use ttl level inputs from CC on port1
//  3.2             Add FORCEOUT host command and code to check for charge controller status on port2
//  3.3             ADC voltage adjustments from host control
//  3.4             start basic battery monitor fuctions using Victron PMB as a model.
//  3.5             C40 LED status linked to program. two routines to monitor the LED. one just checks for solid LED, the other counts blinks
//                  We will check both as a failsafe mode to make sure the battery is charged. The blink monitor also looks for when we are in
//                  ABSORPTION mode and if the C40 in in BULK run mode.
//  3.6             cleanup current monitor and add GPL header.
//  3.7             low isr routines for timer2 and portb to support alarms and history worker thread
//  3.8             monitor backup battery #1 (primarypower[B2] on ad6)
//  3.9             high/low ISR bug fixes and code corrections
//  4.0             reformat datalogging format
//  4.1             Ah/Power/Runtime routines
//  4.2             convert LCD strings for multi use.
//  4.3             Display format and refresh fixes
//  4.4             FAIL-SAFE mode changes for battery equalization
//  4.5             Add the peukert routines for TTG, bug hunt
//  4.6             add digital signal filter, 63/64,3/4 ratios
//  4.7             DEADLOCK hunt
//  4.8             reformat display for 4x20 LCD
//  4.9             SD card datalogger, only works with SDHC cards, SD support is totally fubar
//  5.0             SDHC card support
//  5.1     SD card history, data dump
//  5.2     Improve battery float/charge logic to use several factors to product a total SOC "weight" to decide what to do. higher = better
//  5.3     save controller and battery history to SD card
//  5.4     redo CC and BM state machine code, add power divert
//  5.5     inverter battery sense switch code. (BETA)
//  5.6     fix data corruption bug in sd_dump
//  5.7     save run data to eeprom
//  5.8     current sensor zero routines, tek terminal codes on comm2 (control)
//  5.9     fix usart oerr errors. lockup in tek receive
//  6.0     Use battery monitor SOC at all times unless set to full charge with * command
//  6.1     set CEF from real battery SOC not derated capacity
//  6.2     keep CC in float as long as possible
//  6.3     serial control port command and bug fixed
//  6.4     Stop using timer1 and only have timer0 and timer2  1HZ 153HZ
//  6.5     Move back to timer1 at 50Hz and timer0 at 1hz
//  6.6     change default discharge to a daily event instead with setting for batts 1@2 AH_DAY_LOSS*
//  6.7     add drate to hist to adjust Ah rate when battery real Ahs seems different.
//  6.8     add runtime and error text for terminal display, add CCS.bn and CCS.alert logic to force battery selection and charging
//  6.9     rework code for fewer irq locks
//  7.0     add profile code with hirez_count[6]: 0=time in high isr, 1=time in low isr, 2= temp work var
//  7.1     code and display bug hunt
//  7.2     buffer overflow and switching bug hunt
//  7.3     stackover flow problems from floating point calcs, place critical flags around or simplify
//  7.4     Lots of global vars in use to reduce stack errors
//  8.0     Start using Peukert adjusted amps for SOC
//  8.1     fix Ah bug
//  8.2     fix high isr lockout bug
//  8.3     Fix idle loop wdt timeout
//  9.0     start host interface code for PIC32 rs-232 to ethernet web interface
//  9.1     Use GenericTypeDefs for compat with PIC32, add mbmc.h to share data with host code
//  9.2     Basic mbmc serial network connection and command API
//  9.3-9.5 network code changes
//  9.6     lp-filter fixes
//  9.7-10.0		Mainly MBMC web page routines and displays
//  10.0-10.3		Network code and ADC improvements (adc10 is grounded and used to discharge adc charge cap between measurements)
//  10.4    Correct errors in battery Ah in/out balance accounting (work_handler thread)
//  10.5    increase Hall Sensor samples to capture several PWM cycles
//  10.6    fix stupid worker thread time error. it was running at 11 seconds instead of 10. fix charger override deadlock in pick-batt
//  21.1    Power glitch and unstable code, move from timer1 to timer3 because of erata
//  21.6    Fix port B errors caused by not including openxlcd.c. it defaults to B for I/O in the C18 library version
//  21.7    Add a T command to change mainly Ah runtime data
//  22.0    A true Beta version, fix sd_dump to use correct rs-232 port
//  22.1    modify model for cap recovery and other factors
//  22.2    add battery model type data structures for better SOC matching
//  22.5    add xlcd files in package. Add code to allow optimization and still have correct program flow.
//  22.6    External Charger fixups, AC monitor code cleanup and additions, LCD VC code fixes, Rest Reserve Recovery simple model
//  22.7    Fix mbmc cell data transfer, add battery 1&2 current monitor code, add framework for diversion PWM control
//  22.8    minor dead battery error and esr calc fixes, start to split the source file, use interrupt driven xmit for the host link
//  22.9    Remove the battstatus 512 byte array and use sdbuffer instead, reworked the linker and variables to fix bank optimization.
//  23.0    Fix buffer overflow bug int16_t bootstr2 printing. Improve PWM and add ABSORPTION time adjustments, code refactor
//  23.1    Update SDCARD data format
//  23.2    Add a telnet server app on the PIC32 host that talks to the RS-232 terminal comm port, User: mbmc Password: mbmc
//  23.4    Add data to mbmcdata structure for chart data
//  23.5    Bug fixes to the BSOC and usages
//  23.7    Keep track of total power in and out of each battery, bug fixes
//  23.8    Allow Batteries 1&2 to operate GANGED mode, fix EEPROM cal data bug
//  23.9    Refactor variable names and type structures
//  24.0    change vars to stdint types
//  24.4    Fix a huge amount of runtime bugs
//  24.5-6  Add sunlight quality checking for DIVERSION FLAG
//  24.7    Add End-Amps factor for extended absorption timing
//  24.8    Rework static SOC code for better matching of the battery SOC to VOLTAGE
//  24.9    Store and display both SOC method results for skew, fix end_amps bug, add SOC codes U,S,M,F,R,L
//  25.0    Update SD data format and fix index bugs, pick_batt fixes
//  25.2    Move some routines from the main into modules
//  25.3    Use a external VREF 5.0v on ana3, move old an3 input to ana11, change OpenADC config
//	    This is a hardware change that should improve measurements
//  25.4    Fix kwi/kwo accounting
//  25.5    Start setting up the foundation for using ESR in SOC calc's
//  25.6    Fix some of the ESR routines and add data for esrp in data logging
//  25.7    Change the data logging format to make it easier to track variables.
//  25.8-9  Add more bad battery detection
//  26.0    Software fixes and cleanups
//  26.1    Fixups for gellcell current limiters, add GELL_R_COMP and GELL_ESR_COMP defines
//  26.2    Start moving all the flags into structures.
//  26.3    Add fresh data flag for remote data monitor and increase update rate while in charging modes
//  26.4    Fix B_GANGED bug in daq.c
//  30.0    New fixes branch
//  30.1    Use AGM cells for controller power so change 'S' to 'M'
//  30.4    Fix accounting bug on battery 3
//  40.0    New development branch
//  40.1    Lots of global variables but embedded C is one trick monkey
//  40.2    Dual charging of controller batteries and ganged fixes
//  40.3    get local time, equilization function and full charge count fixes
//  40.5    SD card updates
//  40.6    adjust battery weight by DOD >100
//	***
//  dipswitch settings PORTD
//  1       on=reset battery charging counters and flags
//  2       on=2 batteries/off=4 batteries to monitor
//  3       on=Force inverter to primary battery in software
//  4       on=turn on external charge power when needed
//  5       on= Enable GANGED B1 and B2
//  6       on=FAIL-SAFE MODE, just connect C40 to PRIMARY BATTERY
//  7       on=disenable DIVERSION control of excess power when battery on charger is full
//  8       on=Force DIVERSION on
//	***

#include <p18cxxx.h>
#include <delays.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mbmc_defs.h"
#include "xlcd.h"
#include "config.h"
#include "mbmc.h"
#include "crit.h"
#include "sdspi.h"
#include "mbmc_msg.h"
#include "hwconf.h"
#include "power.h"
#include "model.h"
#include "mbmc_vector.h"
#include "mbmc_shared.h"
#include "daq.h"
#include "timelib.h"

void clr_lcd(void);
int8_t *ahfp(int32_t, int8_t *);
int8_t *voltfp(uint32_t, int8_t *);
int8_t *voltfps(uint32_t, int8_t *);
int8_t *voltfpi(int32_t, int8_t *);
void noload_soc(void);
void fail_safe(void);
int8_t *hms(uint32_t);
int8_t *hm(uint32_t);
float lp_filter(float, int16_t, int16_t);
int16_t sd_dump(int16_t); // send SD card data to comm1 port
int16_t W_SDC0_EEP(uint16_t); // EEPROM save routine
void putc2(uint8_t c);
void set_batt_type(void); // set the battery type
void set_tweak(void); // tweak run time parameters
void set_ganged(void); // modify ganged mode
void hold_process(void); // hold monitor progrsm
void sync_battsoc(void); // set BOC to 100% SOC
void system_data(void); // send system variables to rs-232 terminal
void system_help(void); // send system help menu to rs-232 terminal
void display_system(void); // send adc values to terminal
void mbmc_update(void); // load data into MBMC buffer
void mkbsstring(void); // create data buffer for SD card and network
uint8_t check_alarm(uint8_t, const rom int8_t*);
int32_t ABSL(int32_t);
int16_t ABSI(int16_t);
void LCD_VC_puts(uint8_t, uint8_t, uint8_t);
float update_cef(uint8_t, uint8_t);
uint32_t peukert(uint16_t, float, float, int16_t, uint8_t);
void wdttime(uint32_t);
void wdtdelay(uint32_t);
void update_hist(void);
void term_time(void);
uint16_t Volts_to_SOC(uint32_t, uint8_t);
uint16_t Get_RestSOC(uint8_t, uint8_t, blendmode_t);
void init_hist_data(void);
void ChargeRelayOn(uint8_t, uint8_t);
void ChargeRelayOff(uint8_t, uint8_t);

const rom uint32_t BVSOC_TABLE[BVSOC_SLOTS][2] = {
	11500, 5,
	11700, 10,
	11800, 20,
	12060, 25,
	12100, 30,
	12220, 40,
	12270, 45,
	12300, 50,
	12323, 53,
	12350, 55,
	12375, 57,
	12400, 60,
	12425, 63,
	12475, 67,
	12500, 70,
	12510, 72,
	12520, 75,
	12525, 80,
	12530, 85,
	12540, 90,
	12548, 92,
	12561, 93,
	12570, 95,
	12580, 97,
	12590, 100,
	13100, 90
};

// section just for the large arrays idata
#pragma	idata	bigdata
far int8_t block_buffer[SDBUFFERSIZE + SDBUFFER_EXTRA] = {0};
far int8_t bootstr2[MESG_W + 1] = {0};
uint8_t csd[SD_18] = {0}, cid[SD_18] = {0}, HCRIT[CRIT_8] = {0}, LCRIT[CRIT_8] = {0};
int8_t p1[C_TEMP16] = {0}, p2[C_TEMP16] = {0};
int8_t termstr[32] = {0}, CCM = 'O';
volatile struct celltype cell[DATA_SLOTS] = {0}, *mbmccell; // data array for each battery cell
far int8_t f1[C_TEMP7] = {0}, f2[C_TEMP7] = {0}, f3[C_TEMP7] = {0}, f4[C_TEMP7] = {0};
int8_t p3[C_TEMP16] = {0};
volatile struct buttype buth[BUTH_SLOTS] = {0}; // data array for each battery history data / hour
volatile struct almbuffertype alarm_buffer[MAXALM] = {0};
float smooth[LPCHANC] = {0}, esr_delta;
volatile struct histtype hist[DATA_SLOTS] = {0};
struct lcdb ds[VS_SLOTS] = "Fred Brooks"; //  LCD display string, name
struct battmodeltype bmt[HISTBATTNUM] = {0};

#pragma idata gpr13
far int8_t hms_string[16] = {0};
volatile int16_t venttimer = VENTTIME, loggertime = LOGGERTIME;
int16_t a50 = 0, a300 = 0, a50c = 0, therm = 0, worktick = 0, cef = 0, cef_calc = 0, cef_save = 0, sdret = 0, sderr = 0;

volatile struct P_data P = {TRUE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, TRUE, TRUE,
	FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

// BCHECK = TRUE, TIMERFLAG = FALSE,  PRIPOWEROK = TRUE,FORCEOUT = FALSE, ,WORKERFLAG = FALSE CHARGEROVERRIDE = FALSE, FAILSAFE = FALSE,
//  MORNING_HELP = FALSE, SYSTEM_STABLE = FALSE, HOLD_PROC = FALSE, POWER_UNSTABLE = FALSE,  SET_BATT = FALSE,, BLANK_LCD = FALSE
// STATIC_SOC = TRUE,  SET_CEF = TRUE, D_UPDATE = TRUE, GLITCH_CHECK = TRUE,
//         FORCEDAY = FALSE, COOLING = FALSE,
//	UPDATE_EEP = FALSE, RESET_ZEROS = FALSE,
volatile uint8_t
SYS_DATA = FALSE, MOD_DATA = FALSE, SYS_HELP = FALSE, SET_ADC = FALSE,
	WDT_TO = FALSE, EEP_ER = FALSE, PERKOSW_R = FALSE, TWEAK = FALSE, GANGED_MODE = FALSE, XON_XOFF = FALSE, DISPLAY_MODE = FALSE, GANG_OVERRIDE = FALSE;

volatile uint8_t battnum = MAXBATT, critc_level = 0, keynum = 0, b_read = 0,
	c2raw = 0, glitch_count = 0, fast_ticks = FT20, real_ticks = 0, cdelay = 0, SIM_MODE = RUNSIM, SIM_FLAG = 0;

volatile struct almtype alarm_codes = {FALSE, 0};
volatile uint8_t almctr = 0;
union Timers hirez_0 = 0, hirez_1 = 0;
volatile uint32_t display_count = 0,
	status_count = 0, cctimer = CCLEDTIME,
	dayclockup = 0, dayclockdown = 0, worker_count = 0, critc_count = 0, d_on = 0, d_off = 0,
	c_on = 0, c_off = 0, dayclocklocal = 0;

#pragma idata gpr3
volatile uint8_t HOST_BUSY = FALSE, HOST_COMM = FALSE;
volatile SDCARD_TYPE SDC0 = {MAGIC, 0, FALSE, FALSE, 2, 2}; // active program SD buffer
volatile SDDUMP_TYPE SDD0 = {FALSE, ' ', 0};
volatile struct ccledtype ccled_flag = {OFF, 0, CCLEDBLINK, 0, FALSE};
int8_t sign = ' ';
float lp_speed = 0.0, lp_x = 0.0;
volatile struct mbmclinktype LINK = {TRUE, TRUE};

#pragma idata gpr15
struct R_data R = {0};
struct C_data C = {0};
volatile struct B_data B = {0};
volatile struct V_data V = {0};
const rom int8_t *build_date = __DATE__, *build_time = __TIME__;
VOLUME_INFO_TYPE MMC_volume_Info = {0}, *vinf = 0;
volatile uint16_t solarup_delay = 0;
uint16_t zero_ref = 0, max_eeprom_data = 1024;
volatile uint32_t utctime = 0, localtime = 0;

volatile union {
	uint32_t netdword;
	uint8_t netdbyte[4];
} netd;
volatile int32_t time_skew_base = 0, time_skew = 0;
volatile uint8_t dsi = 0; //      LCD display string index to console 0

#pragma idata gpr4
volatile struct mbmcdata MBMC = {0};
volatile struct mbmcflagtype mbmcflag = {0}, mbmc_dumpflag = {0};
float t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0, t5 = 0.0, t6 = 0.0, t7 = 0.0, t_time = 0.0;

#pragma idata gpr0
volatile int16_t tx_tmp = 0, rx_tmp = 0;
volatile uint32_t mbmc_cmd_reply = 0;
float voltfrak = 0.0;
float ahfrak = 0.0;
volatile int32_t ahi_tmp = 0, aho_tmp = 0, ahop_tmp = 0, absorp_current = 0, end_amps = 0;
uint8_t model_update = MODEL_UPDATE;
int32_t current_t = 0, currentin_t = 0, currentcharger_t = 0;
uint32_t chrg_v = 0;
volatile struct battbufftype battbuffer = {0}, batttype = {0};
volatile uint8_t idleflag = FALSE;
volatile int16_t CCEFF = 99, CCEFF_DIFF = 0; // 99% of max power
int32_t iw = 0, ip = 0;
struct SDCARD sdc0b1 = {0}; // SD buffer for loading and dumping SD data
volatile uint8_t B0 = B0B, B1 = B1B, B2 = B2B, B3 = B3B, B4 = B4B, B_GANGED = FALSE;

#pragma idata
volatile uint8_t UTC_flag = 0, UTC_ok = 0, DIVERSION_set = FALSE;
volatile uint8_t *netdword_ptr = 0, netdword_pos = 0;
volatile struct ccstype CCS = {0};
volatile uint16_t hirez_count[7] = {0, 0, 0, 0, 0, 0, 0};
/* ADC voltage/current default calibration values , adjusted with D command */
// adc_cal[10-13]				current sensors zero offset stored in eeprom 10=a50, 11=a50c, 12=a300, 13=future
uint8_t adc_cal[] = {125, 152, 106, 199, 146, 114, 171, ADC_NULL, ADC_NULL, ADC_NULL, 123, ADC_NULL, 118, ADC_NULL, 0};
// voltage/current value calibration: 0=system voltage, 1=CC voltage, 2=PV current, 3=PV voltage, 4=B1, 5=Battery current, 6=B2
uint8_t CRITC = 0, BOOT_STATUS = 0;
int8_t soc_method[DATA_SLOTS] = {'U', 'U', 'U', 'S', 'S'};
struct tm local_tm;
uint32_t vsoc[DATA_SLOTS] = {0}; // store adjusted battery voltage used to calc SOC
volatile union Alarm alarms;

volatile enum ccmode_t {
	IDLE_M, BULK_M, FLOAT_M, TEST_M, ABSORP_M, FLOAT_W
} CCMODE;

volatile enum mbmode_t {
	IDLE_M, CHARGE_M, FLOAT_M, TEST_M
} BMMODE;

volatile enum answer_t {
	WAIT_M, YES_M, NO_M
} YNKEY;

blendmode_t BLENDMODE = NO_BLEND;

/* ISR vectors */
#pragma code tick_interrupt = HIGH_VECTOR

void tick_int(void)
{
	_asm goto tick_handler _endasm // high
}
#pragma code

#pragma code work_interrupt = LOW_VECTOR

void work_int(void)
{
	_asm goto work_handler _endasm // low
}
#pragma code

/* Current is in 0.1A units */
uint32_t peukert(uint16_t brate, float bcurrent, float peukert, int16_t bsoc, uint8_t battn)
{
	if (battn > HISTBATTNUM) return 1.25;
	t1 = (float) bcurrent; // Load on battery in 0.1A units
	t1 /= 10.0; // convert back to A
	if (t1 < 1.0) t1 = 1.0; // inverter current floor is 1.0 amp
	t2 = (float) brate; // Battery capacity in 1.0A units
	t3 = (float) ((float) bsoc / 100.0); // State of Charge
	if (t3 > 0.0) t2 = t2 * t3; // only decrease battery Ah
	if (t2 < 1.0) t2 = 1.0; // Ah floor is 1.0
	t4 = t2 * (float) (pow((t2 / (float) 20.0), ((float) peukert - (float) 1.0)));
	t_time = pow((t2 / (float) 20.0), peukert); // factor at 20h rate
	t5 = pow(t1, peukert); // factor at load current rate
	t6 = t4 / t5; // runtime in hours at the current draw
	if (t6 > MAXRUNTIME) t6 = MAXRUNTIME; // max time is 4 days in hours
	if (t6 < MINRUNTIME) t6 = MINRUNTIME;
	t7 = t4 / t_time; // time at fixed 20h rate
	s_crit(HL);
	hist[battn].peukert_adj = t7 / t6; // Peukert factor to resize Ah usage, t7=runtime at the 20h current rate/t6=runtime at the inverter load current value
	if (hist[battn].peukert_adj < Perk_ADJ_FL)
		hist[battn].peukert_adj = Perk_ADJ_FL; // limit how LOW
	if (hist[battn].peukert_adj > Perk_ADJ_FH)
		hist[battn].peukert_adj = Perk_ADJ_FH; // limit how HIGH
	e_crit();
	t6 = lp_filter(t6, LP_PEUKERT + battn, FALSE); // digital filter for each battn
	t6 = t6 * 3600.0; // convert to seconds for runtime at current discharge rate
	return(uint32_t) t6;
}

void LCD_VC_puts(uint8_t console, uint8_t line, uint8_t COPY) // VCx,DSx, [TRUE..FALSE} copy data from bootstr2 string
{ // into the LCD display buffer
	static uint8_t ib = 0;

	if (COPY) {
		ib = console + line; // set to string index to store data in LCD message array ds[x].b
		strncpypgm2ram(ds[ib].b, "                        ", LCD_W); // write 20 space chars
		strncpy(ds[ib].b, bootstr2, LCD_W); // move data from static buffer in lcd message array
		ds[ib].b[LCD_W] = NULL0; // make sure we have a string terminator
	}

	switch (line) {
	case DS0:
		SetDDRamAddr(LL1); // move to  line
		break;
	case DS1:
		SetDDRamAddr(LL2); // move to  line
		break;
	case DS2:
		SetDDRamAddr(LL3); // move to  line
		break;
	case DS3:
		SetDDRamAddr(LL4); // move to  line
		break;
	default:
		SetDDRamAddr(LL1); // move to  line 1 of out of range
		break;
	}
	ib = dsi + line; // set to string index to display on LCD, dsi is the current VC being displayed

	if (!P.D_UPDATE)
		return;
	if (P.BLANK_LCD)
		clr_lcd();
	while (BusyXLCD());
	putsXLCD(ds[ib].b);
	while (BusyXLCD());
}

void update_hist(void) // compute the runtime data from current data
{
	static uint8_t z = 0;
	static float fcurrent = 0.0;
	static uint32_t ttg_t = 0;

	if (!P.SYSTEM_STABLE) return;
	noload_soc();
	check_alarm(CCS.boc, " update_hist1 ");

	for (z = 1; z <= HISTBATTNUM; z++) { // find a approx run-time at current load on each cell
		if (cell[z].current > 0) {
			fcurrent = (float) cell[z].current + (float) DCURRENT; // battery is supplying current
		} else {
			fcurrent = (float) DCURRENT; // default current for controller power
		}

		ttg_t = peukert((uint16_t) hist[z].rate, fcurrent, hist[z].peukert, hist[z].bsoc, z); // Reduce the total Ah by SOC
		hist[z].ttg = (int32_t) ((float) ttg_t * DF);
		if (hist[z].ahop > (hist[z].ah * 1000l)) hist[z].ahop = hist[z].ah * 1000l; // limit the max ahop to max battery capacity
	}

	voltfp(R.primarypower[B1], f1);
	voltfp(R.primarypower[B2], f2);
	ahfp(hist[B1].h[0], f3); // display pf amps
	sprintf(bootstr2, "%5s %5s %u %s %i     ", f1, hm(hist[B1].ttg), hist[B1].bsoc, f3, cell[B1].online); // B1 status
	LCD_VC_puts(VC0, DS2, YES);
	ahfp(hist[B2].h[0], f3); // display pf amps
	if (!B_GANGED) {
		sprintf(bootstr2, "%5s %5s %u %s %i     ", f2, hm(hist[B2].ttg), hist[B2].bsoc, f3, cell[B2].online); // B2 status
	} else {
		sprintf(bootstr2, "%5s B2&B1 GANGED           ", f2); // B2 status
	}
	LCD_VC_puts(VC0, DS3, YES);

	// check FLAGS from the tick ISR and run subroutine if needed
	if (SDD0.dumping) { // dump history data from the SD Card
		sd_dump(0);
	}

	if (P.UPDATE_EEP) { // save system date to internal eeprom
		W_SDC0_EEP(SDC0EEP); // mirror SDC0 data to eep at address
		P.UPDATE_EEP = FALSE;
	}
	if (P.RESET_ZEROS) { // zero the current sensors
		zero_amploc();
		P.RESET_ZEROS = FALSE;
	}
	if (SET_ADC) { // Set gains for ADC channel calibration
		set_adc_gain();
		SET_ADC = FALSE;
	}
	if (TWEAK) { // Adjust runtime data
		set_tweak();
		TWEAK = FALSE;
	}
	if (GANGED_MODE) { // Adjust Ganged mode
		set_ganged();
		GANGED_MODE = FALSE;
	}
	if (P.SET_BATT) { // Set battery size types
		set_batt_type();
		P.SET_BATT = FALSE;
	}
	if (P.HOLD_PROC) { // Hold processing, mainly used during a battery EQ cycle.
		hold_process();
		P.HOLD_PROC = FALSE;
	}
	if (P.SETBATT_SOC) { // Set SOC/BSOC to battery being charged to 100%
		sync_battsoc();
		P.SETBATT_SOC = FALSE;
	}
	if (SYS_DATA) { // display System data on rs-232 port
		system_data();
		SYS_DATA = FALSE;
	}
	if (MOD_DATA) { // display System data on rs-232 port
		model_data();
		MOD_DATA = FALSE;
	}
	if (SYS_HELP) { // Command Help message
		system_help();
		SYS_HELP = FALSE;
	}
}

/* ISR code moved to mbmc_vector.c */


void wdtdelay(uint32_t delay)
{
	static uint32_t dcount;

	for (dcount = 0; dcount <= delay; dcount++) { // delay a bit
		Nop();
		ClrWdt(); // reset the WDT timer
	};
}

void wdttime(uint32_t delay) // delay = ~ .1 seconds
{
	static uint32_t dcount, timetemp, clocks_hz;

	s_crit(HL);
	dcount = V.clock50;
	e_crit();
	clocks_hz = dcount + delay + delay; // number of low int16_t clock ticks per second is about 20

	do { // wait until delay
		s_crit(HL);
		timetemp = V.clock50;
		e_crit();
		ClrWdt();
		LCD_VC_puts(dsi, DS0, NO);
		LCD_VC_puts(dsi, DS1, NO);
		LCD_VC_puts(dsi, DS2, NO);
		LCD_VC_puts(dsi, DS3, NO);
		idle_loop();
	} while (timetemp < clocks_hz);
}

void DelayFor18TCY(void)
{
	static uint8_t n;
	for (n = 0; n < 24; n++) Nop(); // works at 200
}

//------------------------------------------

void DelayPORXLCD(void) // works with 15
{
	Delay10KTCYx(15); // Delay of 15ms
	return;
}

//------------------------------------------

void DelayXLCD(void) // works with 5
{
	Delay10KTCYx(5); // Delay of 5ms
	return;
}

void putc2(uint8_t c)
{
	while (Busy2USART()) {
	}; // wait until the usart is clear
	putc2USART(c);
}

void start_delay(void)
{
	wdttime(BATRUNF); // wait for .5 seconds.
}

void clr_lcd()
{
	if (!P.D_UPDATE) return;
	while (BusyXLCD());
}

/*	lp_filters
	0	PWM
	1	CCEFF
	2	solar buffer (overvolt errors)
	3	current
	4	currentin
	5	currentcharger
	6	t6 peukert B0
	7	t6 peukert B1
	8	t6 peukert B2
 *	9	PV inputvoltage
 */
float lp_filter(float new, int16_t bn, int16_t slow) // low pass filter, slow rate of change for new, LPCHANC channels, slow/fast select (-1) to zero channel
{
	// smooth,lp_speed,lp_x is a udata global array to save stack space

	if ((bn >= LPCHANC) || (bn < 0)) // end of the filter array so just return passed value
		return new;
	if (slow) {
		lp_speed = 0.06;
	} else {
		lp_speed = 0.125;
	}
	lp_x = ((smooth[bn]*100.0) + (((new * 100.0)-(smooth[bn]*100.0)) * lp_speed)) / 100.0;
	smooth[bn] = lp_x;
	if (slow == (-1)) { // reset and return zero
		lp_x = 0.0;
		smooth[bn] = 0.0;
	}
	return lp_x;
}

void term_time(void) // sent internal time to rs-232 terminal
{

	ClrWdt(); // reset the WDT timer
	sprintf(termstr, " CT-%s", hms(V.timerint_count));
	puts2USART(termstr);
	sprintf(termstr, " CU-%s", hms(dayclockup));
	puts2USART(termstr);
	sprintf(termstr, " CD-%s", hms(dayclockdown));
	puts2USART(termstr);
}

void hold_process(void) // hold the monitor in the current status until released.
{
	term_time();
	putrs2USART(hold0);
	YNKEY = WAIT_M;
	while (YNKEY == WAIT_M) {
		wdtdelay(10);
		//		ADC_read();
		mkbsstring();
		idle_loop();
		noload_soc();
	}
	if (YNKEY == NO_M) {
		term_time();
		putrs2USART(hold1);
		return;
	}
	term_time();
	putrs2USART(hold1);
}

void system_data(void) // display system data on terminal
{
	static uint8_t z;
	static int32_t q1, q2;

	ClrWdt(); // reset the WDT timer
	pick_batt(0, 0);
	sprintf(bootstr2, "\r\n");
	puts2USART(bootstr2);
	term_time();
	if (SIM_MODE) {
		putrs2USART(SIMULA);
	}
	putrs2USART(" FW ");
	strcpypgm2ram(bootstr2, build_time);
	puts2USART(bootstr2);
	putrs2USART(" ");
	strcpypgm2ram(bootstr2, build_date);
	puts2USART(bootstr2);
	strcpypgm2ram(bootstr2, MBMC_VERSION);
	puts2USART(bootstr2);
	offtime(&local_tm, utctime, 0);
	asctime(&local_tm, bootstr2, 0);
	puts2USART(bootstr2);
	sprintf(bootstr2,
		"GMT, Boot Code %i\r\n Controller Status:\r\n SD time %lu, SD records %lu, SD status %d:%d, Power status 1=OK %u, Config DIPSW %u%u%u%u%u%u%u%u lsb, Temp Raw %i, Temp Sensor %lu, Temp Offset %li, Ah Temp Comp %i",
		(int16_t) BOOT_STATUS, SDC0.timekeep, SDC0.sdpos, sdret, sderr, P.PRIPOWEROK, DIPSW8, DIPSW7, DIPSW6, DIPSW5, DIPSW4, DIPSW3, DIPSW2, DIPSW1, therm, R.thermo_batt, R.thermo_batt - Temp_ZERO, C.temp_drate);
	puts2USART(bootstr2);
	sprintf(bootstr2,
		"\r\n UTC counter %lu, Time Skew %li, Highint %lu, Lowint %lu, Timerint %lu, Workerint %lu, \r\n Com1rx INT %lu, Com1tx INT %lu, Com2int %lu, Bint %lu, PWMint %lu, Eint %lu, Aint %lu, Lowclocks %lu, Lowruns/S %lu,\r\n",
		utctime, time_skew, V.highint_count, V.lowint_count, V.timerint_count, worker_count, V.c1rx_int, V.c1tx_int, V.c2_int, V.buttonint_count, V.pwm4int_count, V.eeprom_count, V.adc_count, V.clock50, V.clock50 / V.timerint_count);
	puts2USART(bootstr2);
	sprintf(bootstr2, " %c,%c,%c,%c, CHARGER %u, H%u,L%u,B%u CRITC levels %u, CRITIC counts %lu, CCLED counts %u, ADC Zero Offset %u\r\n",
		cell[B1].id, cell[B2].id, cell[B3].id, cell[B4].id, CHARGERL, hirez_count[0], hirez_count[1], hirez_count[4], critc_level, critc_count, ccled_flag.ticks, zero_ref);
	puts2USART(bootstr2);
	sprintf(bootstr2, " CCS status: pick %u, boi %u, boc %u, alert %u, bn %u : MBMC network  %u, MBMC Data Bytes %lu, Tx CPS: %li, Rx CPS: %li",
		CCS.pick, CCS.boi, CCS.boc, CCS.alert, CCS.bn, mbmcflag.cmd_timeout ? 0 : 1, V.mbmcdata_count, LINK.tx_cps, LINK.rx_cps);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\r\n System Status:\r\n PV Voltage %lumV, Charging Voltage %lumV, Controller Voltage %lumV, Charge Cycle Time Left %s, Absorp Current %li00mA, End-Amps %li00mA",
		R.inputvoltage, R.ccvoltage, R.systemvoltage, hm(B.charge_time_left), ABSL(absorp_current), end_amps);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\r\n PV Current sensor %li00mA, Inverter Battery Current sensor %li00mA, Inverter Load Current %li00mA, Current Power IN %liW, OUT %liW\r\n AC PWR Inverter %i, Utility %i, Glitch Count %i: ",
		R.currentin, R.current, C.currentload, (R.currentin * R.inputvoltage) / 10000, (R.primarypower[CCS.boi] * C.currentload) / 10000, AC_OFF_I, AC_OFF_U, glitch_count);
	puts2USART(bootstr2);
	if (AC_OFF_U || AC_OFF_I) {
		if (AC_OFF_I) putrs2USART(" \x1b[7m Inverter Power is OFF \x1b[0m,"); // ANSI escape codes (REVERSE)
		if (AC_OFF_U) putrs2USART(" \x1b[7m Utility  Power is OFF \x1b[0m,");
	}
	if (DIPSW3) putrs2USART(" Inverter Battery 1 only: DIPSW3,");
	if (B_GANGED) putrs2USART(" \x1b[7mStrings 1&2 are GANGED\x1b[0m,");
	if (!DIPSW7) putrs2USART(" Power Diversion enabled: DIPSW7,");
	if (DIVERSION) {
		sprintf(bootstr2, " Diversion Status Off: PWM %i%%\r\n Todays Power Q level: %i, Yesterdays Power Q level: %i", (int16_t) MBMC.diversion.power,
			(int16_t) B.today, (int16_t) B.yesterday);
	} else {
		sprintf(bootstr2, " \x1b[7mDiversion Status On\x1b[0m: PWM %i%%\r\n Todays Power Q level: %i, Yesterdays Power Q level: %i", (int16_t) MBMC.diversion.power,
			(int16_t) B.today, (int16_t) B.yesterday);
	}
	puts2USART(bootstr2);
	sprintf(bootstr2,
		"\r\n Total Charger Energy %liWh, Todays Charger energy %liWh, Prev Charger Energy %liWh, Diversion Energy: Total %liWh, Todays %liWh",
		SDC0.harvest.c_total / 1000, SDC0.harvest.charger / 1000, SDC0.harvest.prev_charger / 1000, SDC0.harvest.diversion / 1000, B.diversion / 1000);
	puts2USART(bootstr2);
	ClrWdt(); // reset the WDT timer
	sprintf(bootstr2,
		"\r\n Total PV Energy %liWh, Todays PV energy %liWh, Prev PV Energy %liWh, Total Usage %liWh, Todays Usage %liWh, Dayclock %u:",
		SDC0.harvest.e_total / 1000, SDC0.harvest.energy / 1000, SDC0.harvest.prev_energy / 1000, SDC0.harvest.u_total / 1000, SDC0.harvest.usage / 1000, SDC0.DAYCLOCK);
	puts2USART(bootstr2);
	q1 = (hist[B1].kwo * 100) / hist[B1].kwi;
	if (B_GANGED) {
		q2 = 0;
	} else {
		q2 = (hist[B2].kwo * 100) / hist[B2].kwi;
	}
	sprintf(bootstr2,
		"\r\n Battery Status:\r\n Battery 1 Voltage %lumV, Current %li00mA, Power %liW, Quality %li : Battery 2 Voltage %lumV, Current %li00mA, Power %liW, Quality %li, Water %s,",
		R.primarypower[B1], cell[B1].current, ((int32_t) R.primarypower[B1] * (int32_t) cell[B1].current) / 10000l, q1,
		R.primarypower[B2], cell[B2].current, ((int32_t) R.primarypower[B2] * (int32_t) cell[B2].current) / 10000l, q2,
		hm(B.watercounter - B.watercounter_prev));
	puts2USART(bootstr2);
	putrs2USART(BATTERY_CHANGE);
	ClrWdt(); // reset the WDT timer

	for (z = 1; z <= battnum; z++) { // create
		if ((z == B2) && B_GANGED) {
			sprintf(bootstr2, "%2i,  \x1b[7mGANGED to B1\x1b[0m \n\r", z);
		} else {
			voltfp((int32_t) (hist[z].peukert_adj * (float) 1000.0), f1);
			sprintf(bootstr2,
				"%2i,%i%i,%6li,%6li,%6li,%5i,%7li,%7li,%7li,%7li,%7li",
				z, cell[z].cconline, cell[z].online, cell[z].noload,
				cell[z].voltage, vsoc[z], hist[z].rate, hist[z].ahir, hist[z].ahi, hist[z].aho, hist[z].kwi / 10000l, hist[z].kwo / 10000l);
			puts2USART(bootstr2);
			sprintf(bootstr2,
				",%4d,%4d%c,%4d,%8li,%6lu,%6u,%6u  Pk Adj %6s, Ahop %6li, Rest Rate %6u, CYCLES %s\n\r",
				hist[z].udod, hist[z].bsoc, soc_method[z], B.r_soc[z], hist[z].ttg,
				(uint32_t) cell[z].weight, hist[z].esr, hist[z].h[10], f1, hist[z].ahop, hist[z].rest_rate, hm(cell[z].cycles));
		}
		puts2USART(bootstr2);
		ClrWdt(); // reset the WDT timer
	}
	putrs2USART(battheader0);

	/*		hist[x].h[x]
	 *		h0	Peukert Factor adjusted Ah usage this cycle 			MUST BE INTERGER variable type!
	 *		h1	Lowest discharge ever,
	 *		h2	current lowest discharge,
	 *		h3	avg discharge
	 *		h4	Number of full charge cycles,
	 *		h5	Number of full discharge cycles
	 *		h6	Real Ah usage this cycle 					MUST BE INTERGER variable type!
	 *		h7	Min Batt Voltage
	 *		h8	Max Batt Voltage
	 *		h9	Total KWH out
	 *		h10	Lowest ESR Post
	 *		h11	Total charge cycles
	 *		h12	Total kWH in
	 */

	for (z = 1; z <= battnum; z++) { // create
		if ((z == B2) && B_GANGED) {
			sprintf(bootstr2, " B%i, \x1b[7mGANGED to B1\x1b[0m \n\r", z);
		} else {
			cef = (int16_t) ((float) hist[z].cef * (float) 100.0);
			cef_calc = (int16_t) ((float) hist[z].cef_calc * (float) 100.0);
			cef_save = (int16_t) ((float) hist[z].cef_save * (float) 100.0);
			sprintf(bootstr2,
				" B%i,%6i,%6i,%6i,%6i,%6i,%6i,%6i,%6i,%6i,%6i,%6i,%6i,",
				z, hist[z].h[1], hist[z].h[2], hist[z].h[3], hist[z].h[11], hist[z].h[4], hist[z].h[5], hist[z].h[0], hist[z].h[7], hist[z].h[8], hist[z].h[6], hist[z].h[12], hist[z].h[9]);
			puts2USART(bootstr2);

			if (z == CCS.boc) {
				sprintf(bootstr2,
					"%6i,%6i,%6i,%6i,%6li,%7li,%7li,%6i,%7limAh Absorp Time %s\n\r",
					cef, cef_calc, cef_save, B.start_ahu, hist[z].ahir, B.start_ahi, B.start_aho, B.cef_raw, B.absorp_ahi, hm(B.absorp_time));
			} else {
				sprintf(bootstr2,
					"%6i,%6i,%6i,%6i,%6li,%7li,%7li,%6i\n\r",
					cef, cef_calc, cef_save, B.start_ahu, hist[z].ahir, B.start_ahi, B.start_aho, B.cef_raw);
			}
		}
		puts2USART(bootstr2);

		ClrWdt(); // reset the WDT timer
	}
	putrs2USART(battheader1);
	putrs2USART(battheader2);
}

void system_help(void) // display system help on terminal
{
	putrs2USART(keycmds0);
	putrs2USART(keycmds1);
	putrs2USART(keycmds2);
}

void sync_battsoc(void) // set battery SOC to 100% when C40 is in float
{
	putrs2USART(sync0);
	YNKEY = WAIT_M;
	while (YNKEY == WAIT_M) {
		wdtdelay(10);
		idle_loop();
	}
	if (YNKEY == NO_M) {
		putrs2USART(sync2);
		P.SYNCSOC = FALSE;
		return;
	}
	P.SYNCSOC = TRUE;
	putrs2USART(sync1);
}

void display_system(void)
{
	sprintf(bootstr2, "\n\r 0: %u,%lu Controller voltage.", adc_cal[0], R.systemvoltage);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 1: %u,%lu PV Charge Controller output voltage.", adc_cal[1], R.ccvoltage);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 2: %u,%li PV input current. Raw ADC %i", adc_cal[2], R.currentin, a50);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 3: %u,%lu PV input voltage.", adc_cal[3], R.inputvoltage);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 4: %u,%lu Battery 1 voltage.", adc_cal[4], R.primarypower[B1]);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 5: %u,%li Inverter Battery current. Raw ADC %i", adc_cal[5], R.current, a300);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 6: %u,%lu Battery 2 voltage.", adc_cal[6], R.primarypower[B2]);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 7: %u,%lu Not Used.", adc_cal[7], 0);
	puts2USART(bootstr2);
	sprintf(bootstr2, "\n\r 8: %u,%li Mains charger current. Raw ADC %i", adc_cal[8], R.currentcharger, a50c);
	puts2USART(bootstr2);
}

void set_batt_type(void) // set the battery type LMS in the EEPROM
{
	if (c2raw == NULL0) {
		batttype.busy = FALSE;
		return;
	}
	s_crit(HL);
	cell[batttype.position].id = c2raw; // set battery type eeprom data S gell,M agm, L lead-acid
	e_crit();
	write_data_eeprom(c2raw, 5, batttype.position, 0);                                                                                                                                                                                                                                                                                 \
   	sprintf(bootstr2, "\n\r Battery type %c set in position %lu. \n\r", c2raw, batttype.position);
	puts2USART(bootstr2);
	c2raw = 0;
	batttype.busy = FALSE;
}

void set_ganged(void) // modify the GANGED MODE
{
	GANG_OVERRIDE = TRUE;
	B_GANGED != B_GANGED;
	if (B_GANGED) {
		sprintf(bootstr2, "\r\n Configured batteries in Ganged mode B1 and B2 in parallel.\r\n");
		puts2USART(bootstr2);
	} else {
		sprintf(bootstr2, "\r\n Configured batteries in normal mode B1 and B2 separated.\r\n");
		puts2USART(bootstr2);
	}
	if (B_GANGED) {
		hist[B1].ah = B12_GANGEDAH;
	} else {
		hist[B1].ah = B1AH; // config battery cap in Ah, 1.0 A units
	}
}

void set_tweak(void) // modify active charge parameters
{
	int16_t t_value, t_boc, t_more = 0;
	int32_t t_temp, t_tempo;
	uint32_t t_keytime, t_keytime_next;
	uint8_t t_index, t_prev = 0, t_fast = FALSE;

	if (batttype.busy) {
		t_boc = (int16_t) batttype.position;
		batttype.good = FALSE;
		batttype.busy = FALSE;
		batttype.flag = FALSE;
		batttype.position = 0;
		batttype.length = 0;
	} else {
		t_boc = CCS.boc;
	}
	sprintf(bootstr2, "\r\n Tweaking Battery %i.\r\n", t_boc);
	puts2USART(bootstr2);
	c2raw = 0;
	YNKEY = WAIT_M;
	keynum = 0;
	putrs2USART(tweak0);
	while ((YNKEY == WAIT_M) && (keynum == NULL0)) {
		idle_loop();
	}
	if (YNKEY != WAIT_M) {
		putrs2USART(tweak2);
		return;
	}

	t_index = (uint8_t) keynum - (uint8_t) 0x30; // convert to binary number
	if (t_index > MAX_TWEAK_CMD) {
		putrs2USART(tweak2);
		return;
	}

	YNKEY = WAIT_M;
	t_value = 0;
	t_keytime_next = 0;
	t_prev = 0xff;

	while (YNKEY == WAIT_M) { // display current status of parameter selected
		switch (t_index) {
		case 1:
			t_tempo = hist[t_boc].ahir;
			sprintf(bootstr2, tweak_t1);
			break;
		case 2:
			t_tempo = hist[t_boc].ahi;
			sprintf(bootstr2, tweak_t2);
			break;
		case 3:
			t_tempo = hist[t_boc].aho;
			sprintf(bootstr2, tweak_t3);
			break;
		case 4:
			t_tempo = hist[t_boc].ahop;
			sprintf(bootstr2, tweak_t4);
			break;
		default:
			t_tempo = 0;
			sprintf(bootstr2, tweak_tw);
			break;
		}
		sprintf(bootstr2, " Selected parameter #%u for adjustment on Battery %i. %s = %li\r\n", t_index, t_boc, bootstr2, t_tempo);
		puts2USART(bootstr2);

		if ((t_keytime_next < 3)) { // 10 fast key presses switches to high value mode
			if (c2raw == t_prev) t_more++;
			if (t_more > 9) {
				t_fast = TRUE;
				putrs2USART(tweak5);
			}
		} else {
			t_fast = FALSE;
			t_more = 0;
			putrs2USART(tweak3);
		}


		YNKEY = WAIT_M;
		c2raw = 0;
		s_crit(HL);
		t_keytime = V.timerint_count; // waiting for keypress start time
		e_crit();
		while (c2raw == NULL0) {
			idle_loop();
		}
		s_crit(HL);
		t_keytime_next = V.timerint_count - t_keytime; // time it took to press key (t_keytime_next-t_keytime)
		e_crit();

		if (YNKEY == NO_M) {
			putrs2USART(tweak2);
			return;
		}
		if ((c2raw == 'Q') || (c2raw == 'q')) {
			putrs2USART(tweak2);
			return;
		}



		if (t_fast) {
			if (c2raw == 'M') t_value += 1000;
			if (c2raw == 'L') t_value += -1000;
			if (c2raw == 'm') t_value += 50;
			if (c2raw == 'l') t_value += -50;
		} else {
			if (c2raw == 'M') t_value += 100;
			if (c2raw == 'L') t_value += -100;
			if (c2raw == 'm') t_value += 5;
			if (c2raw == 'l') t_value += -5;
		}
		t_prev = c2raw;
		switch (t_index) { // make temp value with updates
		case 1:
			t_temp = hist[t_boc].ahir + t_value;
			break;
		case 2:
			t_temp = hist[t_boc].ahi + t_value;
			break;
		case 3:
			t_temp = hist[t_boc].aho + t_value;
			break;
		case 4:
			t_temp = hist[t_boc].ahop + t_value;
			break;
		default:
			t_temp = 0;
			break;
		}
		sprintf(bootstr2, " Adjustment value %i, Parameter %s will be %li when saved.\r\n", t_value, bootstr2, t_temp);
		puts2USART(bootstr2);
	}

	putrs2USART(tweak4);
	switch (t_index) { // save updated value
	case 1:
		hist[t_boc].ahir += t_value;
		break;
	case 2:
		hist[t_boc].ahi += t_value;
		break;
	case 3:
		hist[t_boc].aho += t_value;
		break;
	case 4:
		hist[t_boc].ahop += t_value;
		break;
	default:
		break;
	}
	update_hist();
	putrs2USART(tweak1);
}

void mbmc_update(void)
{
	MBMC.thermo_batt = R.thermo_batt;
	MBMC.cef_boc = (uint32_t) (hist[CCS.boc].cef * 100);

	MBMC.PRIPOWEROK = P.PRIPOWEROK;
	MBMC.DIPSW = DIPSW;
	MBMC.UTC = localtime; // change to localtime

	MBMC.pick = CCS.pick;
	MBMC.boi = CCS.boi;
	MBMC.boc = CCS.boc;
	MBMC.alert = CCS.alert;
	MBMC.bn = CCS.bn;

	//	MBMC.CHARGER_B = CHARGERL; //FIXME waste of 32 bits
	//	MBMC.DIVERSION_B = DIVERSION; //FIXME waste of 32 bits
	MBMC.diversion.flag = 0; // clear the status flag
	MBMC.diversion.flag |= DIVERSION; // bit 0
	MBMC.diversion.flag |= (CHARGERL << 1); // bit 1
	MBMC.diversion.alarm = B.d_code;

	MBMC.systemvoltage = R.systemvoltage;
	MBMC.ccvoltage = R.ccvoltage;
	MBMC.inputvoltage = R.inputvoltage;
	MBMC.primarypower_B1 = R.primarypower[B1];
	MBMC.primarypower_B2 = R.primarypower[B2];
	MBMC.currentin = R.currentin;
	MBMC.current = R.current;
	MBMC.currentload = C.currentload;
	MBMC.current_B1 = cell[B1].current;
	MBMC.current_B2 = cell[B2].current;
	MBMC.harvest = SDC0.harvest;
	MBMC.ports.NEWDATA = TRUE;
	MBMC.ports.ALARM = alarms.alarm_byte;
	MBMC.ports.RUNTIME = (uint8_t) ((int32_t) hist[CCS.boi].ttg / 3600l); // seconds to hours
	MBMC.ports.CCMODE = CCM;
}

void mkbsstring(void) // generate status report string
{
	static uint8_t j, k;
	static uint8_t z;

	ADC_read(); // always update data

	if (battbuffer.copy && P.SYSTEM_STABLE && !SDD0.dumping) { // update sd card with data after block_buffer copy is complete from isr, wait for good data
		if (SDC0.sdinit) {

			//              SD ASCII data block format
			if (!battbuffer.busy && !SDD0.dumping) {
				battbuffer.good = FALSE;
				wipe_sdbuffer();

				s_crit(HL);
				sprintf(block_buffer, sd_data_layout1,
					utctime, P.PRIPOWEROK, DIPSW, SDC0.DAYCLOCK, SDC0.sdpos, SDC0.timekeep, SDC0.time,
					SDC0.harvest.energy, SDC0.harvest.usage, SDC0.harvest.prev_energy, SDC0.harvest.prev_usage,
					SDC0.harvest.e_total, SDC0.harvest.u_total, SDC0.harvest.count, SDC0.harvest.charger,
					SDC0.harvest.c_total, SDC0.harvest.prev_charger, SDC0.harvest.diversion);
				sprintf(block_buffer + strlen(block_buffer), sd_data_layout2,
					CHARGERL, DIVERSION, (int16_t) B_GANGED,
					R.systemvoltage / 100, R.inputvoltage / 100, R.ccvoltage / 100, R.primarypower[B1] / 100,
					R.primarypower[B2] / 100, R.currentin, R.current, C.currentload,
					cell[B1].cconline, cell[B1].online, cell[B1].cycles, cell[B2].cconline, cell[B2].online,
					cell[B2].cycles, cell[B1].id, cell[B2].id, cell[B3].id, cell[B4].id,
					R.thermo_batt, (uint32_t) (hist[CCS.boc].cef * 100), (int16_t) MBMC.diversion.power);
				sprintf(block_buffer + strlen(block_buffer), sd_data_layout3,
					C.temp_drate, B.start_ahu, B.cef_raw, B.start_ahi, B.start_aho, B.absorp_ahi, B.absorp_time,
					B.charge_time_left, (int16_t) B.yesterday, (int16_t) B.today);
				if (!PIE1bits.TX1IE) {
					mbmc_update(); // push new data into the MBMC structure
				}
				e_crit();

				for (z = 1; z <= battnum; z++) { // create
					sprintf(block_buffer + strlen(block_buffer), sd_data_layout4,
						z, cell[z].noload / 100,
						cell[z].voltage / 100, hist[z].ahi / 100, hist[z].aho / 100, hist[z].ahop / 100, hist[z].kwi / 10000,
						hist[z].kwo / 10000, hist[z].udod, hist[z].ttg, hist[z].esrp, hist[z].esr, hist[z].h[9], hist[z].h[10], soc_method[z]);
				}
				strcatpgm2ram(block_buffer, sd_data_layout5); // terminate the SD ACSII data block

				battbuffer.length = strlen(block_buffer); // set total string length for copy
				if (battbuffer.length > SDBUFFERSIZE) {
					ALARMOUT = R_ON; //
					alarm_buffer[almctr].bn = battbuffer.length - SDBUFFERSIZE;
					alarm_buffer[almctr++].alm_num = 12;
					alarm_codes.alm_flag = TRUE;
					check_alarm(CCS.boc, " mkbstring1 Data Record block size too large");
					battbuffer.length = SDBUFFERSIZE; // if it's too large set it to the max string size
				}
				battbuffer.good = TRUE; // buffer is ready to copy
			}

			if (sdret = mmc_write_block(SDC0.sdpos++)) // write data log buffer block
				sderr++;
			SDC0.sdnext = SDC0.sdpos; // update last block position
			s_crit(HL);
			SDC0.time = V.timerint_count; // update current time clock
			for (j = 0; j < HISTBATTNUM; j++) {
				hist[j + 1].h[12] = (int16_t) (hist[j + 1].kwi / 10000l); // save power in int16_t from uint32_t
				hist[j + 1].h[9] = (int16_t) (hist[j + 1].kwo / 10000l);
				for (k = 0; k < HPARAM_SIZE; k++) {
					SDC0.h[j][k] = hist[j + 1].h[k]; // copy primary battery history data to SD buffer
				}
			}
			e_crit();
			if (sizeof( SDC0) > SDBUFFERSIZE) {
				ALARMOUT = R_ON; //
				alarm_buffer[almctr].bn = sizeof( SDC0) - SDBUFFERSIZE;
				alarm_buffer[almctr++].alm_num = 12;
				alarm_codes.alm_flag = TRUE;
				check_alarm(CCS.boc, " mkbstring2 SD card info block size too large");
			}
			memcpy((void *) &block_buffer[0], (void *) &SDC0, sizeof( SDC0));
			if (sdret = mmc_write_block(SDINFO)) // write SD info block
				sderr++;
			battbuffer.copy = FALSE; // data block in on SD card
		}
	}
}

int8_t* hms(uint32_t sec) // convert int32_t (seconds) to time string
{
	static uint32_t h = 0, m = 0, s = 0;

	if (sec > MAXSECONDS) sec = MAXSECONDS; // max time in seconds
	s = sec;
	h = (s / 3600);
	s = s - (h * 3600);
	m = (s / 60);
	s = s - (m * 60);
	sprintf(hms_string, "%01lu:%02lu:%02lu", h, m, s);
	return hms_string;
}

int8_t* hm(uint32_t sec) // convert int32_t (seconds) to time string
{
	static uint32_t h = 0, m = 0, s = 0;
	if (sec > MAXSECONDS) sec = MAXSECONDS; // max time in seconds
	s = sec;
	h = (s / 3600);
	s = s - (h * 3600);
	m = (s / 60);
	s = s - (m * 60);
	sprintf(hms_string, "%01lu:%02lu", h, m);
	return hms_string;
}

int16_t ABSI(int16_t i)
{
	if (i < 0)
		return -i;
	else
		return i;
}

int32_t ABSL(int32_t i)
{
	if (i < 0)
		return -i;
	else
		return i;
}

int8_t* voltfp(uint32_t millvolts, int8_t *strprt) // convert uint32_t (millvolts) to voltage string
{
	//   static int32_t iw = 0, ip = 0;
	//   static float voltfrak;
	voltfrak = (float) millvolts / 1000;
	iw = (int32_t) ((float) voltfrak);
	ip = (int32_t) ((float) voltfrak * 100) - iw * 100;
	sprintf(strprt, "%d.%02d", (int16_t) iw, (int16_t) ip);
	return strprt;
}

int8_t* voltfps(uint32_t millvolts, int8_t *strprt) // convert uint32_t (millvolts) to voltage string (short)
{
	//   int32_t iw = 0, ip = 0;
	//   float voltfrak;
	voltfrak = (float) millvolts / 1000;
	iw = (int32_t) ((float) voltfrak);
	ip = (int32_t) ((float) voltfrak * 10) - iw * 10;
	sprintf(strprt, "%d.%01d", (int16_t) iw, (int16_t) ip);
	return strprt;
}

int8_t* voltfpi(int32_t millvolts, int8_t *strprt) // convert int32_t (mill volts/watts/current) to string (integer with Kilo)
{
	//   int32_t iw = 0, ip = 0;
	//   float voltfrak;
	//   int8_t sign = ' ';

	sign = ' '; // init sign
	if (millvolts < 0)
		sign = '-';
	voltfrak = (float) millvolts / 1000;
	iw = (int32_t) ((float) voltfrak);
	ip = (int32_t) ((float) voltfrak * 10) - iw * 10;
	if (ABSL(iw) < 1500) {
		sprintf(strprt, "%c%li", sign, ABSL(iw));
	} else {
		voltfrak = voltfrak / 1000;
		iw = (int32_t) ((float) voltfrak);
		ip = (int32_t) ((float) voltfrak * 100) - iw * 100;
		sprintf(strprt, "%c%li.%02lik", sign, ABSL(iw), ABSL(ip));
	}
	return strprt;
}

int8_t* ahfp(int32_t millah, int8_t *strprt) // convert int32_t (.1 of Ah) to Ah string
{
	//   int16_t iw = 0, ip = 0;
	//   float ahfrak;
	//   int8_t sign = ' ';

	sign = ' '; // init sign
	if (millah < 0)
		sign = '-';
	ahfrak = (float) millah / 10;
	iw = (int32_t) ((float) ahfrak);
	ip = (int32_t) ((float) ahfrak * 10) - iw * 10;
	sprintf(strprt, "%c%d.%01d", sign, ABSI(iw), ABSI(ip));
	return strprt;
}

// The battery relay sends power to the controller buss, the charge connects the battery to the charging buss

void ChargeRelayOn(uint8_t bn, uint8_t FLOATSW) // switch relays for battery
{
	if (FLOATSW && (CCMODE == FLOAT_M)) {
		cell[bn].cconline = TRUE; // charging from CC
		CCOUTOPENSW = R_OFF;
		wdttime(BATRUNF);
		CHRG2 = R_ON; // charge #2 relay/on ,use as float battery
		wdttime(BATRUNF);
		switch (bn) {
		case B1B:
			CHRG1 = R_ON; // charge #1 relay/on
			if (B_GANGED) CHRG2 = R_ON;
			break;
		case B2B:
			CHRG2 = R_ON; // charge #2 relay/on
			break;
		case B3B:
			CHRG3 = R_ON; // charge #3 relay/on
			break;
		case B4B:
			CHRG4 = R_ON; // charge #4 relay/on
			break;
		default:
			CHRG1 = R_ON; // charge #1 relay/on
			break;
		}
		wdttime(BATRUNF);
		if (bn != B2)
			CHRG2 = R_OFF; // switch off transfer battery
		BMMODE = FLOAT_M;
	} else {
		cell[bn].cconline = TRUE; // charging from CC
		SOLAROFF = R_ON; // PV off before C40
		wdttime(BATRUNF);
		switch (bn) {
		case B1B:
			BAT1 = R_ON; // battery #1 relay/off
			CHRG1 = R_ON; // charge #1 relay/on
			if (B_GANGED) {
				BAT2 = R_ON; // battery #2 relay/off
				CHRG2 = R_ON; // charge #2 relay/on
			}
			break;
		case B2B:
			BAT2 = R_ON; // battery #2 relay/off
			CHRG1 = R_OFF;
			CHRG2 = R_ON; // charge #2 relay/on
			if (B_GANGED) {
				BAT1 = R_ON; // battery #1 relay/off
				CHRG1 = R_ON; // charge #1 relay/on
			}
			break;
		case B3B:
			BAT3 = R_ON; // battery #3 relay/off
			CHRG1 = R_OFF;
			CHRG3 = R_ON; // charge #3 relay/on
			break;
		case B4B:
			BAT4 = R_ON; // battery #4 relay/off
			CHRG1 = R_OFF;
			CHRG4 = R_ON; // charge #4 relay/on
			break;
		default:
			BAT1 = R_ON; // battery #1 relay/off
			CHRG1 = R_ON; // charge #1 relay/on
			break;
		}
	}
	wdttime(BATRUNF);
	CCOUTOPENSW = R_OFF; //
	wdttime(BATRUNF);
	SOLAROFF = R_OFF;
	wdttime(BATRUNF);
	BMMODE = CHARGE_M;

	if (bn != B1) { // switch off float cell and update status
		CHRG1 = R_OFF; // switch off transfer battery
		wdttime(BATRUNF);
		cell[B1].cconline = FALSE;
	}
}

void ChargeRelayOff(uint8_t bn, uint8_t FLOATSW)
{
	if (FLOATSW && (CCMODE == FLOAT_M)) {
		cell[bn].cconline = FALSE; // not charging from CC
		CCOUTOPENSW = R_OFF;
		wdttime(BATRUNF);
		CHRG1 = R_ON; // charge #1 relay/on ,use as float battery
		cell[B1].cconline = TRUE; // charging from CC
		wdttime(BATRUNF);
		switch (bn) {
		case B1B:
			BAT1 = R_OFF; // battery #1 relay/on
			if (B_GANGED) BAT2 = R_OFF; // battery #2 relay/on
			break;
		case B2B:
			BAT2 = R_OFF; // battery #2 relay/on
			CHRG2 = R_OFF; // charge #2 relay/off
			break;
		case B3B:
			BAT3 = R_OFF; // battery #3 relay/on
			CHRG3 = R_OFF; // charge #3 relay/off
			break;
		case B4B:
			BAT4 = R_OFF; // battery #4 relay/on
			CHRG4 = R_OFF; // charge #4 relay/off
			break;
		default:
			BAT1 = R_OFF; // battery #1 relay/on
			break;
		}
		wdttime(BATRUNF);
		SOLAROFF = R_OFF;
		wdttime(BATRUNF);
		BMMODE = FLOAT_M;
	} else {
		cell[bn].cconline = FALSE; // not charging from CC
		SOLAROFF = R_ON; // PV off before C40
		wdttime(BATRUNF);
		switch (bn) {
		case B1B:
			BAT1 = R_OFF; // battery #1 relay/on
			CHRG1 = R_OFF; // charge #1 relay/off
			if (B_GANGED) {
				BAT2 = R_OFF; // battery #2 relay/on
				CHRG2 = R_OFF; // charge #2 relay/off
			}
			break;
		case B2B:
			BAT2 = R_OFF; // battery #2 relay/on
			CHRG2 = R_OFF; // charge #2 relay/off
			if (B_GANGED) {
				BAT1 = R_OFF; // battery #1 relay/on
				CHRG1 = R_OFF; // charge #1 relay/off
			}
			break;
		case B3B:
			BAT3 = R_OFF; // battery #3 relay/on
			CHRG3 = R_OFF; // charge #3 relay/off
			break;
		case B4B:
			BAT4 = R_OFF; // battery #4 relay/on
			CHRG4 = R_OFF; // charge #4 relay/off
			break;
		default:
			BAT1 = R_OFF; // battery #1 relay/on
			CHRG1 = R_OFF; // charge #1 relay/off
			break;
		}
		wdttime(BATRUNF);
		SOLAROFF = R_OFF;
		wdttime(BATRUNF);
		BMMODE = IDLE_M;
	}
}

void battalarm(int16_t time, int16_t battno, int16_t mode)
{
	ALARMOUT = R_ON;
}

//FIXME fix check_alarm

/*  prints messages from the alarm array, need a rework as it's buggy */
uint8_t check_alarm(uint8_t bn, const rom int8_t* where) // print alarm codes to terminal or just the battery number with code 251
{ // or set flag with code 253 or clear flag code 252
	static uint8_t i = 0, alm_num = 255; // if bn is 255 return state of alarm_codes.alm_flag flag TRUE/FALSE, 254 return current alarm code
	static uint8_t last_alm_num = 255;

	s_crit(HL);

	if (bn > 250) {
		if (bn == 255) {
			if (alarm_codes.alm_flag) {
				e_crit();
				return TRUE;
			} else {
				e_crit();
				return FALSE;
			}
		}
		if (bn == 254) {
			e_crit();
			return alarm_buffer[almctr].alm_num;
		}
		if (bn == 253) {
			alarm_codes.alm_flag = TRUE;
			e_crit();
			return 253;
		}
		if (bn == 252) {
			alarm_codes.alm_flag = FALSE;
			e_crit();
			return 252;
		}
		if (bn == 251) {
			alarm_codes.alm_flag = FALSE;
			e_crit();
			return alarm_buffer[almctr].bn;
		}
	}

	if (alarm_codes.alm_flag == NULL0) { // nothing, lets go
		e_crit();
		return FALSE;
	}

	while (almctr > NULL0) {
		alm_num = alarm_buffer[--almctr].alm_num; // move down the alarm stack
		if (alm_num == last_alm_num) break;
		last_alm_num = alm_num;
		term_time();
		putrs2USART(where);
		sprintf(bootstr2, " BN%u, Q%u, Battery %02x,", bn, almctr, alarm_buffer[almctr].bn); // use the message battery number if set
		puts2USART(bootstr2);
		i = 0; // set alarm index to zero
		if (alm_num == i++) putrs2USART(almcode0); //0
		if (alm_num == i++) putrs2USART(almcode1); //1
		if (alm_num == i++) putrs2USART(almcode2); //2
		if (alm_num == i++) putrs2USART(almcode3); //3
		if (alm_num == i++) putrs2USART(almcode4); //4
		if (alm_num == i++) putrs2USART(almcode5); //5
		if (alm_num == i++) putrs2USART(almcode6); //6
		if (alm_num == i++) putrs2USART(almcode7); //7
		if (alm_num == i++) putrs2USART(almcode8); //8
		if (alm_num == i++) putrs2USART(almcode9); //9
		if (alm_num == i++) putrs2USART(divert0); //10
		if (alm_num == i++) putrs2USART(divert1); //11
		if (alm_num == i++) putrs2USART(battbuffer0); //12
		if (alm_num == i++) putrs2USART(almcode10); //13
		if (alm_num == i++) putrs2USART(almcode11); //14
		if (alm_num == i++) putrs2USART(almcode12); //15
		if (alm_num == i++) putrs2USART(almcode13); //16
		if (alm_num == i++) putrs2USART(almcode14); //17
		if (alm_num == i++) putrs2USART(almcode15); //18
		if (alm_num == i++) putrs2USART(almcode16); //19
		if (alm_num == i++) putrs2USART(charger2); //20
		if (alm_num == i++) putrs2USART(charger3); //21
		if (alm_num == i++) putrs2USART(charger4); //22
		if (alm_num == i++) putrs2USART(almcode17); //23
		if (alm_num == i++) putrs2USART(almcode18); //24
		if (alm_num == i++) putrs2USART(almcode19); //25
		if (alm_num == i++) putrs2USART(almcode20); //26
		if ((alm_num > i) && (alm_num < 250)) { // if greater than last defined alarm code
			sprintf(bootstr2, " UNKNOWN Alarm code %u \r\n", alm_num);
			puts2USART(bootstr2);
		}
	};
	if (almctr == NULL0) {
		alarm_codes.alm_flag = FALSE;
	}
	alarm_buffer[almctr].bn = B0; // set default battery number to zero
	e_crit();
	return NULL0;
}

float update_cef(uint8_t bn, uint8_t mode) // try to find the real charge eff factor
{
	s_crit(HL);
	if (mode == TRUE) { // startup cef values
		if (hist[bn].bsoc < SOC_DERATE) { // decide what value to use at the current SOC
			hist[bn].cef = CEF_LSOC; // use cef for low state of charge
		} else {
			hist[bn].cef = CEF_HSOC; // use the cef for higher states of charge
		}
		if (hist[bn].cef > CEF_MAX) hist[bn].cef = CEF_MAX;
		if (hist[bn].cef < CEF_MIN) hist[bn].cef = CEF_MIN;
		hist[bn].cef_save = hist[bn].cef; // store the original cef
		e_crit();
		return hist[bn].cef;
	}

	/* Needs work to simplify code */
	if (hist[bn].bsoc < SOC_DERATE) { // adjust charge eff with SOC if battery nears fully charged
		hist[bn].cef = CEF_LSOC; // usually around 91% 0-SOC_DERATE SOC
	} else {
		if (hist[bn].cef_calc > 0.99) { // we are out of range to use realtime data, cef_calc = 100.0.means NO
			hist[bn].cef = CEF_HSOC; // use the static value, high rates of battery charge have lower eff factors to fully charged
		}
		if (hist[bn].cef < CEF_MIN) { // if we go too low reset to static value
			hist[bn].cef = CEF_HSOC; // use cef for HIGH state of charge
		} else if (hist[bn].cef_calc < 1.00) { // only update if we can use realtime data, cef_calc = 100.0.means NO
			hist[bn].cef = hist[bn].cef_save; // use the archived cef for higher states of charge
			if (hist[bn].cef_calc <= CEF_LSOC) { // update cef from realtime data
				if (hist[bn].cef <= SOC_CEF) hist[bn].cef = (hist[bn].cef_calc + hist[bn].cef_save) / 2.0; // use dynamic value average
			}
		}
	}
	if (hist[bn].cef > CEF_MAX) hist[bn].cef = CEF_MAX;
	if (hist[bn].cef < CEF_MIN) hist[bn].cef = CEF_MIN;
	if (CHARGERL == R_ON) divert_power(OFF, YES, 0); // Switch off power to extra loads when charging (waste)
	e_crit();
	return hist[bn].cef;
}

/*
 * Return a battery SOC from a adjusted voltage, store this adjusted voltage in the vsoc array
 * SOC is also set in hist[z].bsoc GLOBAL
 */
uint16_t Volts_to_SOC(uint32_t cvoltage, uint8_t z)
{
	static uint8_t slot;

	if ((R.thermo_batt - Temp_ZERO) != 0) cvoltage = (uint32_t) ((int32_t) cvoltage - ((int32_t) (R.thermo_batt - Temp_ZERO) / (int32_t) BFACTOR_TEMP)); // include temp correction
	if (cell[z].current > 0) { // adjust SOC for battery loading
		cvoltage += cell[z].current / BVSOC_C_OFF; // current = 400 # 40amps loading down voltage
	} else {
		if (!B_GANGED) cvoltage += BVSOC_SV_OFF; // controller loading on standby battery
	}
	vsoc[z] = cvoltage;
	hist[z].bsoc = 0;
	cell[z].fresh = FALSE;
	for (slot = 0; slot < BVSOC_SLOTS; slot++) {
		if (cvoltage > BVSOC_TABLE[slot][0]) {
			hist[z].bsoc = BVSOC_TABLE[slot][1];
		}
	}
	/* if the battery voltage is too high or the SOC is too low it's not FRESH */
	if ((hist[z].bsoc > BVSOC_FRESH) && (cvoltage <= BVSOC_HIGH)) cell[z].fresh = TRUE;
	if (z > HISTBATTNUM) B.r_soc[z] = (uint8_t) hist[z].bsoc; // fill in for controller batteries
	return hist[z].bsoc;
}

/* SOC is set in hist[z].bsoc GLOBAL , load up the cell for testing on startup and store value
 * SOC_BLEND 0 = no blending, 1 = blend loaded with rest soc, 2 = reset stored soc to current soc value
 */
uint16_t Get_RestSOC(uint8_t z, uint8_t S_SOC, blendmode_t SOC_BLEND)
{
	static uint16_t soc_loaded[HISTBATTNUM] = {0, 0}, soc_result = 0;

	if ((z == 0) || (z > HISTBATTNUM)) return 0; // only for primary cells
	BLENDMODE = SOC_BLEND; // set global state var
	if (S_SOC) {
		ADC_read(); // read loaded battery voltage from charge line.
		term_time();
		sprintf(bootstr2, " Get_RestSOC Load testing Battery %i V%li.\r\n", z, R.primarypower[z]);
		puts2USART(bootstr2);
		ChargeRelayOn(z, TRUE);
		wdttime(BATRUNF);
		BATLOAD_HI = R_ON; // battery load relay/on
		wdttime(BATTEST); // drain the battery
	}
	ADC_read(); // read loaded battery voltage from charge line.
	soc_result = Volts_to_SOC(R.primarypower[z], z);
	if (S_SOC) {
		soc_loaded[z - 1] = soc_result; // Store the loaded SOC value, convert z to soc_loaded array index (z-1) B1=0,B2=1
		term_time();
		sprintf(bootstr2, " Get_RestSOC Battery %i V%li Load Disconnected.\r\n", z, R.primarypower[z]);
		puts2USART(bootstr2);
		BATLOAD_HI = R_OFF;
		ChargeRelayOff(z, FALSE);
		wdttime(BATRUNF);
	}
	if (SOC_BLEND == DO_BLEND) {
		soc_result = (soc_result + soc_loaded[z - 1]) / 2; // avg the two SOC results
	}
	if (SOC_BLEND == MILD_BLEND) {
		soc_result = (soc_result + soc_result + soc_loaded[z - 1]) / 3; // avg the two SOC results with bias to result
	}
	if (SOC_BLEND == CLEAR_BLEND) {
		soc_loaded[z - 1] = soc_result;
	}
	return soc_result;
}

void fail_safe(void)
{
	P.FAILSAFE = TRUE;
	CCOUTOPENSW = R_OFF;
	SOLAROFF = R_OFF;
	if (LOADNOTFAN || !P.COOLING) PVLOAD = R_OFF;
	BCRELAYS = 0xFF;
	BAT1 = R_ON; // battery #1 relay/off
	CHRG1 = R_ON; // charge #1 relay/on
	CCS.boc = B1;

	while (DIPSW6 == HIGH) { // wait until switch is clear
		ADC_read();
		sprintf(bootstr2, "FS T%s,SV%lu             ", hms(V.timerint_count), R.systemvoltage / 100);
		LCD_VC_puts(VC0, DS0, YES);

		sprintf(bootstr2, "PV%lu,PI%li,CV%lu           ", R.inputvoltage / 100, R.currentin / 10, R.ccvoltage / 100);
		LCD_VC_puts(VC0, DS1, YES);

		sprintf(bootstr2, "B1V%lu,B2V%lu,LI%li                 ", R.primarypower[B1] / 100, R.primarypower[B2] / 100, C.currentload / 10);
		LCD_VC_puts(VC0, DS2, YES);

		sprintf(bootstr2, "%lu, %lu, %lu                  ", V.timerint_count, V.clock50, V.clock50 / V.timerint_count);
		LCD_VC_puts(VC0, DS3, YES);

		wdtdelay(5000);
		idle_loop();
	}
	P.FAILSAFE = FALSE;
	s_crit(HL);
	c_off = V.timerint_count;
	e_crit();
	CHARGERL = R_OFF;
	alarm_buffer[almctr].bn = CCS.boc;
	alarm_buffer[almctr++].alm_num = 3;
	alarm_codes.alm_flag = TRUE;
	check_alarm(CCS.boi, " fail1 "); // send alarm codes to terminal if alm_flag is set
}

int16_t sd_dump(int16_t mode) // mode = dump device 0 RS-232 port
{
	static int16_t ret = 0, j = 0, k = 0;
	static uint32_t i = 0, dsize = 0;

	sprintf(bootstr2, "Dump SD Card Com2.  ");
	LCD_VC_puts(VC0, DS0, YES);

	ret = mmc_read_block(SDINFO); // read info block
	if (ret) {
		sprintf(bootstr2, "No SD Card, Goodbye. ");
		LCD_VC_puts(VC0, DS1, YES);
		term_time();
		putrs2USART(sddump0);
		s_crit(HL);
		SDD0.dumping = FALSE;
		e_crit();
		return ERR1;
	}
	memcpy((void *) &sdc0b1, (void *) &block_buffer[0], sizeof( sdc0b1));
	if (sdc0b1.magic == MAGIC) { // see if we have a valid MBMC data SDCARD

		if (SDD0.type == 'h') {
			if (sdc0b1.sdnext > 1001) { // send last 1000 records or less
				dsize = sdc0b1.sdnext - 999;
			} else {
				dsize = 1;
			}
		} else {
			dsize = 1; // default: start from first record
		}

		for (i = dsize; i < sdc0b1.sdnext; i++) { // pull the records from the SDCARD
			sprintf(bootstr2, "%lu of %lu records.      ", i, sdc0b1.sdnext);
			LCD_VC_puts(VC0, DS1, YES);

			if (!SDD0.dumping) break; // stop the madness
			ret = mmc_read_block(i); // read data block
			if (ret) {
				ret = mmc_read_block(i); // read data block again
				if (ret) continue; // possible bad block, skip
			}
			k = strlen((int8_t *) block_buffer);
			if (k > SDBUFFERSIZE) k = SDBUFFERSIZE;
			// setup ISR xmit buffer structure
			mbmc_dumpflag.data_pos = 0;
			mbmc_dumpflag.data_len = k;
			mbmc_dumpflag.data_ptr = (uint8_t*) & block_buffer; // data pointer to data block from SD CARD

			PIE3bits.TX2IE = HIGH; // start data xmit from ISR
			while (PIE3bits.TX2IE) { // if it's HIGH we are still sending data
				ClrWdt(); // wait for buffer xmit complete
			}
			if (i % 32 == NULL0) ADC_read(); //  update data, sometimes
			idle_loop(); // stay in touch with the network
		}
	}
	mbmc_dumpflag.data_pos = 0; // reset buffer structure for manual sends
	mbmc_dumpflag.data_len = 0;
	P2wait(); // wait for xmit clear
	TXREG2 = '\r'; // return
	P2wait(); // wait for xmit clear
	TXREG2 = '\n'; // newline
	s_crit(HL);
	SDD0.dumping = FALSE;
	e_crit();
	return NULL0;
}

int16_t W_SDC0_EEP(uint16_t address) // write SDCO to eep starting at address
{
	static uint16_t i = 0;
	//  write_data_eeprom ( uint8_t data, uint8_t count, uint16_t addr, uint16_t offset )
	for (i = 0; i < sizeof( sdc0b1); i++) {
		write_data_eeprom(block_buffer[i], (uint8_t) sizeof( sdc0b1), i, address);
	}
	return NULL0;
}

int16_t initsd(void)
{
	static uint8_t j = 0, k = 0;
	static uint16_t i = 0;

	SDSAFE = S_OFF;
	clr_lcd();
	init_sdspi(); // config SPI port for SDCARD access
	if (disk_initialize() == NULL0) {
		sprintf(bootstr2, "Looking for SD Card ");
		LCD_VC_puts(VC0, DS0, YES);

		i = MMC_get_volume_info();
		if (i == ERR2) {
			sprintf(bootstr2, "Wrong SD Card Found %i.", (int16_t) SDC0.sdtype);
			LCD_VC_puts(VC0, DS0, YES);
			term_time();
			putrs2USART(sddump1);
			s_crit(HL);
			return i;
		}
		if (i == ERR1) {
			sprintf(bootstr2, "No SD Card Found.");
			LCD_VC_puts(VC0, DS0, YES);
			term_time();
			putrs2USART(sddump0);
			s_crit(HL);
			return i;
		}

		if (SDC0.sdtype == 6) {
			sprintf(bootstr2, "%s,%i Size %luM                     ", vinf->name,
				SDC0.sdtype, vinf->size_MB / 1000);
		} else {
			sprintf(bootstr2, "%s,%i Size %luM                     ", vinf->name,
				SDC0.sdtype, vinf->size_MB);
		}
		LCD_VC_puts(VC0, DS0, YES);

		sprintf(bootstr2, "Serial %lu                     ", vinf->serial);
		LCD_VC_puts(VC0, DS1, YES);

		wdttime(BATRUNF + BATRUNF);
		memset(block_buffer, 0, SDBUFFERSIZE);
	} else {
		return ERR1;
	}

	i = mmc_read_block(SDINFO); // dummy read
	i = mmc_read_block(SDINFO); // read info block
	if (i) return ERR1; // error reading info block

	memcpy((void *) &sdc0b1, (void *) &block_buffer[0], sizeof( sdc0b1)); //
	if ((sdc0b1.magic == MAGIC) && !DIPSW1) {
		sprintf(bootstr2, "Loading SD Card data.   ");
		LCD_VC_puts(VC0, DS1, YES);

		SDC0.sdpos = sdc0b1.sdnext; // update from sdcard next block to write
		SDC0.timekeep += sdc0b1.time;
		SDC0.harvest = sdc0b1.harvest;
		for (j = 0; j < HISTBATTNUM; j++) {
			for (k = 0; k < HPARAM_SIZE; k++) {
				hist[j + 1].h[k] = sdc0b1.h[j][k]; // copy primary battery history data, sdcard h array 0=B1, 1=B2
			}
			hist[j + 1].kwi = (int32_t) ((int32_t) hist[j + 1].h[12] * 10000l); // restore power from int16_t to uint32_t
			hist[j + 1].kwo = (int32_t) ((int32_t) hist[j + 1].h[9] * 10000l);
		}
		sprintf(bootstr2, "SDHC/SDXC Card Ready ");
		LCD_VC_puts(VC0, DS2, YES);
		W_SDC0_EEP(SDC0EEP); // mirror SDC0 data to eep at address
		sprintf(bootstr2, "Update EEP/SD data.        ");
		LCD_VC_puts(VC0, DS3, YES);
		term_time();
		putrs2USART(sddump2);
		SDC0.DAYCLOCK = TRUE; // set dayclock after SD data load
		if (SDC0.sdpos > SDEND) {
			SDC0.sdpos = SDSTART;
			SDC0.sdnext = SDSTART;
			term_time();
			putrs2USART(sddump4);
		}
	} else {
		sprintf(bootstr2, "INIT new SD Card.       ");
		LCD_VC_puts(VC0, DS1, YES);
		sprintf(bootstr2, "SDHC/SDXC Card Ready ");
		LCD_VC_puts(VC0, DS2, YES);

		s_crit(HL);
		SDC0.timekeep = V.timerint_count;
		e_crit();
		init_hist_data();
		// other data has already been set earlier
		wipe_sdbuffer();
		memcpy((void *) &block_buffer[0], (void *) &SDC0, sizeof( SDC0));
		sdret = mmc_write_block(SDINFO); // init new card block
		W_SDC0_EEP(SDC0EEP); // mirror SDC0 data to eep at address
		sprintf(bootstr2, "Update EEP/SD data.        ");
		LCD_VC_puts(VC0, DS3, YES);
		term_time();
		putrs2USART(sddump3);
	}
	SDSAFE = S_ON;
	return NULL0;
}

void ansidraw(int16_t mode) // tek 410x/ansi drawing stuff
{
	putc2(ESC);
	putc2('['); // clear screen
	putc2('2');
	putc2('J');
	if (SIM_MODE) putrs2USART(SIMULA);
	putrs2USART(hello1);
	putrs2USART(hello0);
}

void init_hist_data(void)
{
	static uint8_t j = 0, k = 0;

	term_time();
	putrs2USART(" Init History Data \r\n");
	SDC0.time = 0;
	SDC0.magic = MAGIC;
	SDC0.sdpos = SDSTART;
	SDC0.sdnext = SDSTART;
	SDC0.harvest.energy = 0;
	SDC0.harvest.charger = 0;
	SDC0.harvest.usage = 0;
	SDC0.harvest.diversion = 0;
	SDC0.harvest.prev_energy = 0;
	SDC0.harvest.prev_charger = 0;
	SDC0.harvest.prev_usage = 0;
	SDC0.harvest.e_total = 0;
	SDC0.harvest.c_total = 0;
	SDC0.harvest.u_total = 0;
	SDC0.harvest.count = 0;
	SDC0.DAYCLOCK = FALSE;
	for (j = 0; j <= battnum; j++) { // set all data including the dummy battery
		for (k = 0; k < HPARAM_SIZE; k++) {
			hist[j].h[k] = 0; // zero primary battery history data
		}
		hist[j].h[7] = BATTHIGH;
		hist[j].h[8] = BATTLOW;

		hist[j].h[10] = ESRHIGH;
		hist[j].kwi = 0; // reset battery power stats
		hist[j].kwo = 0; // reset battery power stats
	}
}

void main(void) // Lets Party
{
	static uint32_t waittime = 0;
	static uint8_t eep_char = NULL0, boi = 0, bn = B0B, j = 0, k = 0, ftest = NULL0, lmode = TRUE;
	static uint8_t z = 0, tmp8 = 0;

	MBMC.MBMCID = (int32_t) __MBMC_ID + ((int32_t) MAGIC << SHIFT8); // set the card id for the network and MAGIC version number in bits 8..23
	MBMC.diversion.flag = FALSE;
	MBMC.diversion.power = 1; // show a small signal at startup
	MBMC.diversion.power_control = 0;
	MBMC.diversion.alarm = 0;
	mbmcflag.cmd_timeout = TRUE;
	netdword_pos = 0; // set pointer, load flag
	mbmcflag.data_pos = 0; // init the data pointer position
	mbmcflag.data_len = 0; // init the buffer length
	mbmcflag.data_ptr = (uint8_t*) & MBMC; // default data pointer
	mbmccell = (celltype*) & cell; // default data pointer
	mbmc_dumpflag.data_pos = 0; // init the data pointer position
	mbmc_dumpflag.data_len = 0; // init the buffer length
	mbmc_dumpflag.data_ptr = (uint8_t*) & block_buffer; // default data pointer
	UTC_flag = FALSE;
	UTC_ok = FALSE;
	CCMODE = IDLE_M;
	BMMODE = IDLE_M;
	alarm_buffer[B0].bn = B0;
	solarup_delay = NULL0;
	P.SAVE_DAILY = FALSE;
	// energy,usage,prev_energy,prev_usage,e_total,u_total,count, charger vars;
	SDC0.harvest.energy = 0;
	SDC0.harvest.charger = 0;
	SDC0.harvest.usage = 0;
	SDC0.harvest.diversion = 0;
	SDC0.harvest.prev_energy = 0;
	SDC0.harvest.prev_charger = 0;
	SDC0.harvest.prev_usage = 0;
	SDC0.harvest.e_total = 0;
	SDC0.harvest.c_total = 0;
	SDC0.harvest.u_total = 0;
	SDC0.harvest.count = 0;
	SDC0.DAYCLOCK = FALSE;
	B.yesterday = 0;
	B.today = 0;
	B.equal = 0;
	C.t_comp = 1.0; // 1.0 is the default
	dsi = VC0; // set display index to 0 for monitor strings
	battbuffer.busy = FALSE;
	battbuffer.flag = FALSE;
	battbuffer.copy = FALSE;
	battbuffer.good = TRUE;
	CCS.alert = FALSE;
	CCS.bn = 0;
	bmt[B0].soc[SOC_50].soc = 50;
	bmt[B0].soc[SOC_70].soc = 70;
	bmt[B0].soc[SOC_85].soc = 85;
	bmt[B0].soc[SOC_100].soc = 95;
	bmt[B1].soc[SOC_50].soc = 50;
	bmt[B1].soc[SOC_70].soc = 70;
	bmt[B1].soc[SOC_85].soc = 85;
	bmt[B1].soc[SOC_100].soc = 95;
	alarm_codes.alm_flag = FALSE;
	for (z = 0; z < LPCHANC; z++) { // init lp_filter array
		smooth[z] = 0;
	}
	smooth[LP_CCEFF] = 255; // preset value
	CCEFF = (int16_t) lp_filter((float) 255, LP_CCEFF, FALSE); // update filter
	sprintf(bootstr2, "\r\n^^^,0,No Status Report,###");

#ifdef	__18F8722
	config_pic(PIC_8722); // configure all controller hardware to the correct settings and ports
#endif

	for (z = 1; z <= battnum; z++) { //      make sure nothings valid until voltage tested.
		cell[z].valid = NULL0;
	}
	cell[B0].valid = TIMEROFFSET;

	sprintf(bootstr2, "********************"); // blank display data
	LCD_VC_puts(VC0, DS0, YES);
	LCD_VC_puts(VC0, DS1, YES);
	LCD_VC_puts(VC0, DS2, YES);
	LCD_VC_puts(VC0, DS3, YES);

#ifdef	__18F8722
	start_pic(PIC_8722); // configure external hardware to the correct startup conditions
#endif
	P.BLANK_LCD = FALSE;
	wdtdelay(10000); // delay for power related LCD setup glitch
	OpenXLCD(FOUR_BIT & LINES_5X7);
	while (BusyXLCD());
	wdtdelay(10000); // delay for power related LCD setup glitch
	OpenXLCD(FOUR_BIT & LINES_5X7);
	while (BusyXLCD());
	WriteCmdXLCD(0xc); // blink, cursor off
	while (BusyXLCD());
	WriteCmdXLCD(0x1); // clear screen
	wdtdelay(10000);
	while (BusyXLCD());

#ifdef	__18F8722
	if (STKPTRbits.STKFUL) {
		putrs2USART("\r\n");
		term_time();
		putrs2USART("\x1b[7m Restart from Stack Full. \x1b[0m\r\n");
		BOOT_STATUS += 1;
		alarms.mbmc_alarm.cpu = 1;
	}
	if (STKPTRbits.STKUNF) {
		putrs2USART("\r\n");
		term_time();
		putrs2USART("\x1b[7m Restart from Stack Underflow. \x1b[0m\r\n");
		BOOT_STATUS += 2;
		alarms.mbmc_alarm.cpu = 1;
	}
#endif

	if (WDT_TO) {
		putrs2USART("\r\n");
		term_time();
		putrs2USART("\x1b[7m Restart from Watchdog Timer. \x1b[0m\r\n");
		BOOT_STATUS += 4;
		alarms.mbmc_alarm.cpu = 1;
	}

	if (EEP_ER) {
		putrs2USART("\r\n");
		term_time();
		putrs2USART("\x1b[7m Possible EEPROM write error. \x1b[0m\r\n");
		BOOT_STATUS += 8;
		alarms.mbmc_alarm.cpu = 1;
	}

	strncpypgm2ram(bootstr2, START1, LCD_W);
	LCD_VC_puts(VC0, DS0, YES);

	putrs2USART(" FW ");
	strncpypgm2ram(bootstr2, build_time, LCD_W);
	LCD_VC_puts(VC0, DS1, YES);
	puts2USART(bootstr2);
	putrs2USART(" ");

	strncpypgm2ram(bootstr2, build_date, LCD_W);
	puts2USART(bootstr2);
	LCD_VC_puts(VC0, DS2, YES);

	strncpypgm2ram(bootstr2, MBMC_VERSION, LCD_W);
	puts2USART(bootstr2);
	putrs2USART("\r\n");
	LCD_VC_puts(VC0, DS3, YES);

	if (WDT_TO || EEP_ER || STKPTRbits.STKFUL || STKPTRbits.STKUNF) {
		STKPTRbits.STKFUL = 0;
		STKPTRbits.STKUNF = 0;
		strncpypgm2ram(bootstr2, BOOT_ALM1, LCD_W);
		LCD_VC_puts(VC0, DS0, YES);
		LCD_VC_puts(VC0, DS1, YES);
		LCD_VC_puts(VC0, DS2, YES);
		LCD_VC_puts(VC0, DS3, YES);
		do {
			ALARMOUT = R_ON;
		} while (STFU);
	}

	term_time();
	sprintf(bootstr2, " Configuration DIPSW %i%i%i%i%i%i%i%i LSB\r\n", DIPSW8, DIPSW7,
		DIPSW6, DIPSW5, DIPSW4, DIPSW3, DIPSW2, DIPSW1);
	puts2USART(bootstr2);

	if (DIPSW2 == HIGH) { // set number of batteries to 2
		battnum = HISTBATTNUM;
	}

	if (DIPSW5 && !DIPSW2) { // hardware GANGED MODE if > 2 batteries
		B_GANGED = TRUE;
		term_time();
		putrs2USART(" Battery 1&2 GANGED mode \r\n");
	} else {
		B_GANGED = FALSE;
	}

	// leds from outputs to ground via resistor.

	hist[B0].ah = 100; // not used
	if (B_GANGED) {
		hist[B1].ah = B12_GANGEDAH;
	} else {
		hist[B1].ah = B1AH; // config battery cap in Ah, 1.0 A units
	}
	hist[B2].ah = B2AH;
	hist[B3].ah = B3AH;
	hist[B4].ah = B4AH;
	term_time();
	putrs2USART(" Configure battery operational data \r\n");
	cell[B0].id = 'N'; /* none */
	cell[B1].id = B1ID;
	cell[B2].id = B2ID;
	cell[B3].id = B3ID;
	cell[B4].id = B4ID;

	for (z = 0; z <= battnum; z++) {
		if (DIPSW1 == HIGH) { // clear battery data
			term_time();
			putrs2USART(" Init Battery Data \r\n");
			cell[z].id = B1ID;
			if (z > 2) {
				write_data_eeprom(B3ID, 5, z, 0);
				cell[z].id = B3ID;
			} else {
				write_data_eeprom(B1ID, 5, z, 0);
			}
		}
		cell[z].voltage = 0;
		cell[z].current = 0;
		cell[z].charge = 0;
		cell[z].cycles = 0;
		cell[z].noload = 0;
		cell[z].date = 0;
		hist[z].rate = (uint16_t) ((float) hist[z].ah * DF); // derate battery by (Discharge Floor) factor
		hist[z].drate = 0; // system adjusted battery Ah offset
		hist[z].rest_rate = 0; // stores energy in Ah than can be recovered by battery rest and other factors
		hist[z].rest_factor = RFACTOR; // Efficency factor of battery recovery
		hist[z].peukert = PerkC1;
		hist[z].peukert_adj = Perk_ADJ_FL;
		hist[z].cef = CEF_HSOC; // cef used for recharge calculations
		hist[z].cef_save = hist[z].cef; // starting cef during recharge cycles
		hist[z].cef_calc = CEF_HSOC; // this value will be updated after a full recharge cycle
		hist[z].h[7] = BATTHIGH;
		hist[z].h[8] = BATTLOW;

		hist[z].h[10] = ESRHIGH;
		cell[z].online = FALSE;
		cell[z].cconline = FALSE;
		cell[z].discharged = FALSE;
		cell[z].dead = FALSE;
		cell[z].critical = FALSE;
		cell[z].fresh = FALSE;
	}
	hist[B2].peukert = PerkC2; // init B2 Peukert factor

	/*              SET primary battery [B1] as the online (power to inverter */
	cell[B1].online = TRUE;

	if (DIPSW1 == HIGH) { // clear and set default eeprom data
		term_time();
		putrs2USART(" Erasing all EEPROM data values\r\n");
		wipe_data_eeprom(1024);
		term_time();
		putrs2USART(" Init ADC Cal EEPROM Data with default values\r\n");
		for (z = 0; z < ADC_SLOTS; z++) {
			write_data_eeprom(adc_cal[z], ADC_SLOTS, z, EEPROM_ADC);
		}
	}

	term_time();
	putrs2USART(" Read battery eeprom data \r\n");

	/*
	 * load EEPROM data
	 */
	if (read_data_eeprom(0, EEPROM_BAT) == CHECKMARK) { // load battery types from EEPROM
		for (z = 0; z <= battnum; z++) { // 1 + number of batteries, 0 is the controller supply voltage
			eep_char = read_data_eeprom(EEPROM_BAT + 2, z);
			if ((eep_char == 'S') || (eep_char == 'M') || (eep_char == 'L') || (eep_char == 'N')) {
			} else {
				term_time();
				putrs2USART(" Invalid battery type eeprom data \r\n"); // init eeprom data
				write_data_eeprom(cell[z].id, 5, z, EEPROM_BAT);
			}
		}
	} else {
		term_time();
		putrs2USART(" Invalid battery eeprom data \r\n"); // init eeprom data
		for (z = 0; z <= battnum; z++) {
			term_time();
			putrs2USART(" Invalid battery type eeprom data \r\n"); // init eeprom data
			write_data_eeprom(cell[z].id, 5, z, EEPROM_BAT);
		}
	}
	term_time();
	putrs2USART(" Read ADC eeprom data \r\n");

	if (read_data_eeprom(0, EEPROM_ADC) == CHECKMARK) { // load ADC cal data from EEPROM
		term_time();
		putrs2USART(" ADC eeprom data ");
		for (z = 0; z < ADC_SLOTS; z++) {
			adc_cal[z] = read_data_eeprom(EEPROM_ADC + 2, z);
			sprintf(bootstr2, " %i:", (int16_t) adc_cal[z]);
			puts2USART(bootstr2);
		}
		putrs2USART("\r\n");
	} else {
		term_time();
		putrs2USART(" Invalid ADC eeprom data \r\n"); // init adc cal eeprom data												// init eeprom data
		for (z = 0; z < ADC_SLOTS; z++) {
			write_data_eeprom(adc_cal[z], ADC_SLOTS, z, EEPROM_ADC);
		}
	}

	term_time();
	putrs2USART(" Read History eeprom data \r\n");

	if (read_data_eeprom(0, EEPROM_HIS) == CHECKMARK) { // load old history data from EEPROM
		term_time();
		putrs2USART(" History eeprom data ");
		for (z = 0; z <= battnum; z++) {
			tmp8 = read_data_eeprom(EEPROM_HIS + 2, z);
			sprintf(bootstr2, " %x:", (int16_t) tmp8);
			puts2USART(bootstr2);
		}
		putrs2USART("\r\n");
	} else {
		term_time();
		sprintf(bootstr2, " Invalid History eeprom data, size: %i\r\n", (int16_t) sizeof(hist[0].h)); // init eeprom data
		puts2USART(bootstr2);
		for (z = 0; z <= battnum; z++) {
			write_data_eeprom(hist[z].h[11], battnum, z, EEPROM_HIS); // total charge cycles
		}
	}

	if (DIPSW6 == HIGH) { // failsafe mode, connect C40 to battery#1 and loop
		fail_safe();
		while (TRUE); // Don't  continue
	}

	zero_amploc_PV(); // zero input current sensor
	CCOUTOPENSW = R_OFF; // charge voltage relay/on
	if (LOADNOTFAN || !P.COOLING) PVLOAD = R_OFF; // charge load relay/on
	term_time();
	putrs2USART(" Read ADC data inputs \r\n");
	wdttime(BATRUNF);
	ADC_read();

	//              setup SDHC card for datalogging
	if (initsd() != 0) { // init the SDCARD interface.
		sprintf(bootstr2, "SD Card init failed.   ");
		LCD_VC_puts(VC0, DS2, YES);
		sprintf(bootstr2, "No history will be saved!");
		LCD_VC_puts(VC0, DS3, YES);
		term_time();
		putrs2USART(" #### \x1b[7mNo SDCARD Detected, No history will be saved!\x1b[0m ####\r\n");
		alarms.mbmc_alarm.sdcard = 1;
	}

	if ((DIPSW1 == HIGH) || (hist[B1].h[8] == 0) || (hist[B2].h[8] == 0)) { // set default hist and SD data with DIPSW1 or if the h[8] data is invalid
		init_hist_data();
	}

	voltfp(R.inputvoltage, f1);
	voltfp(R.ccvoltage, f2);
	sprintf(bootstr2, "%iBat,%sV,%sV      ", battnum, f1, f2); // display battery ,PV info
	LCD_VC_puts(VC0, DS0, YES);

	sprintf(bootstr2, "DIPSW %i%i%i%i%i%i%i%i LSB          ", DIPSW8, DIPSW7,
		DIPSW6, DIPSW5, DIPSW4, DIPSW3, DIPSW2, DIPSW1);
	LCD_VC_puts(VC0, DS1, YES);

	start_delay();

	BCRELAYS = 0xFF; // turn on all battery relays/on
	PVLOAD = R_ON; // charge load relay on before measuring PV input voltage

	wdttime(BATRUNF); // read battery and charging system voltages
	ADC_read();
	srand((uint16_t) R.systemvoltage); // set random seed
	cell[B0].valid = rand(); // set valid value

	/* Work thread start */
	start_workerthread();

	wdttime(BATRUNF);
	term_time();
	putrs2USART(runcode3);

	/* Loop forever */
	while (TRUE) {
		if (P.PRIPOWEROK) {
			BCRELAYS = 0xFF; // turn off all battery relays
			wdttime(BATRUNF); // read battery and charging system voltages

			mkbsstring();
			update_hist();

			// set battery number 0=battery array, controller batteries check
			cell[B0].voltage = R.systemvoltage;
			cell[B0].noload = R.systemvoltage;
			cell[B0].charge = R.ccvoltage;
			cell[B0].cycles++;
			if (cell[B0].voltage < BATTSYSLOW) P.BCHECK = TRUE; // check array for low voltage

			for (z = 1; z <= battnum; z++) {
				if (cell[B0].voltage < BATTSYS) cell[z].critical = TRUE; // set battery as critical if the whole array is failing
				if (cell[z].valid == cell[B0].valid) {
					update_hist();
					voltfp(cell[z].charge, f1);
					sprintf(bootstr2, "B%i %sV                   ", z, f1);
					LCD_VC_puts(VC0, DS0, YES);
					voltfp(cell[z].noload, f1);
					voltfp(cell[z].voltage, f2);
					sprintf(bootstr2, "ul %sV,tl %sV          ", f1, f2);
					LCD_VC_puts(VC0, DS1, YES);
					wdttime(BATRUNF);
				}
			}

			ftest++;
		} else {
			idle_loop();
			update_hist();
			bn = pick_batt(NO, NULL0);
			if (P.SYSTEM_STABLE) noload_soc();
		}

		if (ftest > BATTCHECK) { // force battery test after X loops
			if (R.inputvoltage > SOLARHIGH) P.BCHECK = TRUE;
			ftest = 0;
		}

		if (!P.PRIPOWEROK) { // skip if we are in primary battery override charging.
			sprintf(bootstr2, "OVERRIDE CHRG #1");
			LCD_VC_puts(VC0, DS0, YES);
		}
		sprintf(bootstr2, "                        "); //      blank second line
		LCD_VC_puts(VC0, DS1, YES);

		wdttime(BATRUNF);
		ADC_read();
		while ((R.inputvoltage > SOLARHIGH) || P.BCHECK) {

			if (P.BCHECK) {
				for (z = 1; z <= battnum; z++) {
					if (P.PRIPOWEROK) {
						if (P.SET_CEF) update_cef(z, P.SET_CEF); // check cef before we start charging
						term_time();
						sprintf(bootstr2, " Battery %i BC ", z);
						puts2USART(bootstr2);
						putrs2USART(runcode2);
						wdttime(BATRUNF);
						mkbsstring();
						bn = z; // set battery #
						ChargeBatt(bn, TRUE, TRUE); //      check battery
						update_hist();
					}
				}
				if (!P.SYSTEM_STABLE) {
					noload_soc(); //	Setup soc on startup after ESR checks
				}
			}
			P.BCHECK = FALSE;
			P.SET_CEF = FALSE;

			P.SYSTEM_STABLE = TRUE; // we can start monitor logic now

			s_crit(HL); // reload_cal adc values into ram from eeprom
			if (read_data_eeprom(0, 8) == CHECKMARK) { // load ADC cal data from EEPROM
				for (z = 0; z < ADC_SLOTS; z++) {
					adc_cal[z] = read_data_eeprom(10, z);
				}
			}
			e_crit();

			noload_soc(); // run both twice to get stable data
			noload_soc();
			pick_batt(NO, NULL0);
			update_hist();

			if (P.PRIPOWEROK) {
				sprintf(bootstr2, "Any critical      ");
				LCD_VC_puts(VC0, DS0, YES);
				sprintf(bootstr2, "Batteries?              ");
				LCD_VC_puts(VC0, DS1, YES);

				for (z = 1; z <= battnum; z++) {
					pick_batt(NO, NULL0);
					update_hist();
					sprintf(bootstr2, "Battery #%i          ", z);
					LCD_VC_puts(VC0, DS1, YES);
					mkbsstring();

					if (cell[z].critical) {
						wdttime(BATRUNF);
						if ((R.inputvoltage > SOLARHIGH)) {
							term_time();
							putrs2USART(runcode4);
							bn = z; // set battery #
							hist[bn].h[5]++; // full discharge cycles, will also update B2 when ganged
							if ((z == B2) && B_GANGED) {
								term_time();
								sprintf(bootstr2, " Battery %2i,  \x1b[7mGANGED to B1\x1b[0m \n\r", z);
								puts2USART(bootstr2);
								bn = B1;
							}
							noload_soc();
							ChargeBatt(bn, FALSE, TRUE);
							noload_soc();
							ChargeBatt(bn, TRUE, TRUE);
							ftest = BATTCHECK;
							ALARMOUT = R_OFF; // turn off relay
						}
					}
				}
			}

			if (P.PRIPOWEROK && (R.inputvoltage > SOLARHIGH)) {
				sprintf(bootstr2, "Any discharged        ");
				LCD_VC_puts(VC0, DS0, YES);
				sprintf(bootstr2, "Batteries?           ");
				LCD_VC_puts(VC0, DS1, YES);
				wdttime(BATRUNF);
				sprintf(bootstr2, "---------------------");
				LCD_VC_puts(VC0, DS1, YES);

				ftest = 0;

				do {
					idle_loop();
					update_hist();
					bn = pick_batt(NO, NULL0);
					noload_soc();
					bn = pick_batt(battnum + 1, NULL0); // again to recheck for valid data
					boi = 0;
					if (cell[B1].online) boi = B1;
					if (cell[B2].online) boi = B2;
					if (bn != pick_batt(NO, NULL0)) bn = pick_batt(battnum + 1, NULL0); // double check

					if ((bn == B0) && (CCMODE == FLOAT_M)) {
						sprintf(bootstr2, "Battery #1 Float charge          ", bn);
						LCD_VC_puts(VC0, DS0, YES);
					} else {
						if (bn == B0) bn = boi; // try to make charger to to float on boi
						sprintf(bootstr2, "Battery #%i Full charge         ", bn);
						LCD_VC_puts(VC0, DS0, YES);
					}

					mkbsstring();
					wdttime(BATRUNF);
					ADC_read();
					if ((R.inputvoltage > SOLARHIGH)) {
						if ((bn == B0) && (CCMODE == FLOAT_M)) {
							voltfp(R.inputvoltage, f1);
							voltfp(R.ccvoltage, f2);
							ahfp(R.currentin, f3);
							sprintf(bootstr2, "P%s,B%s,%sA           ", f1, f2, f3);
							LCD_VC_puts(VC0, DS1, YES);

							if (BMMODE != FLOAT_M) {
								ChargeRelayOn(1, TRUE);
								BMMODE = FLOAT_M;
							}
						} else {
							term_time();
							putrs2USART(runcode5);
							BMMODE = CHARGE_M;

							ChargeBatt(bn, FALSE, TRUE);
							noload_soc();

							ChargeBatt(bn, TRUE, TRUE);
						}
					}
					ftest++;
					sprintf(bootstr2, "Battery #%i Exit       ", bn);
					LCD_VC_puts(VC0, DS0, YES);

					for (z = 1; z <= battnum; z++) {
						if (P.PRIPOWEROK) {
							if (P.SET_CEF) update_cef(z, P.SET_CEF); // check cef before we start charging
							bn = z; // set battery #
							ChargeBatt(bn, TRUE, TRUE); // check battery
							noload_soc(); // Setup soc on retesting
							update_hist();
						}
					}

					bn = pick_batt(NO, NULL0);
					if (bn != pick_batt(NO, NULL0)) bn = 0; // double check
				} while ((bn == B0) && (ftest < BFTEST)); // try to stay in this loop if floating
			}
			zero_amploc_PV(); // reset input sensor zero

			if (ftest++ >= BATTCHECK) { // force battery test after X loops
				//                                BCHECK = TRUE;
				ftest = 0;
			}
			term_time();
			putrs2USART(runcode10);
			wdttime(BATRUNF);
			for (z = 1; z <= battnum; z++) {
				if (cell[z].valid == cell[B0].valid) {
					noload_soc();
					update_hist();
					if (!P.PRIPOWEROK) {
						sprintf(bootstr2, "OVERRIDE CHRG #1");
						LCD_VC_puts(VC0, DS2, YES);

						mkbsstring(); // update primary battery voltage
						cell[B1].voltage = R.primarypower[B1]; // update cell[1] voltages for display and status
						cell[B1].noload = R.primarypower[B1];
						wdttime(BATRUNF);
					}
					voltfp(cell[z].charge, f1);
					sprintf(bootstr2, "B%i %sV                   ", z, f1);
					LCD_VC_puts(VC0, DS0, YES);

					voltfp(cell[z].noload, f1);
					voltfp(cell[z].voltage, f2);
					sprintf(bootstr2, "ul %sV,tl %sV          ", f1, f2);
					LCD_VC_puts(VC0, DS1, YES);

					if (cell[z].dead) {
						alarm_buffer[almctr].bn = z;
						alarm_buffer[almctr++].alm_num = 9;
						alarm_codes.alm_flag = TRUE;
						check_alarm(z, " main1 "); // possible dead battery
						battalarm(0, z, 0);
						cell[z].dead = FALSE;
						cell[z].critical = TRUE;
					}
					wdttime(BATRUNF);
				}
			}
			wdttime(BATRUNF);
			ADC_read();
		}

		s_crit(HL);
		waittime = V.timerint_count;
		e_crit();
		term_time();
		putrs2USART(runcode0);
		wdttime(BATRUNF);

		while (R.inputvoltage < SOLARLOW) { // wait until we have charging power
			solarup_delay = NULL0;
			idle_loop();
			check_alarm(CCS.boi, " main2 "); // send alarm codes to terminal if alm_flag is set
			sprintf(bootstr2, "Charge Power Low        ");
			LCD_VC_puts(VC0, DS0, YES);

			voltfp(R.inputvoltage, f1);
			voltfp(R.ccvoltage, f2);
			sprintf(bootstr2, "%s,%s %s               ", f1, f2, hms(((V.timerint_count - waittime))));
			LCD_VC_puts(VC0, DS1, YES);

			wdttime(BATRUNF);
			mkbsstring(); // update
			P.BCHECK = TRUE;
			ftest = 0;
			if (P.SYSTEM_STABLE && (((R.primarypower[CCS.boi] < BATTFLAT)
				&& (R.primarypower[CCS.boi] > BATTCRIT))
				&& (cell[CCS.boi].valid == cell[B0].valid))) { // check for low B1
				if (P.PRIPOWEROK) { // went from good to bad
					ALARMOUT = R_ON; // alert for bad power
				}
				//		P.PRIPOWEROK = FALSE; // set software flag and trigger HOUSE power charger/generator
				if (DIPSW4 == HIGH) {
					divert_power(OFF, YES, 0);
					if (R.currentin < CHARGER_MIN) {
						charger_power(ON, NO); // CHARGERL = R_ON; // RB0 is external battery charger/generator relay
						PVLOAD = R_OFF;
						alarm_buffer[almctr].bn = CCS.boc;
						alarm_buffer[almctr++].alm_num = 4;
						alarm_codes.alm_flag = TRUE;
					}
				}
				check_alarm(CCS.boi, " main3 "); // send alarm codes to terminal if alm_flag is set
			}
			noload_soc();
			update_hist();
			pick_batt(NO, NULL0);
			if ((model_update)) {
				model_learn(lmode);
			}
		}
		PVLOAD = R_ON;
		noload_soc();
		update_hist();
		term_time();
		putrs2USART(runcode1);

		ClrWdt(); // reset the WDT timer
	}
}

