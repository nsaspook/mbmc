#ifndef MBMC_DEFS_H_INCLUDED
#define MBMC_DEFS_H_INCLUDED
/* Program operation parameters for MBMC controller */
#define MBMC_VERSION 	"    MBMC  30.4 FB  "                  // version text header
#define	MAGIC		0x0304  				// data version checkmark
#define	START1		"Power Up, Init started, Fred Brooks"	// first LCD message
#define BOOT_ALM1       "Boot ALM, Press ALM ACK Button     "   // boot code message
#define SIMULA		" \x1b[7m RUNNING IN SIMULATION MODE \x1b[0m "
#define	PIC_8722	8722
#define	CHECK_DATE	1305123894ul
#define CHECKMARK	0x57					// EEPROM checkmark
#define CHECKMARK_CRC	0x57575757ul				// 32 bit crc checkmark
#define MAXSECONDS      31557600ul*10ul // 10 years
#define EEPROM_BAT	0
#define EEPROM_ADC	8
#define EEPROM_HIS	32

#define	TIMEROFFSET	26474           // timer0 16bit counter value for 1 second to overflow
#define	TIMER3REG	3048            // timer3 value for 20Hz clock
#define BUF_SIZE 	128
#define LOW			(uint8_t)0               // digital output state levels, sink
#define	HIGH		(uint8_t)1               // digital output state levels, source
#define	ON			LOW       		//
#define OFF			HIGH			//
#define	S_ON		LOW       		// low select/on for chip/led
#define S_OFF		HIGH			// high deselect/off chip/led
#define	R_ON		LOW       		// control relay states, relay is on when output gate is low
#define R_OFF		HIGH			// control relay states
#define NO			LOW
#define YES			HIGH
#if defined(__18CXX)
#define NULL0           (uint8_t)0
#else
#define NULL            ((void *)0)
#endif
#define SHIFT1          1
#define SHIFT2          2
#define SHIFT4          4
#define SHIFT6          5
#define SHIFT7          7
#define SHIFT8          8
#define SHIFT9          9
#define SHIFT16         16
#define SHIFT24         24
#define SHIFT30         30
#define	ERR1			1
#define	ERR2			2
#define	XON				0x11
#define	XOFF            0x13
#define	H				1
#define	L				2
#define	HL				3
#define	BMT_FLAG_0	0b00000001      // soc 100 tested and saved
#define BMT_FLAG_1	0b00000010      //
#define	BMT_FLAG_2	0b00000100
#define BMT_FLAG_3	0b00001000
#define	BMT_FLAG_4	0b00010000
#define BMT_FLAG_5	0b00100000
#define	BMT_FLAG_6	0b01000000
#define BMT_FLAG_7	0b10000000      //
#define	PWM_FLAG_OK	0b00000001      // OK to divert power via PWM
#define PWM_FLAG_1	0b00000010      //
#define	PWM_FLAG_2	0b00000100
#define PWM_FLAG_3	0b00001000

/* LCD defines */
#define LCD_L           4			// lines
#define LCD_W           20			// chars per line
#define LCD_STR         LCD_W+2		// char string for LCD messages
#define MESG_W          212			// message string buffer
#define	LL1		0x00				// LCD line addresses
#define	LL2		0x40
#define LL3		0x14
#define	LL4		0x54
#define	VC_MAX		3
#define VS_SLOTS	12		// storage array size
#define	VC0		0			// LCD Virtual Screens
#define	VC1		4
#define	VC2		8
#define VS0		0			// Virtual screen select
#define VS1		1
#define VS2		2
#define	DS0		0			// LCD line index
#define	DS1		1
#define	DS2		2
#define	DS3		3
#define	DS4		4
#define	DS5		5
/* DIO defines */

#define LOW_VECTOR      0x18            // ISR low address
#define HIGH_VECTOR     0x8             // ISR high address
#define POWER_SLOTS		3				// realtime battery voltage array size, 0 is the null battery

