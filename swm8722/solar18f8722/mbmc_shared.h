/* extern variables used in several modules */
#ifndef MBMC_SHARED_H_INCLUDED
#define MBMC_SHARED_H_INCLUDED

#include "mbmc.h"

extern volatile struct mbmcdata MBMC;
extern volatile struct celltype cell[DATA_SLOTS];
extern volatile struct histtype hist[DATA_SLOTS];
extern volatile SDCARD_TYPE SDC0;
extern volatile struct ccstype CCS;
extern struct R_data R;
extern volatile struct almbuffertype alarm_buffer[MAXALM];
extern volatile struct almtype alarm_codes;
extern volatile uint8_t B0, B1, B2, B3, B4;

#endif /* MBMC_SHARED_H_INCLUDED */
