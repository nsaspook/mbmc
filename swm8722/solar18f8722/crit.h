#ifndef CRIT_H_INCLUDED
#define CRIT_H_INCLUDED
#include <p18cxxx.h>
#include "mbmc.h"
#include <timers.h>
#include <EEP.h>

volatile void s_crit(uint8_t);
volatile void e_crit(void);
volatile void clear_crit(void);
void write_data_eeprom(uint8_t, uint8_t, uint16_t, uint16_t);
uint8_t read_data_eeprom(uint16_t, uint16_t);
void wipe_data_eeprom(uint16_t);
uint8_t save_daily(void);

extern uint8_t CRITC, HCRIT[CRIT_8], LCRIT[CRIT_8];
extern volatile uint32_t critc_count;
extern volatile uint8_t critc_level, battnum;
extern union Timers hirez_0, hirez_1;
extern volatile uint16_t hirez_count[7];
extern volatile uint8_t idleflag;
extern volatile struct P_data P;
extern volatile struct histtype hist[DATA_SLOTS];

extern void idle_loop(void);

#endif /* CRIT_H_INCLUDED */