#define	CCLED		PORTCbits.RC0
#define	SDSAFE		LATCbits.LATC1   	// SD card is safe to remove
#define	SDPOWER		LATAbits.LATA4		// SD card 3.3vdc power enable
#define SPI_CS 		LATCbits.LATC2
#define SOLAROFF	LATJbits.LATJ7
#define	CHARGERL	LATJbits.LATJ5
#define VENTFAN		LATJbits.LATJ6
#define ALARMOUT	LATJbits.LATJ4
#define BAT1		LATEbits.LATE0
#define BAT2		LATEbits.LATE1
#define BAT3		LATEbits.LATE2
#define BAT4		LATEbits.LATE3
#define	CHRG1		LATEbits.LATE4
#define	CHRG2		LATEbits.LATE5
#define	CHRG3		LATEbits.LATE6
#define	CHRG4		LATEbits.LATE7
#define	DIVERSION	LATJbits.LATJ0
#define	BATLOAD		LATJbits.LATJ1		// low current battery load
#define BATLOAD_HI	LATGbits.LATG4		// high current battery load
#define	CCOUTOPENSW	LATJbits.LATJ2
#define	PVLOAD		LATJbits.LATJ3
#define	COOLFAN		LATJbits.LATJ3
#define MPULED		LATHbits.LATH0
#define	DIPSW1		PORTDbits.RD0
#define	DIPSW2		PORTDbits.RD1
#define	DIPSW3		PORTDbits.RD2
#define	DIPSW4		PORTDbits.RD3
#define	DIPSW5		PORTDbits.RD4           //      GANGED Mode
#define	DIPSW6		PORTDbits.RD5
#define	DIPSW7		PORTDbits.RD6
#define	DIPSW8		PORTDbits.RD7
#define	HIDLED		LATBbits.LATB0   	//      mode lamp  PORT B is cross wired
#define	AC_OFF_U	PORTBbits.RB1   	//	if input is high the AC power from the Utility off
#define	TIMESIG		LATBbits.LATB2   	// 	Test pin for timing measurements
#define	AC_OFF_I	PORTBbits.RB3		//	if input is high the AC power from the Inverter off
#define	HID1		PORTBbits.RB4   	//      mode switch N/O
#define	PERKOSWI	PORTBbits.RB5		//	Battery selector switch
#define	HID2		PORTBbits.RB6   	//  	mode switch N/C
#define	STFU		PORTBbits.RB7   	//  	alarm ack switch

#define LOADNOTFAN	FALSE			//      Is the cooling fan and pv load on the same pin
#define COOL_ON		320                     //	start cooling temp in 0.01C units
#define COOL_OFF	240			//	stop cooling
#define CC_HIGHPOWER    200                     //      20A in 0.1A units 1/2 C40 Max current rating, cooling fan should start running.
#define	COOL_MAX	1000			//	invalid temp (I hope)
#define	BLINK_RATE	20000
#define	BATRUN 		15       	//
#define	BATRUNF		5       	// faster delay
#define BATRUNS		500             // Really long time
#define	BATTEST		40       	// full load testing time
#define BATTEST_SLOPE	2		// Short time to find discharge slope
#define BATTREST	3600		// rest time for battery voltages to settle after a charge cycle
#define	CHRGTIME	50      	// charged alarm time
#define SDTIME		30       	// SD card timeout
#define	SUPDELAY	60			// solarup delay for start of day
#define DAYDELAY	86400		// Seconds in 24 hours
#define DARKDELAY	3600		// darkness delay, a few hours total
#define	BATCHARGE_S	7200    	// seconds in 2 hours
#define BATCAP_S	9       	// battery capacity range at 20H discharge rate
#define	BATCHARGE_M	21600   	// seconds in 6 hours
#define BATCAP_M	100
#define	BATCHARGE_L	43200   	// seconds in 12 hours
#define BATCAP_L	225
#define	BTEST_DELAY	1800		// seconds between battery tests
#define BFTEST		10			// number of loops for the charge loop
#define	TIMEOFF		60      	// seconds in 1 min
#define	WORKSEC		10      	// run every this time seconds
#define DISPSEC		600			//
#define ADC_STEP	488     	// mv per dac step
#define	ADC_MULT	344     	// voltage div factor
/* Solar input voltage limits */
#define SOLARUP		11000ul		// Voltage from PV array that starts the day
#define	SOLARDOWN	2000ul		// Voltage from PV array that ends the day
#define SOLARHIGH	6100ul    	// Voltage from PV array to start charger connections
#define	SOLARLOW	6000ul    	// Voltage from PV array to stop charger connections
#define LOADLOW		1000ul		// always turnoff the load below this
#define PWMHIGH		14200ul		// input voltage from PV to start PWM loads
#define DVOLTAGE        12100ul         // lowest voltage while running diversion.
#define GANGEDHIGH      13800ul         // voltage limit to supply controller voltage while ganged
#define GANGEDHYST      14500ul         // upper limit to disconnect from supplying power

