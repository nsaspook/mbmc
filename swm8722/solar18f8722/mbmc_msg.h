#ifndef MBMC_MSG_H_INCLUDED
#define MBMC_MSG_H_INCLUDED
#include "mbmc.h"

const rom int8_t \
lowbatt0[] = "\n\r Reducing battey Ah rating due to possible discharged battery.\n\r",
	zero0[] = "\n\r Are all current inputs at zero current? y/n ",
	zero1[] = "\n\r Current sensors zero setpoints have been recalibrated.\n\r",
	zero2[] = "\n\r NOT changing current sensors zero calibration!\n\r",
	zero3[] = " PV Current sensor zero setpoint has been recalibrated.\n\r",
	zero4[] = "\n\r Please wait while inputs are switched off.\n\r",
	adcg0[] = "\n\r Select analog channel to calibrate. Enter 0-8 or n to exit. ",
	adcg1[] = "\n\r Analog channel has been recalibrated.\n\r",
	adcg2[] = "\n\r NOT changing analog channel gain calibration!\n\r",
	adcg3[] = "\n\r Press M/m to increase adc offset or L/l to decrease offset. Press Y to save or Q to exit and NOT save.\n\r",
	adcg4[] = "\n\r Saving analog channel gain calibration in EEPROM!\n\r",
	tweak0[] = "\n\r 1: AHIR Ah in  REAL\r\n 2: AHI  Ah in  ADJUSTED\r\n 3: AHO  Ah out REAL\r\n 4: AHOP Ah out ADJUSTED\r\n Select parameter to modify. Enter number or n to exit. \n\r",
	tweak1[] = " Exiting, Parameter has been modified.\n\r",
	tweak2[] = " Exiting, NOT changing Parameter!\n\r",
	tweak3[] = "\r\n Press M/m to increase or L/l to decrease in 100 or 5 units per button press.\r\n Press Y to save or Q to exit and NOT save.\n\r",
	tweak4[] = " Updating parameter in active process memory!\n\r",
	tweak5[] = "\r\n 10X, Press M/m to increase or L/l to decrease in 1000 or 50 units per button press.\r\n Press Y to save or Q to exit and NOT save.\n\r",
	tweak_t1[] = "AHIR",
	tweak_t2[] = "AHI",
	tweak_t3[] = "AHO",
	tweak_t4[] = "AHOP",
	tweak_tw[] = "Wrong Parameter",
	hello0[] = "\n\r SolarPIC MBMC for PIC18F8722 multi-battery monitor and charger - nsaspook@nsaspook.com GPL  MBMC ",
	hello1[] = "\r\x1b[0m S/N 000001 ",
	hold0[] = "\n\r MBMC Monitor is held in the current state until released, \n\r Press y key to release. ",
	hold1[] = "\n\r MBMC Monitor has been released and is running.\n\r",
	sync0[] = "\n\r Set battery currently charging to 100% SOC? y/n ",
	sync1[] = "\n\r Battery SOC set to 100%.\n\r",
	sync2[] = "\n\r Battery SOC NOT changed.\n\r",
	keycmds0[] = "\n\r KEY CMDS: # Display run data, * Reset SOC to 100% on BOC, V charger on,\r\n v Charger off, ! Hold Program, ^ Reset current zero cal, T tweak battery run data\n\r",
	keycmds1[] = " KEY CMDS: H dump all SD records to comm2, h dump last 1000 SD records to comm2,\r\n K Lock program causing reboot, g ADC channel Cal, D diversion ON, d diversion OFF,\n\r w Clear Water Flag\r\n",
	keycmds2[] = " SOC Methods: R Rest Voltage SOC, S Static boot SOC, C Amp counting,\r\n Blended SOC methods: M Not Charging, F Skew, L Loaded\r\n",
	battheader0[] = " # CI  mV B1  mV B2  mVSOC    Ah    mAhir    mAhi    mAho      WHi     WHo DOD  BSOC  RSOC    RUN  Weight  CESR   LESR\n\n\r Battery History:\r\n",
	battheader1[] = " #     LDE    LDC     AD    ACC    FCC    FDC   AHUP  MINBV  MAXBV    AHUR    WHIN   WHOUT  CEF  CEF_CAL CEF_SAV BS_AHU AHIR  BS_AHI  BS_AHO  CEF_RAW\n\r",
	battheader2[] = " #     0.1A   0.1A   0.1A     Battery Cycles    0.1A  Battery Volts   0.1A    0.1 WattHour  Charge efficiency    Program Data Factors\n\n\r",
	modelheader0[] = " Battery Model Data Display\n\n\r",
	modelheader1[] = " Battery Model Data \n\n\r",
	battbuffer0[] = " Block_buffer overflow >SDBUFFERSIZE \r\n",
	sddump0[] = " #### \x1b[7mNo SDCARD Found, Goodbye\x1b[0m ####\r\n",
	sddump1[] = " #### \x1b[7mWrong Type SDCARD Found, Goodbye\x1b[0m ####\r\n",
	sddump2[] = " Update EEP/SD data.\r\n",
	sddump3[] = " Update EEP/SD data, New SDCARD Installed.\r\n",
	sddump4[] = " SD data dumped, New log started.\r\n",
	divert0[] = " D0  AC Power diversion is ON\r\n",
	divert1[] = " D1  AC Power diversion is OFF, Bits 4-7: PVV,SOC,DIV,DIW \r\n",
	divert99[] = "";

