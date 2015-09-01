// defines and structures for MBMC networking
#define	__MBMCAPP_C
#define MBMC_VERSION "    MBMC  10.6B FB  "
#define	MAGIC		0x0106  // data version checkmark
#define	CHECK_DATE	1305123894ul

#define MASK9BIT	0x0100
#define	MBMC_CHART_POINTS	24
#define	LPCHAN	16

/* PV array defines */
/* array spec V,I,P	*/
#define A_VPM		17300.0 // array voltage at power max, millivolts units
#define	A_IPM		190.75  // array current at power max,  0.1 A units
#define	A_SSC		210.75  // array short circuit current, 0.1 A units
#define	PV_MAX		3299975 // max possible power/10000 for W

/* battery Ah caps	*/
#define B1AH		225     // FLA costco
#define	B2AH		200     // FLA bi-mart
#define B3AH		12      // gell cell
#define	B4AH		12      // gell cell
#define	PerkC1		1.26    // Peukert Comp Batt #1
#define PerkC2		1.30	// Peukert Comp Batt #2
#define Perk_ADJ_FL	0.5		// If the peukert_adj is below this, make it this the Ah adjustment factor
#define	CEFH		.80     // Charge Efficiency Factor, high SOC
#define	CEFL		.92     // Charge Efficiency Factor, low SOC
#define	CEF_RATE	80      // derate CEF above this
#define	DF			1.0     // discharge floor of battery total Ah
#define	DCURRENT	0.0     // default discharge current 0.1A units "3.6 is the lowest possible value = .36Ah", use AH_DAY_OFF
#define	AH_DAY_LOSS1	10      // Ah lost in 24 hours from natural discharge or controller use BATT1.
#define	AH_DAY_LOSS2	10      // Ah lost in 24 hours from natural discharge or controller use BATT2.
#define	SS_RATE		2.5     // STATIC SOC RATE Ah factor for static voltage cal to SOC

#define	HELP_SOC	65      // state of charge to begin charger help in morning
#define SOCFULL		88      // this is as good a full charge after a full C40 cycle timeout or float

#define SDINFO	0			// SD card data info block
#define SDSTART	1			// SD card first data block
#define	SDC0EEP	510         // start address of SD mirror block data in EEPROM

#include <GenericTypeDefs.h>

struct harvesttype{
        LONG energy, usage, prev_energy, prev_usage, e_total, u_total; 
		LONG count, charger, c_total, prev_charger, diversion;
};

typedef struct SDCARD {
        WORD magic;
        BYTE sdtype, sdinit, sddetect, DAYCLOCK;
        DWORD sdpos, sdnext, timekeep, time;
        struct harvesttype harvest;
        SHORT h[2][9];                  // battery history data
} SDCARD_TYPE;

typedef struct SD_VOLUME_INFO {
        DWORD size_MB;
        DWORD sector_multiply, read_block_len;
        DWORD sector_count, serial;
        BYTE name[6];
} VOLUME_INFO_TYPE;

typedef struct SDDUMP {
        BYTE dumping, type;
        DWORD sdpos;
} SDDUMP_TYPE;

struct ccstype {
        BYTE pick, boi, boc, alert, bn;
};