/* battery condition defines */
#define	LOAD_CHECK	100l		// 10A load
#define	AHADJ		0.33		// dyn Ah adjustment factor for very low SOC, reduce the actual rate by this amount
#define	CHRG_HIGH	18000ul   	// max voltage while in a charge cycle to have charger on.
#define BATTHIGH	16500ul   	// over-voltage point from charge controller
#define BATTABSORP	14000ul     // absorption voltage min
#define BATTFRESH	13200ul   	// float voltage after charge
#define	BATTADJ		11800ul		// >15%	At this point under load start adjusting the Ah used by a static amount
#define BATTFLAT	11400ul		// Close to full discharged (flat but usable)
#define BATTCRIT	10900ul   	// Fully discharged
#define BATTSYS		9000ul		// controller system voltage critical level
#define BATTSYSLOW	10500ul		// controller system voltage low
#define BATTLOW		8000ul		// unuseable (damaged) battery
#define	BATTDROP	5000ul		// Max voltage drop from unloaded to test test loaded
#define BATTBOOST	200ul		// hyst voltage
#define BATTCHECK	5          	// number of battery rechecks
#define BATTWATER	500000ul	// charging in seconds before checking the water levels in the battery.
#define BLOAD1		50l       	// load resistor in ohms*10
#define BLOAD2		25l       	// ditto
#define GELL_R_COMP     760L            // voltage drop from current limiting during testing.
#define AGM_R_COMP		200L            // voltage drop from current limiting during testing.
#define GELL_ESR_COMP   660L            // voltage drop from current limiting static.
#define AGM_ESR_COMP	100L            // voltage drop from current limiting static.
#define B0B				0		// null battery
#define	B1B				1
#define	B2B				2
#define B3B             3
#define B4B             4
#define	VENTTIME	1200
#define D_TIME		1800		// power diversion timeouts seconds
#define C_TIME		600			// charger power timeouts seconds
#define	MAXRUNTIME	95.0
#define MINRUNTIME	0.05
#define	VENTENABLE	HIGH
#define	LOGGERTIME	30

/* ADC scaling defines */
#define AMP300_OF	521ul		// dc offset for amploc amp300 sensor raw bit count
#define AMP300_MAX	2380ul		// Vo at max current n/a
#define AMP300_SEN	8ul			// mV/A
#define AMP50_OF	510ul		// dc offset for amploc amp50 sensor raw bit count
#define AMP50_MAX	11400ul		// Vo at max current n/a
#define AMP50_SEN	23ul		// mV/A
#define AMP50c_OF	510ul		// dc offset for amploc amp50 sensor raw bit count
#define AMP50c_MAX	11400ul		// Vo at max current n/a
#define AMP50c_SEN	23ul		// mV/A
#define	AMPZ		2			// ADC value less that this is still zero.
#define	THERMO_OFF	420			// adc counts for 0C
#define	THERMO_SEN	0.2875		// C per adc count

