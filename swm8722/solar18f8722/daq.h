#ifndef DAQ_H_INCLUDED
#define DAQ_H_INCLUDED
#include <adc.h>
#include <delays.h>
#include <usart.h>
#include <stdio.h>
#include "mbmc.h"
#include "mbmc_shared.h"
#include "crit.h"

uint32_t ADC_get(uint8_t, uint16_t, uint16_t, uint8_t, int16_t, uint8_t);
void ADC_zero(void);
void ADC_read(void);
void set_adc_gain(void); // get adc channel gains
void zero_amploc(void); // set sensor ADC zero value
void zero_amploc_PV(void); // set PV sensor ADC zero value, non-interactive
void do_sim(void);

extern const rom int8_t adcg0[], adcg1[], adcg2[], adcg3[], adcg4[], zero0[], zero1[], zero2[], zero3[], zero4[];
extern int32_t current_t, currentin_t, currentcharger_t;
extern uint32_t Vin, rawp1, rawp2, rawp3, vbatol_t, solar_t;
extern uint8_t adc_cal[];
extern volatile uint8_t battnum, c2raw, SIM_MODE, SIM_FLAG, keynum, B_GANGED;
extern int16_t a50, a300, a50c, therm;
extern uint16_t zero_ref;
extern struct R_data R;
extern struct C_data C;
extern volatile struct P_data P;

extern volatile enum answer_t {
	WAIT_M, YES_M, NO_M
} YNKEY;
extern far int8_t bootstr2[MESG_W + 1];

extern int32_t ABSL(int32_t);
extern float lp_filter(float, int16_t, int16_t);
extern void do_sim(void);
extern void display_system(void);
extern void wdtdelay(uint32_t);
extern void wdttime(uint32_t);
extern void term_time(void);


#endif /* DAQ_H_INCLUDED */