#if defined(__MBMC_C)
struct celltype {							// C18 uses byte alignment
#else
struct __attribute__((aligned(1))) celltype {	// force C32 to byte alignment
#endif
        WORD id;                      //      battery cell type S,M,L
        LONG voltage, current, charge, cycles, noload, date;
        BYTE cconline, online, discharged, dead, critical, valid, fresh;
        float weight;
};

#if defined(__MBMC_C)
struct histtype {							// C18 uses byte alignment
#else
struct __attribute__((aligned(1))) histtype {	// force C32 to byte alignment
#endif
        WORD peak, rate, soc, bsoc, ce, cb, samplei, sampleo, ah, drate,esr;
        SHORT h[9];							// h[6]=cumulative battery Ah cc and inv (real),h[0]=cumulative battery Ah cc and inv (p_adj)
        LONG kwi, kwo, ttg;
        LONG ahi, aho, ahir, ahop, thermo;			// A stored in battery, A taken from battery, A from raw pv, peukert adjusted A
        LONG pv_eff, tot_eff;         		// pv generation eff factor, total system eff factor
        float peukert, cef, peukert_adj;
};

struct buttype {
        DWORD bvi, bvo;
        SHORT boc, boi;
        LONG bii, bio, bil;
};                              // battery voltage in/out, battery  current in/out/load ,battery on charge, battery on inverter, battery inverter load

struct almtype {
        BYTE	alm_flag, alm_num;
};

struct mbmccmdtype {
        WORD	ready,cmd;
};

struct datadefaulttype {
		DWORD	data_default;
};

struct lcdb {
        CHAR b[22];
};

struct timeruntype {
        DWORD hour, day, weeks;
};

struct mbmcnettype {
        BYTE 	*mbmc_byte;
		WORD	mbmc_index,mbmc_len;
};

/*
 *
 * This application is designed for use with the
 * ET-BASE PIC8722 board, LCD display and XANTREX C40 charge controller.
 *
 * RS-232 host commands 9600baud 8n1
 * A		send controller/battery status
 * B		select battery for modify commands, used with S M L
 * C		(NOT DONE YET)
 * D 		Calibrate ADC voltages.
 * E		When in FAIL-SAVE mode switch to second battery
 * F		Force current (none critical) charge routine to exit
 * H		Dump all SD card data records to comm1 port
 * h		Dump last 10000 SD card data records to comm1 port
 * K		lockup controller causing WDT timer to reboot
 * S M L	modify selected battery type, example: ZBBMZ would set battery 2 to M type.
 * V		toggle external charger on/off
 * v		turn external charger off
 * Z		reset command parser
 * ?		Send help menu to rs-232 terminal
 * $		fuse blown error. (NOT DONE YET)
 * ^		reset current sensor zero calibration
 * !		hold program in present date
 * *		set battery on CC to 100% SOC
 * #		display run data on terminal rs-232 port
 *
 */



#define	HOST_REQ	'0'		// request mbmc ID
#define	HOST_ACK	'1'		// data ack code, returned when finished
#define	HOST_REAL	'2'		// send mbmc realtime data
#define	HOST_CELL	'3'		// send cell data stucture
#define	HOST_HIST	'4'		// send history data structure
#define HOST_SDC0	'5'		// send a SDCARD sector
#define	HOST_CMD_F	'F'		// send FORCEOUT command to solar controller
#define	HOST_CMD_V	'V'		// send charger toggle command to solar controller
#define	HOST_CMD_v	'v'		// send charger off command to solar controller
#define	HOST_CMD_SOC	'*'		// send set SOC command to solar controller
#define	HOST_CMD_UTC_S	'6'		// start xmit of UTC time to controller
#define	HOST_CMD_UTC_E	'7'		// end xmit of UTC time to controller

// message text
#if defined(__MBMC_C)

#define BCRELAYS	PORTE
#define IORELAYS	PORTJ
#define	DIPSW		PORTD
#define	EXTIO		PORTB


const rom char tekbox[] = { 0x1d, 0x20, 0x60, 0x20, 0x40, 0x60, 0x3f, 0x5f, 0x37, 0x7f, 0x5f, 0x7f, 0x20, 0x40, 0x20, 0x60, 0x40, 0x1f },
lowbatt0[] = "\n\r Reducing battey Ah rating due to possible bad battery.\n\r",
zero0[] = "\n\r Are all current inputs at zero current? y/n ",
zero1[] = "\n\r Current sensors zero setpoints have been recalibrated.\n\r",
zero2[] = "\n\r NOT changing current sensors zero calibration!\n\r",
adcg0[] = "\n\r Select analog channel to calibrate. Enter 0-8 or n to exit. ",
adcg1[] = "\n\r Analog channel has been recalibrated.\n\r",
adcg2[] = "\n\r NOT changing analog channel gain calibration!\n\r",
adcg3[] = "\n\r Press M/m to increase adc offset or L/l to decrease offset. Press Y to save or Q to exit and NOT save.\n\r",
adcg4[] = "\n\r Saving analog channel gain calibration in EEPROM!\n\r",
hello0[] = "\n\r SolarPIC PIC18F8722 multi-battery monitor and charger - nsaspook@nsaspook.com GPL  MBMC ",
hold0[] = "\n\r Solar Monitor is held in the current state until released, \n\r Press y key to release. ",
hold1[] = "\n\r Solar Monitor has been released and is running.\n\r",
sync0[] = "\n\r Set battery currently charging to 100% SOC? y/n ",
sync1[] = "\n\r Battery SOC set to 100%.\n\r",
sync2[] = "\n\r Battery SOC NOT changed.\n\r",
charger0[] = "\n\r Battery in float, charger relay switched off.\n\r",
charger1[] = "\n\r Inverter battery low, charger relay switched on.\n\r",
keycmds0[] = "\n\r KEY CMDS: # Display run data, * Reset SOC to 100% on BOC, V Toggle charger,\r\n v Charger off, ! Hold Program, ^ Reset current zero cal\n\r",
keycmds1[] = " KEY CMDS: H dump all SD records to comm1, h dump last 10000 SD records to comm1,\r\n K Lock program causing reboot, D ADC channel cal\r\n",
battheader0[] = " # CI  mV B1  mV B2   mAhir    mAhi    mAho      Wi      Wo  SOC  BSOC    RUN   Weight   ESR\n\n\r",
battheader1[] = " #     LDE    LDC     AD    FCC    FDC    AHU  MINBV  MAXBV \n\n\r",
battbuffer0[] = " Battbuffer overflow >512 \r\n",
divert0[] = " AC Power diversion is ON\r\n",
divert1[] = " AC Power diversion is OFF\r\n";

const rom char 	almcode0[] = " Charger on,0 Battery Low.\r\n",
almcode1[] = " Charger on,1 Low Primary Battery, in irq.\r\n",
almcode2[] = " Charger off,2 Battery Fresh.\r\n",
almcode3[] = " Charger off,3 Failsafe Mode.\r\n",
almcode4[] = " Charger on,4 Low Primary battery, in main.\r\n",
almcode5[] = " Charger on,5 Morning Help.\r\n",
almcode6[] = " Charger off,6 Morning Help.\r\n",
almcode7[] = " Charger off,7 PV High in Float Mode.\r\n",
almcode8[] = " Charger,8 .\r\n",
almcode9[] = " Charger Alarm on,9 Possible Dead Battery.\r\n",
almcode10[] = " Day Clock,10 Daily Status reset.\r\n";

const rom char 	chrgcode0[] = " Charging stopped,0 Battery overvolt limit.\r\n",
chrgcode1[] = " Charging stopped,1 PV voltage too low (normal).\r\n",
chrgcode2[] = " Charging stopped,2 Terminal FORCEOUT.\r\n",
chrgcode3[] = " Charging stopped,3 Battery in FLOAT cycle.\r\n",
chrgcode4[] = " Charging stopped,4 PV voltage too low (critical).\r\n",
chrgcode5[] = " Charging,5 .\r\n",
chrgcode6[] = " Charging,6 OVERRIDE MODE.\r\n",
chrgcode7[] = " Charging,7 Battery load test.\r\n",
chrgcode8[] = " Charging Started,8 Begin routine.\r\n",
chrgcode9[] = " Charging Done,9 Exit routine.\r\n";

const rom char 	runcode0[] = " Running,0  Checking for Low PV Voltage.\r\n",
runcode1[] = " Running,1  PV voltage above low setpoint.\r\n",
runcode2[] = " Running,2  Starting Battery Check.\r\n",
runcode3[] = " Running,3  System Ready, Starting up Monitor Operation.\r\n",
runcode4[] = " Running,4  Battery CRITICAL charge cycle\r\n",
runcode5[] = " Running,5  Battery NORMAL charge cycle.\r\n",
runcode6[] = " Running,6  Battery exiting, charging in FLOAT cycle.\r\n",
runcode7[] = " Running,7  Alert from Pick Battery.\r\n",
runcode8[] = " Running,8  Battery holding, charging in FLOAT cycle.\r\n",
runcode9[] = " Running,9  Setting battery to fully recharged.\r\n";
#endif

// SDCARD data format structure using TypeDefs for pic32 host
#if defined(__MBMC_C)
typedef struct mbmcdata {							// C18 uses byte alignment
#else
//#pragma pack(1)
typedef struct  __attribute__((aligned(1))) mbmcdata {							// force C32 to byte alignment
#endif
		LONG			solar, inputvoltage, primarypower_B1, primarypower_B2, vbatol;
		LONG			currentin, current, currentload;
        LONG 			thermo_batt;
        LONG			PRIPOWEROK, DIPSW;
		LONG			pick, boi, boc, alert, bn;
		LONG			CHARGER_B, DIVERSION_B;
		LONG			MBMCID,UTC;
        struct 			harvesttype harvest;
//		LONG			crc;
} mbmctype;        

typedef struct mbmcchart {
	struct mbmcdata	data[MBMC_CHART_POINTS];
	DWORD			sdate,edate,start;
	BYTE			pos,gap;
	float			avg;
} mbmccharttype;

#if defined(__MBMC_C)
#else
//#pragma pack()
#endif

struct	mbmcflagtype {
	WORD	mbmc_cmd,mbmc_data,mbmc_ack;
	WORD	host_cmd,host_data,host_ack;
	DWORD	cmd_timeout,host_timeout,data_timeout,data_len,data_pos;
	BYTE	rx_9bit,tx_9bit,mbmc_done,host_done,*data_ptr;
};

struct mbmcstatustype {
	BYTE	seq;
	BYTE	real_valid;
	BYTE	cell_valid;
	BYTE	hist_valid;
	BYTE	sdco_valid;
	BYTE	cmd_valid;
	DWORD	sent;
	DWORD	received;
	DWORD	cmdsent;
	DWORD	cmdreceived;
	DWORD	acksent;
	DWORD	ackreceived;
};

/* SD data fprint code
                sprintf ( battstatus,
                          "\r\n^^^,1,%lu,%u,%u,%u,%lu,%lu,%lu,%lu, %li,%li,%li,%li,%li,%li, %li,%li,%li,%li, %lu,%lu,%lu,%lu,%lu,%u,%u, %lu,%lu,%lu,%lu,%lu,%li,%li,%li, %u,%u,%u,%u, %c,%c,%c,%c",
                          timerint_count, PRIPOWEROK, DIPSW, SDC0.DAYCLOCK, SDC0.sdpos, SDC0.sdnext, SDC0.timekeep, SDC0.time,
                          SDC0.harvest.energy, SDC0.harvest.usage, SDC0.harvest.prev_energy, SDC0.harvest.prev_usage, SDC0.harvest.e_total, SDC0.harvest.u_total,
                          SDC0.harvest.count, SDC0.harvest.charger, SDC0.harvest.c_total, SDC0.harvest.prev_charger,
                          commint_count, buttonint_count, highint_count, lowint_count, worker_count, CHARGER, DIVERSION,
                          vbatol, solar, inputvoltage, primarypower[B1], primarypower[B2], currentin, current, currentload,
                          cell[1].cconline, cell[1].online, cell[2].cconline, cell[2].online, 
						  cell[1].id, cell[2].id, cell[3].id, cell[4].id );

                for ( z = 1; z <= BATTNUM; z++ ) {                      // create
                        sprintf ( battstatus + strlen ( battstatus ),
                                  ",%u,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%u,%lu,%u", z, cell[z].noload,
                                  cell[z].voltage, hist[z].ahi, hist[z].aho, hist[z].ahop, hist[z].kwi,
                                  hist[z].kwo, hist[z].soc, hist[z].ttg ,hist[z].esr);
                }

                strcatpgm2ram ( battstatus, ",###" );

*/

