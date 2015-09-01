/* 
 * File:   timelib.h
 * Author: root
 *
 * Created on September 13, 2012, 8:51 AM
 */

#ifndef TIMELIB_H_INCLUDED
#define	TIMELIB_H_INCLUDED

#include "mbmc.h"
#include <stdlib.h>
#include <string.h>

typedef struct tm {
    int16_t tm_sec; // 0 to 59 (or 60 for occasional rare leap-seconds)
    int16_t tm_min; // 0 to 59
    int16_t tm_hour; // 0 to 23
    int16_t tm_mday; // 1 to 31
    int16_t tm_mon; // 0 to 11, stupidly 0=January, 11=December
    int16_t tm_year; // year-1900, so 79 means 1979, 103 means 2003
    int16_t tm_wday; // 0 to 6, 0=Sunday, 1=Monday, ..., 6=Saturday
    int16_t tm_yday; // 0 to 365, 0=1st January
    int16_t tm_isdst; // 0 to 1, 1=DST is in effect, 0=it isn't
    int8_t *tm_zone; // time zone, e.g. "PDT", "EST".
    int16_t tm_gmtoff; // time zone in seconds from GMT; EST=-18000, WET=3600
} tm;

typedef uint32_t time_t;

int16_t isleap(int16_t);
time_t mktime(tm*);
void offtime(tm*, time_t, int32_t);
void asctime(tm*, int8_t*, uint8_t);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* TIMELIB_H_INCLUDED */

