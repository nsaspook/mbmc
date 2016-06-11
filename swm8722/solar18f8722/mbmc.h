#ifndef MBMC_H_INCLUDED
#define MBMC_H_INCLUDED
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// defines and structures for MBMC networking
#define	__MBMCAPP_H

#include "mbmc_defs.h"
#include <GenericTypeDefs.h>

#ifdef INTTYPES
#include <stdint.h>
#else
#define INTTYPES
/*unsigned types*/
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
/*signed types*/
typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;
typedef signed long long int64_t;
#endif

typedef struct hoststattype {
	int32_t usart1_rxint, usart1_txint, usart2_rxint, usart2_txint;
	int32_t telnet_connects, telnet_rxbytes, telnet_txbytes;
} volatile hoststattype;

typedef struct harvesttype {
	int32_t energy, usage, prev_energy, prev_usage, e_total, u_total;
	int32_t count, charger, c_total, prev_charger, diversion;
} volatile harvesttype;

typedef struct battparmtype {
	uint16_t esr, current, voltage, ah, temp;
	uint8_t soc, cef, flags;
} volatile battparmtype;

struct battmodeltype {
	struct battparmtype soc[MODEL_SLOTS];
};

typedef struct SDCARD {
	uint16_t magic;
	uint8_t sdtype, sdinit, sddetect, DAYCLOCK;
	uint32_t sdpos, sdnext, timekeep, time;
	struct harvesttype harvest;
	int16_t h[HISTBATTNUM][HPARAM_SIZE]; // battery history data
} SDCARD_TYPE;

typedef struct SD_VOLUME_INFO {
	uint32_t size_MB;
	uint32_t sector_multiply, read_block_len;
	uint32_t sector_count, serial;
	uint8_t name[SDNAME_SIZE];
} VOLUME_INFO_TYPE;

typedef struct SDDUMP {
	uint8_t dumping, type;
	uint32_t sdpos;
} SDDUMP_TYPE;

typedef struct ccstype { // charger controller status
	uint8_t pick, boi, boc, alert, bn; // picked battery for pick_batt, battery on inverter, battery on charger, alert flag, battery number that need charging
} volatile ccstype;

struct portstype {
	uint8_t NEWDATA, ALARM, RUNTIME, CCMODE;
};

typedef struct diversiontype {
	uint8_t flag, power, power_control, alarm;
} volatile diversiontype;

#if defined(__18CXX)