/*	ADC offsets	defines */
#define ADC0_OFF	1713
#define ADC1_OFF	1630
#define ADC2_OFF	488
#define ADC3_OFF	2423
#define ADC4_OFF	1910
#define ADC5_OFF	488
#define ADC6_OFF	1910
#define ADC7_OFF	488
#define ADC8_OFF	488
#define ADC9_OFF	488
#define ADC10_OFF	488		// Ground REF connection
#define	ADC_SLOTS	14		// 14 ADC data slots + 1 checksum at the end
#define ADC_INDEX	8		// max adc gain array select number
#define ADC_NULL	127		// zero offset value
/* The number of samples must be high to sample several complete PWM cycles from the CC to get stable voltage and current measurements at lower ranges. */
#define ADC_SAMP_F	128
#define ADC_SAMP_S	512
#define ADC_CHAN_DELAY	100		// delay in 10X chip cycles after switching ADC channels

/* Charge controller condition defines	*/
#define	VCP		13200ul   	// Voltage at full charge
#define	CCP		4       	// precent of bank cap full charged current.
#define	CTP		4       	// time at VCP

/* C40 LED reading defines	*/
#define CCLEDTIME	2400    // wait time (seconds) of solid LED on for charge completed flag from C40 in FLOAT mode
#define	CCFLOATTIME	1200    // seconds to check to see if we continue in float
#define	CCLEDBLINK	14     	// seconds to count blink clocks.
#define CCONEBLINK	25      // C40 is working
#define CCFOURBLINKS    77 	// C40 in absorption mode
#define	CCLEDSOLID	180     // need to check this

#define INVERTERON	120     // if current to inverter is more than this AMPS it's ON and loaded
#define	GASSING		250		// possible h2 gas above this charging current
#define	LPCHANC		12      // digital filter channels
#define	LP_PWM		0		// PWM period filter channel
#define LP_CCEFF	1		// channel for CCEFF
#define	LP_CCVOLTAGE	2	// ccvoltage
#define LP_CURRENT	3		// current channel
#define LP_CURRENTIN	4	// currentin channel
#define LP_CURRENTCHARGER   5	// charger
#define LP_PEUKERT	6		// peukert channels [6..8]
#define LP_PVVOLTAGE    9	// PV inputvoltage

#define PWM_LIMIT	24		// max level from CCEFF
#define	PWM_FACTOR	4		// PWM CCEFF gain factor
#define PWM_POWER	6		// Min Power from PV to allow PWM diversion
#define PWM_SLOPE	4		// When to start using gain factor

/* battery runtime charge factors	*/
#define	SMALLCOMP	1200.0  // normalize factor for small gell cells in weight cals mV
#define MIDCOMP		10.0	// normalize factor for small AGM cells
#define	DSOC_L		75      // divert power SOC setpoint for BOI
#define	DSOC_H		85      // divert power SOC setpoint for BOI
#define WFLOAT_LOW      24000.0 // divert power lowest weight for any battery
#define MAXWEIGHT		50000.0	// highest weight value possible
#define	MINWEIGHT		10000.0	// lowest weight value possible
#define PLUSWEIGHT      1000.0		// must be at least this much diff to cause a alert
#define ALERT_TIME      120			// delay between alerts
#define W_BASE_F        100.0
#define W_DOD_F         20.0
#define W_IR_F          0.2
#define W_AH_F          2.0
#define W_CYC_F         10.0
#define	PRIPOINTS	0.0			// weight points for primary battery
#define	INVPOINTS	2000.0		// weight points for battery on inverter
#define	LOWPOINTS       12000.0	// weight points for a very low battery
#define INV_VOLT_LOW    11400L  // Low voltage alarm point for inverter

