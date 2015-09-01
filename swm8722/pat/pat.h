#ifndef PAT_H_INCLUDED
#define PAT_H_INCLUDED
//	hardware defines

#ifdef INTTYPES
#include <stdint.h>
#else
#define INTTYPES
/*unsigned types*/
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
/*signed types*/
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long int32_t;
typedef signed long long int64_t;
#endif

typedef struct V_data { // ISR used, mainly for non-atomic mod problems
    uint16_t blink, blink_out, blink_alt, fine;
    int16_t ihc_d_abs;
    uint8_t inreg : 1;
    uint8_t ibs_block_done : 1;
    uint8_t ihc_data0 : 1;
    uint8_t ihc_data1 : 1;
    uint8_t ihc_data2 : 1;
    uint8_t ihc_data3 : 1;
    uint8_t ihc_data4 : 1;
    uint8_t config : 1;
} V_data;

typedef struct OUTBITS2 {
    uint8_t b0 : 1;
    uint8_t b1 : 1;
    uint8_t b2 : 1;
    uint8_t b3 : 1;
    uint8_t b4 : 1;
    uint8_t b5 : 1;
    uint8_t b6 : 1;
    uint8_t b7 : 1;
} OUTBITS_TYPE2;

union Obits2 {
    uint8_t out_byte;
    OUTBITS_TYPE2 out_bits;
};

#define TRUE	1
#define FALSE	0
#define	ON	1
#define	OFF	0
#define	LEDON	0   // logic low lights led
#define	LEDOFF	1

#define	TIMEROFFSET	34268			// timer0 16bit counter value for 1 second to overflow
#define	TIMERFAST	61000			// fast flash 2hz
#define	SAMPLEFREQ	0xe7b2			// timer1 100hz

#define MAX_DATA        6

#define IBSPORTA	TRISA
#define IBSPORTB	TRISB
#define IBSPORT_IOA	0b00000000		//
#define IBSPORT_IOB	0b00010010		// Rs-232 receive on B4

#define LED0		LATAbits.LATA0
#define LED1		LATAbits.LATA1
#define LED2		LATAbits.LATA2
#define LED3		LATAbits.LATA3
#define LED4		LATBbits.LATB6
#define LED5		LATBbits.LATB7
#define LED6		LATAbits.LATA6
#define LED7		LATBbits.LATB5
#define TRACE_BIT	LATBbits.LATB0
#define FINE_REG  	LATBbits.LATB0
#define COMM_ENABLE	LATBbits.LATB3
#define COMM_ERROR	LATAbits.LATA4

// regulation feedback 0 center 600 = nom.
// filament voltage, 700 = nom.
// cathode current, 600 = nom.
// cathode voltage 600v = 1023
// filament current, 425 is nom.

// *** Have to 'mung' the codes to release this software ***

#define IHC_CODE0       '1'  // extraction current regulation
#define IHC_CODE0_TUNE  30
#define IHC_CODE0_FINE	5
#define IHC_CODE0_VFINE	1
#define IHC_CODE0H      800
#define IHC_CODE0L      400
#define IHC_CODE1       '2'  // filament voltage
#define IHC_CODE1H      900
#define IHC_CODE1L      200
#define IHC_CODE2       '3' // filament current
#define IHC_CODE2H      900
#define IHC_CODE2L      300
#define IHC_CODE3       '4' // cathode voltage,  is EU for voltage
#define IHC_CODE3H      1050
#define IHC_CODE3L      700
#define IHC_CODE4       '5' // cathode current
#define IHC_CODE4H      700
#define IHC_CODE4L      300

#define IHC_SAMPLES	2

#define CONFIG_CHAR     '?'
#define CONFIG_REPEATS  9

#define LINK_COUNT      10
#endif 