typedef struct celltype { // C18 uses byte alignment
#else

typedef struct __attribute__((aligned(1))) celltype
{ // force C32 to byte alignment, 32bit alignment is still critical
#endif
	uint16_t id, model; //      battery cell type S,M,L
	int32_t voltage, current, charge, cycles, noload, date;
	uint8_t cconline, online, discharged, dead, critical, valid, fresh, misc;
	float weight;
}
volatile celltype;

/*		hist[x].h[x]
 *		h0	Peukert Factor adjusted Ah usage this cycle, MUST BE INTERGER variable type!
 *		h1	Lowest discharge ever,
 *		h2	current lowest discharge,
 *		h3	avg discharge
 *		h4	Number of full charge cycles, 
 *		h5	Number of full discharge cycles
 *		h6	Real Ah usage this cycle, 	MUST BE INTERGER variable type!
 *		h7	Min Batt Voltage
 *		h8	Max Batt Voltage
 *		h9	Lowest ESR Pre
 *		h10	Lowest ESR Post
 *		h11	Total charge cycles
 *		h12	Total kWH in
 */

#if defined(__18CXX)

typedef struct histtype { // C18 uses byte alignment
#else

typedef struct __attribute__((aligned(1))) histtype
{ // force C32 to byte alignment, 32bit alignment is still critical
#endif
	uint16_t rate, udod, bsoc, bound_rate, bound_factor, samplei, sampleo, ah, drate, esr, rest_rate, rest_factor, esrp;
	int16_t h[HPARAM_SIZE]; // h[6]=cumulative battery Ah cc and inv (real),h[0]=cumulative battery Ah cc and inv (p_adj)
	int32_t kwi, kwo, ttg, btest;
	int32_t ahi, aho, ahir, ahop, thermo; // A stored in battery, A taken from battery, A from raw pv, peukert adjusted A
	int32_t pv_eff, tot_eff; // pv generation eff factor, total system eff factor
	float peukert, cef, peukert_adj, cef_calc, cef_save;
}
volatile histtype;

typedef struct buttype {
	uint32_t bvi, bvo;
	uint8_t boc, boi;
	int32_t bii, bio, bil;
} volatile buttype; // battery voltage in/out, battery  current in/out/load ,battery on charge, battery on inverter, battery inverter load

struct almtype {
	uint8_t alm_flag, alm_count;
};

struct almbuffertype {
	uint8_t alm_num, bn;
};

struct mbmccmdtype {
	uint16_t ready, cmd;
};

struct datadefaulttype {
	uint32_t data_default;
};

struct lcdb {
	int8_t b[LCDW_SIZE];
};

struct timeruntype {
	uint32_t hour, day, weeks;
};

struct mbmcnettype {
	uint8_t *mbmc_byte;
	uint16_t mbmc_index, mbmc_len;
};

#define	HOST_REQ	'0'		// request mbmc ID
#define	HOST_ACK	'1'		// data ack code, returned when finished
#define	HOST_REAL	'2'		// send mbmc realtime data
#define	HOST_CELL	'3'		// send cell data stucture
#define	HOST_HIST	'4'		// send history data structure
#define HOST_SDC0	'5'		// send a SDCARD sector
#define	HOST_CMD_F	'F'		// send FORCEOUT command to ccvoltage controller
#define	HOST_CMD_V	'V'		// send charger on command to ccvoltage controller
#define	HOST_CMD_v	'v'		// send charger off command to ccvoltage controller
#define	HOST_CMD_SOC	'*'		// send set SOC command to ccvoltage controller
#define	HOST_CMD_UTC_S	'6'		// start xmit of UTC time to controller
#define	HOST_CMD_UTC_E	'7'		// end xmit of UTC time to controller
#define	HOST_CMD_D	'D'		// send Diversion on command to ccvoltage controller
#define	HOST_CMD_d	'd'		// send Diversion off command to ccvoltage controller

#if defined(__18CXX)
#define BCRELAYS	PORTE
#define IORELAYS	PORTJ
#define	DIPSW		PORTD
#define	EXTIO		PORTB
#endif

// SDCARD data format structure using TypeDefs for pic32 host
#if defined(__18CXX)

typedef struct mbmcdata { // C18 uses byte alignment
#else

typedef struct __attribute__((aligned(1))) mbmcdata
{ // force C32 to byte alignment, 32bit alignment is still critical
#endif
	int32_t ccvoltage, inputvoltage, primarypower_B1, primarypower_B2, systemvoltage;
	int32_t currentin, current, currentload;
	int32_t current_B1, current_B2;
	int32_t thermo_batt, cef_boc; // cef*100
	int32_t PRIPOWEROK, DIPSW;
	int32_t pick, boi, boc, alert, bn;
	int32_t misc1, misc2;
	int32_t MBMCID, UTC;
	struct harvesttype harvest;
	struct portstype ports;
	struct diversiontype diversion;
	int32_t crc;
}
volatile mbmctype;

typedef struct mbmcchart {
	struct mbmcdata data[MBMC_CHART_POINTS];
	uint32_t sdate, edate, start;
	uint16_t pos, gap;
	float avg;
} mbmccharttype;

#if defined(__18CXX)
#else
#endif

typedef struct mbmcflagtype {
	uint16_t mbmc_cmd, mbmc_data, mbmc_ack;
	uint16_t host_cmd, host_data, host_ack;
	uint32_t cmd_timeout, host_timeout, data_timeout, data_len, data_pos;
	uint8_t rx_9bit, tx_9bit, mbmc_done, host_done, *data_ptr;
} volatile mbmcflagtype;

typedef struct mbmcstatustype {
	uint8_t seq;
	uint8_t real_valid;
	uint8_t cell_valid;
	uint8_t hist_valid;
	uint8_t sdco_valid;
	uint8_t cmd_valid;
	uint32_t sent;
	uint32_t received;
	uint32_t cmdsent;
	uint32_t cmdreceived;
	uint32_t acksent;
	uint32_t ackreceived;
} volatile mbmcstatustype;

typedef struct mbmclinktype {
	uint32_t tx_cps, rx_cps;
} volatile mbmclinktype;

typedef struct R_data { // set only in adc_read
	int32_t current, currentin, currentcharger, thermo_batt, cin_fast;
	uint32_t systemvoltage, ccvoltage, inputvoltage, primarypower[POWER_SLOTS];
} R_data;

typedef struct V_data { // OS Counters
	uint32_t highint_count, lowint_count, eeprom_count, timerint_count, adc_count, mbmcdata_count, c1rx_int, c1tx_int, c2_int, buttonint_count,
	clock50, pwm4int_count;
} V_data;

typedef struct C_data { // set only in adc_read
	int32_t currentload;
	int16_t temp_drate;
	float t_comp;
} C_data;

typedef struct B_data {
	int16_t start_ahu, cef_raw; // must be int16_t TYPE
	uint32_t start_ahi, start_aho, absorp_ahi, absorp_time, charge_time_left; // uint32_t TYPE
	uint8_t yesterday, today, r_soc[DATA_SLOTS]; // Harvest quality for the whole day, 0..100, uses time of harvest (seconds) -> input power (watts) -> max power (watts).
	int32_t diversion;
	int32_t watercounter, watercounter_prev;
	uint8_t d_code, equal;
} volatile B_data; // of each measurement during that period.

struct battbufftype {
	uint32_t length, position;
	uint8_t busy, flag, good, copy;
};

typedef struct ccledtype {
	uint8_t flag, seconds, online;
	uint16_t count, ticks;
} volatile ccledtype;

typedef enum {
	NO_BLEND, DO_BLEND, CLEAR_BLEND, MILD_BLEND
} blendmode_t;

typedef struct P_data {
	uint8_t BCHECK : 1;
	uint8_t TIMERFLAG : 1;
	uint8_t PRIPOWEROK : 1;
	uint8_t FORCEOUT : 1;
	uint8_t WORKERFLAG : 1;
	uint8_t CHARGEROVERRIDE : 1;
	uint8_t FAILSAFE : 1;
	uint8_t MORNING_HELP : 1;
	uint8_t SYSTEM_STABLE : 1;
	uint8_t HOLD_PROC : 1;
	uint8_t POWER_UNSTABLE : 1;
	uint8_t B2 : 1;
	uint8_t B3 : 1;
	uint8_t B4 : 1;
	uint8_t SET_BATT : 1;
	uint8_t BLANK_LCD : 1;
	uint8_t STATIC_SOC : 1;
	uint8_t SET_CEF : 1;
	uint8_t D_UPDATE : 1;
	uint8_t GLITCH_CHECK : 1;
	uint8_t FORCEDAY : 1;
	uint8_t COOLING : 1;
	uint8_t UPDATE_EEP : 1;
	uint8_t RESET_ZEROS : 1;
	uint8_t SAVE_DAILY : 1;
	uint8_t SETBATT_SOC : 1;
	uint8_t SYNCSOC : 1;
} P_data_t;

struct alarmtype {
	uint8_t absorp : 1;
	uint8_t utility : 1;
	uint8_t inverter : 1;
	uint8_t cpu : 1;
	uint8_t sdcard : 1;
	uint8_t equal : 1;
	uint8_t misc2 : 1;
	uint8_t misc3 : 1;
};

union Alarm {
	struct alarmtype mbmc_alarm;
	uint8_t alarm_byte;
};

#endif /* MBMC_H_INCLUDED */