/* Battery charge/discharge adjustment factors */
#define Perk_ADJ_FL	1.00	// If the peukert_adj is below this, adjust the Ah out by this Ah adjustment factor
#define Perk_ADJ_FH	5.00	// If the peukert_adj is above this, adjust the Ah out by this Ah adjustment factor
#define Temp_ADJ_FL	1.20	// Adjust the battery cap up or down 1C by this percentage from Temp_ZERO
#define Temp_ZERO	267l	// Temperature for base battery rate capacity in tenths of C
#define	CEF_HSOC	0.45    // Charge Efficiency Factor, high SOC
#define CEF_MSOC	0.70    // middle
#define	CEF_LSOC	0.90    // Charge Efficiency Factor, low SOC
#define CEF_OVER	0.99    // CEF overflow in calc
#define CEF_MAX		0.95 	// Invalid charge factor above this, should be about the same as CEF_LOSC
#define CEF_MIN		0.40	// Invalid charge factor below this
#define CEF_RESET	0.80    // reset AH values below this point.
#define CEF_DERATE	1.20	// Ahi derate factor to start dynamic CEF corrections
#define	SOC_DERATE	70      // derate CEF above this
#define SOC_CEF		100	// Max state of charge to update dynamic charge efficiency factors
#define RFACTOR		15l	// default for battery Ah cap recovery factor [0..100]
#define RFACTOR_MAX	100l	// 100 max factor * 100 to scale to .1A units
#define RFACTOR_BANK    9       // above this current start to bank the rest_rate instead of just making it vanish on every update
#define RFACTOR_RATE    2u      // rate in mA to restore batery Ah capacity every 10 seconds from Rest Reserve Bank
#define RFACTOR_BSOC    50u     // don't collect rest reserve Ah below this SOC
#define BFACTOR			15l			// default for battery Ah cap recovery factor [0..100]
#define BFACTOR_MAX		100l		// 100 max factor * 100 to scale to .1A units
#define BFACTOR_BANK    9       // above this current start to bank the bound_rate instead of just making it vanish on every update
#define BFACTOR_RATE    1       // rate in mA to restore batery Ah capacity every 10 seconds from Bound Reserve Bank
#define BFACTOR_BSOC    60u     // don't collect Bound reserve Ah below this SOC
#define BFACTOR_TEMP    2l      // SOC voltage correction factor for C.temp_drate
#define BFACTOR_DIODE   300l    // Isolation diode voltage drop
#define BVSOC_SLOTS     26      // Battery to SOC data table slots
#define BVSOC_FRESH     85      // SOC for FRESH flag
#define BVSOC_HIGH      12900L  // Battery voltage above this is usually from an aborted charge cycle so it might not be fully charged
#define BVSOC_RATIO_C   0.30    // SOC split from current or voltage
#define BVSOC_RATIO_V   0.70
#define BVSOC_SKEW      15.0    // Max skew between counting and voltage SOC measurements before defaulting to voltage
#define BVSOC_MINC      75      // Use method C only if SOC is already high
#define BVSOC_C_OFF     2L      // correction of vots to SOC for high current
#define BVSOC_SV_OFF    25L     // correction of vots to SOC for system controller during GANGED
#define BVSOC_CURRENT   50L     // switching point for R and L SoC methods
#define END_RATIO       0.12     // End amps from battery capacity, value scaled to result in mA for end-amps
#define END_RATIO_MED	0.30     // End amps from battery capacity, value scaled to result in mA for end-amps for M batteries

#define	DCURRENT	0.0     	// default discharge current 0.1A units "3.6 is the lowest possible value = .36A", use AH_DAY_OFF
#define	AH_DAY_LOSS1	2000l      	// Ah lost in 24 hours from natural discharge or controller usage BATT1.
#define	AH_DAY_LOSS2	2000l      	// Ah lost in 24 hours from natural discharge or controller usage BATT2.
#define	SS_RATE		9.00     	// STATIC SOC RATE Ah factor for static voltage cal to SOC and Aho
#define SOCFULL		85u      	// this is as good a full charge after a full C40 cycle timeout or float

