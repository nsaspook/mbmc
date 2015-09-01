#ifndef POWER_H_INCLUDED
#define POWER_H_INCLUDED
#include <p18cxxx.h>
#include "mbmc.h"
#include "mbmc_shared.h"
#include "crit.h"
#include "config.h"
#include "daq.h"
//#include "mbmc_msg.h"
#include "mbmc_vector.h"
#include <pwm.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

extern volatile uint32_t c_on, c_off, d_on, d_off;
extern uint32_t chrg_v;
extern volatile int32_t end_amps;
extern volatile uint8_t almctr, SIM_MODE, DIVERSION_set;
extern volatile int16_t CCEFF, CCEFF_DIFF;
extern volatile struct V_data V;
extern volatile struct B_data B;
extern volatile struct P_data P;
extern struct lcdb ds[VS_SLOTS];
extern far int8_t f1[C_TEMP7], f2[C_TEMP7], f3[C_TEMP7], f4[C_TEMP7];
extern int8_t soc_method[DATA_SLOTS], CCM;
extern float smooth[LPCHANC], esr_delta;
extern uint8_t model_update;
extern struct battmodeltype bmt[HISTBATTNUM];
extern const rom int8_t charger1[],
	chrgcode0[], chrgcode1[], chrgcode2[], chrgcode3[], chrgcode4[],
	chrgcode5[], chrgcode6[], chrgcode7[], chrgcode8[], chrgcode9[],
	chrgcode10[], chrgcode11[], chrgcode12[], chrgcode13[], chrgcode14[],
	chrgcode15[], chrgcode16[],
	runcode0[], runcode1[], runcode2[], runcode3[], runcode4[],
	runcode5[], runcode6[], runcode7[], runcode8[], runcode9[];

extern uint8_t check_alarm(uint8_t, const rom int8_t*);
extern float lp_filter(float, int16_t, int16_t);
extern void LCD_VC_puts(uint8_t, uint8_t, uint8_t);
extern int8_t *voltfpi(int32_t, int8_t *);
extern int8_t *voltfp(uint32_t, int8_t *);
extern int8_t *ahfp(int32_t, int8_t *);
extern uint16_t Volts_to_SOC(uint32_t, uint8_t);
extern uint16_t Get_RestSOC(uint8_t, uint8_t, blendmode_t);
extern void ChargeRelayOn(uint8_t, uint8_t);
extern void ChargeRelayOff(uint8_t, uint8_t);
extern void update_hist(void);
extern void mkbsstring(void);
extern float update_cef(uint8_t, uint8_t);
extern int8_t *hms(uint32_t);
extern void battalarm(int16_t, int16_t, int16_t);

void ResetC40(uint8_t, uint8_t, uint8_t);
uint8_t divert_power(uint8_t, uint8_t, uint8_t);
uint8_t charger_power(uint8_t, uint8_t);
void pv_pwm_set(int16_t);
void pv_pwm_calc(float);
void pv_pwm_shutdown(void);
int16_t predict_energy(uint8_t);

uint8_t ChargeBatt(uint8_t, uint8_t, uint8_t);
void noload_soc(void);
uint8_t pick_batt(uint8_t, uint8_t);

#endif /* POWER_H_INCLUDED */