const rom int8_t \
almcode0[] = " A0  Charger on, Battery Low.\r\n",
	almcode1[] = " A1  Charger on, Low Primary Battery, in irq.\r\n",
	almcode2[] = " A2  Charger off, Battery Fresh.\r\n",
	almcode3[] = " A3  Charger off, Failsafe Mode.\r\n",
	almcode4[] = " A4  Charger on, Low Primary battery, in main.\r\n",
	almcode5[] = " A5  Charger on, Battery value SOC, Morning Help.\r\n",
	almcode6[] = " A6  Charger off, Battery value SOC, Morning Help.\r\n",
	almcode7[] = " A7  Charger off, PV Voltage or Current too High while charger is on.\r\n",
	almcode8[] = " A8  Charger, PV below SOLARDOWN value EOD.\r\n",
	almcode9[] = " A9  Charger Alarm on, Possible Dead Battery.\r\n",
	almcode10[] = " A10 Day Clock, PV above SOLARUP value Daily Status reset BOD.\r\n",
	almcode11[] = " A11 Charger off, Command or Logic.\r\n",
	almcode12[] = " A12 Charger on,  Command or Logic.\r\n",
	almcode13[] = " A13 Possible Utility AC power glitching.\r\n",
	almcode14[] = " A14 AC power is off.\r\n",
	almcode15[] = " A15 AC power is on.\r\n",
	almcode16[] = " A16 Possible Inverter AC power glitching.\r\n",
	almcode17[] = " A17 Program Error detected.\r\n",
	almcode18[] = " A18 Cooling Fan turned on due to heat or high current.\r\n",
	almcode19[] = " alert_pick Done.\r\n",
	almcode20[] = " Vent Fan is OFF.\r\n",
	almcode99[] = "";

const rom int8_t \
chrgcode0[] = " C0  Charging stopped, Battery overvolt limit.\r\n",
	chrgcode1[] = " C1  Charging stopped, PV voltage too low (normal).\r\n",
	chrgcode2[] = " C2  Charging stopped, Terminal FORCEOUT.\r\n",
	chrgcode3[] = " C3  Charging stopped, Battery in FLOAT cycle.\r\n",
	chrgcode4[] = " C4  Charging stopped, PV voltage too low (critical).\r\n",
	chrgcode5[] = " C5  Charging, ABSORP time remaining.\r\n",
	chrgcode6[] = " C6  Charging, OVERRIDE MODE.\r\n",
	chrgcode7[] = " C7  Charging, Battery load test complete.\r\n",
	chrgcode8[] = " C8  Charging, Started, Begin routines.\r\n",
	chrgcode9[] = " C9  Charging, Done, Exit routine.\r\n",
	chrgcode10[] = " C10 Charging, Battery load test starting.\r\n",
	chrgcode11[] = " C11 Charging, Battery load test return.\r\n",
	chrgcode12[] = " C12 Charging, In main charge loop routine.\r\n",
	chrgcode13[] = " C13 Charging, Charger relay switched off.\r\n",
	chrgcode14[] = " C14 Charging, POWER UNSTABLE exit from charging.\r\n",
	chrgcode15[] = " C15 Charging, Skipped battery testing.\r\n",
	chrgcode16[] = " C16 Charging, Critical Battery Tested.\r\n",
	charger0[] = "\n\r C17 Battery in float, charger relay switched off.\n\r",
	charger1[] = " \x1b[7mC18 Inverter battery low WEIGHT, BATTERY PROTECTION UNDER LOAD, charger relay switched on.\x1b[0m \n\r",
	charger2[] = " C19 No charger power detected, charger relay switched off. #### \x1b[7mCHECK MAIN INTPUT FUSE\x1b[0m ####\n\r",
	charger3[] = " C20  AC Power Charger is ON\r\n",
	charger4[] = " C21  AC Power Charger is OFF\r\n",
	charger5[] = "\n\r C22 Battery in float before absorption time reached.\n\r",
	charger99[] = "";

const rom int8_t \
runcode0[] = " R0  Running,  Checking for Low PV Voltage.\r\n",
	runcode1[] = " R1  Running,  PV voltage above low setpoint.\r\n",
	runcode2[] = " R2  Running,  Starting Battery Check.\r\n",
	runcode3[] = " R3  Running,  System Ready, Starting up Monitor Operation.\r\n",
	runcode4[] = " R4  Running,  Battery CRITICAL charge cycle\r\n",
	runcode5[] = " R5  Running,  Battery NORMAL charge cycle.\r\n",
	runcode6[] = " R6  Running,  Battery exiting, charging in FLOAT cycle.\r\n",
	runcode7[] = " R7  Running,  Alert from Pick Battery.\r\n",
	runcode8[] = " R8  Running,  Battery holding, charging in FLOAT cycle.\r\n",
	runcode9[] = " R9  Running,  Setting battery to fully recharged.\r\n",
	runcode10[] = " R10 Running,  Checking Battery load voltages.\r\n";

// SDCARD data acsii format
const rom int8_t sd_data_layout1[] = "\r\n#,%lu,%u,%u,%u,%lu,%lu,%lu,%li,%li,%li,%li,%li,%li,%li,%li,%li,%li,%li"; // printf string format part1
const rom int8_t sd_data_layout2[] = ",#,%u,%u,%u,%lu,%lu,%lu,%lu,%lu,%li,%li,%li,%u,%u,%li,%u,%u,%li,%c,%c,%c,%c,%lu,%lu,%i"; // printf string format part2
const rom int8_t sd_data_layout3[] = ",#,%i,%i,%i,%li,%li,%li,%li,%li,%i,%i"; // printf string format part3
const rom int8_t sd_data_layout4[] = ",#,%u,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%u,%lu,%u,%u,%u,%u,%c"; // printf string format part4
const rom int8_t sd_data_layout5[] = ",#"; // printf string format part5 , terminate

#endif /* MBMC_MSG_H_INCLUDED */