#define MAXALM		7			// alarm message buffer size
#define	MAX_TWEAK_CMD	4      		// number of T tweak command choices

//	program constants
#define	HISTBATTNUM	2       	// we only really track the first two batteries
#define	ESRHIGH		1024		// starting ESR init value
#define	SOC_100	0
#define	SOC_85	1
#define	SOC_70	2
#define	SOC_50	3
#define MODEL_SLOTS	4		// array sixe for model data
#define DATA_SLOTS	5		// array size for battery data
#define BUTH_SLOTS      1               // array size of update data
#define	SDBUFFERSIZE	512l
#define SDBUFFER_EXTRA  8l
#define SDNAME_SIZE     6
#define HPARAM_SIZE     13              // 13 works, any more increases the SD boot data block past 512 bytes
#define LCDW_SIZE       21              // add term char
#define	NTP_SIZE	4               // length in bytes of ntp date var
#define FT20		20              // default value for fast ticks
#define SD_18		18
#define C_TEMP16	16			// temp string buffer size
#define C_TEMP7		7			// float string buffer size
#define HOST_TIMEOUT	256		// network timeout MBMC
#define SDT1            1
#define SDT2            2               // SD card types
#define SDT6            6
#define MAX_Q           175             // Top Power Quality for one day
#define TODAY_Q         30
#define YESTER_Q        35
#define CRIT_8          8               // 8 levels
#define CRITC1          1               // The first CRITC level
#define MASK9BIT	0x0100
#define	MBMC_CHART_POINTS	24
#define	LPCHAN	16

//      TEK410x defines
#define	ESC	0x1b
#define	FF	0x0c
#define	CAN	0x18
#define	FS	0x1c
#define	GS	0x1d
#define	US	0x1f
#define	ESCZ	0x1a

// SDHC defines
/* MMC/SD command (in SPI) */
#define CMD0	(0x40+0)        /* GO_IDLE_STATE */
#define CMD1	(0x40+1)        /* SEND_OP_COND (MMC) */
#define	ACMD41	(0xC0+41)       /* SEND_OP_COND (SDC) */
#define CMD8	(0x40+8)        /* SEND_IF_COND */
#define CMD9	(0x40+9)        /* SEND_CSD */
#define CMD10	(0x40+10)       /* SEND_CID */
#define CMD12	(0x40+12)       /* STOP_TRANSMISSION */
#define ACMD13	(0xC0+13)       /* SD_STATUS (SDC) */
#define CMD16	(0x40+16)       /* SET_BLOCKLEN */
#define CMD17	(0x40+17)       /* READ_SINGLE_BLOCK */
#define CMD18	(0x40+18)       /* READ_MULTIPLE_BLOCK */
#define CMD23	(0x40+23)       /* SET_BLOCK_COUNT (MMC) */
#define	ACMD23	(0xC0+23)       /* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24	(0x40+24)       /* WRITE_BLOCK */
#define CMD25	(0x40+25)       /* WRITE_MULTIPLE_BLOCK */
#define CMD55	(0x40+55)       /* APP_CMD */
#define CMD58	(0x40+58)       /* READ_OCR */
#define CRC_ON_OFF	(0x40+59)       // turn off CRC , it's default to off anyway

/* Control signals (Platform dependent) */
#define SELECT()	SPI_CS = LOW      	/* MMC CS = L */
#define	DESELECT()	SPI_CS = HIGH      	/* MMC CS = H */
//	RC3,RC4,RC5     SPI port1 lines
#define SDINFO		0		// SD card data info block
#define SDSTART		1		// SD card first data block
#define	SDC0EEP		510             // start address of SD mirror block data in EEPROM

#endif /* MBMC_DEFS_H_INCLUDED */
