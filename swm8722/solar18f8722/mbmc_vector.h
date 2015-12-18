/*
 * This is the high and low ISR vector interface dependency header
 */
//FIXME there is way too much stuff in globals

#ifndef MBMC_VECTOR_H_INCLUDED
#define MBMC_VECTOR_H_INCLUDED
#include <p18cxxx.h>
#include "mbmc.h"
#include "mbmc_shared.h"
#include "config.h"
#include "power.h"
#include "crc8.h"
#include <usart.h>
#include <timers.h>

void tick_handler(void);
void work_handler(void);
void idle_loop(void);
void P1wait(void);
void P2wait(void);

/* BEGIN HIGH ISR */
extern volatile uint32_t display_count, dayclockup,
	dayclockdown, c_on, c_off, cctimer;

extern volatile uint16_t hirez_count[7], solarup_delay;
extern union Timers hirez_0, hirez_1;
extern volatile uint8_t fast_ticks, real_ticks, XON_XOFF, battnum,
	glitch_count, almctr, DISPLAY_MODE, dsi,
	c2raw, HOST_COMM, SETBATT_SOC, SYNCSOC, SYS_HELP, SYS_DATA, MOD_DATA,
	SET_ADC, TWEAK, keynum, SIM_FLAG, b_read,
	PERKOSW_R, GANGED_MODE, B_GANGED, GANG_OVERRIDE, DIVERSION_set;
extern volatile struct ccledtype ccled_flag;
extern volatile struct mbmclinktype LINK;
extern volatile int16_t tx_tmp, rx_tmp, venttimer, loggertime;
extern volatile SDDUMP_TYPE SDD0;
extern struct C_data C;
extern volatile struct B_data B;
extern volatile struct V_data V;
extern volatile struct P_data P;
extern volatile union Alarm alarms;

extern volatile enum ccmode_t {
    IDLE_M, BULK_M, FLOAT_M, TEST_M, ABSORP_M, FLOAT_W
} CCMODE;

extern volatile enum mbmode_t {
    IDLE_M, CHARGE_M, FLOAT_M, TEST_M
} BMMODE;
extern volatile struct battbufftype battbuffer, batttype;
extern volatile struct mbmcflagtype mbmcflag, mbmc_dumpflag;
extern volatile uint32_t utctime;

extern volatile union {
    uint32_t netdword;
    uint8_t netdbyte[4];
} netd;
extern volatile int32_t time_skew_base, time_skew, absorp_current;
extern volatile uint8_t netdword_pos;
extern volatile uint8_t UTC_flag, UTC_ok;
extern volatile uint8_t HOST_BUSY;

extern volatile enum answer_t {
    WAIT_M, YES_M, NO_M
} YNKEY;
/* END HIGH ISR */

/* BEGIN LOW ISR EXTRAS */
extern volatile uint32_t worker_count, status_count;
extern volatile uint8_t cdelay, SIM_MODE;
extern volatile struct buttype buth[BUTH_SLOTS];
extern volatile int16_t CCEFF_DIFF;
extern volatile int32_t ahi_tmp, aho_tmp, ahop_tmp;
/* END LOW ISR */

/* BEGIN IDLE_LOOP EXTRAS */
extern void mbmc_update(void);
extern volatile uint8_t idleflag;
extern volatile uint32_t mbmc_cmd_reply;
extern void pv_pwm_set(int16_t);
extern uint8_t crc8_calculate(uint8_t*, uint16_t);
/* END IDLE_LOOP EXTRAS */
#endif /* MBMC_VECTOR_H_INCLUDED */

