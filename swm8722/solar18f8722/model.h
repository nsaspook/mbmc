#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED
#include <p18cxxx.h>
#include "mbmc.h"
#include "mbmc_shared.h"
#include <usart.h>
#include <stdio.h>

void model_data(void);
uint8_t model_learn(uint8_t); // look for a remember model data during discharge cycles after full charge.

extern struct battmodeltype bmt[HISTBATTNUM];
extern far int8_t bootstr2[MESG_W + 1];
extern far int8_t block_buffer[SDBUFFERSIZE + SDBUFFER_EXTRA];
extern const rom int8_t modelheader0[], modelheader1[];
extern float esr_delta;

extern uint8_t ChargeBatt(uint8_t, uint8_t, uint8_t);
extern void noload_soc(void);
extern void update_hist(void);
extern void term_time(void);

#endif /* MODEL_H_INCLUDED */
