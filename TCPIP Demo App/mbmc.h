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

typedef struct remote_daq_data { // set only in adc_read
    long inputcurrent, remotecurrent;
    unsigned long systemvoltage, voltagedrop, inputvoltage, rawtime;
    int sequence, new, read, station, timeout, offline;
} volatile remote_daq_data;

typedef struct hoststattype {
    LONG usart1_rxint, usart1_txint, usart2_rxint, usart2_txint;
    LONG telnet_connects, telnet_rxbytes, telnet_txbytes;
} volatile hoststattype;

typedef struct harvesttype {
    LONG energy, usage, prev_energy, prev_usage, e_total, u_total;
    LONG count, charger, c_total, prev_charger, diversion;
} volatile harvesttype;

typedef struct battparmtype {
    WORD esr, current, voltage, ah, temp;
    BYTE soc, cef, flags;
} volatile battparmtype;

struct battmodeltype {
    struct battparmtype soc[MODEL_SLOTS];
};

typedef struct SDCARD {
    WORD magic;
    BYTE sdtype, sdinit, sddetect, DAYCLOCK;
    DWORD sdpos, sdnext, timekeep, time;
    struct harvesttype harvest;
    SHORT h[HISTBATTNUM][HPARAM_SIZE]; // battery history data
} SDCARD_TYPE;

typedef struct SD_VOLUME_INFO {
    DWORD size_MB;
    DWORD sector_multiply, read_block_len;
    DWORD sector_count, serial;
    BYTE name[SDNAME_SIZE];
} VOLUME_INFO_TYPE;

typedef struct SDDUMP {
    BYTE dumping, type;
    DWORD sdpos;
} SDDUMP_TYPE;

typedef struct ccstype {
    BYTE pick, boi, boc, alert, bn;
} volatile ccstype;

struct portstype {
    BYTE NEWDATA, ALARM, RUNTIME, CCMODE;
};

typedef struct diversiontype {
    BYTE flag, power, control, alarm;
} volatile diversiontype;

#if defined(__18CXX)

typedef struct celltype { // C18 uses byte alignment
#else

typedef struct __attribute__((aligned(1))) celltype { // force C32 to byte alignment, 32bit alignment is still critical
#endif
    WORD id, model; //      battery cell type S,M,L
    LONG voltage, current, charge, cycles, noload, date;
    BYTE cconline, online, discharged, dead, critical, valid, fresh, misc;
    float weight;
}
volatile celltype;

/*		hist[x].h[x]
 *		h0  Peukert Factor adjusted Ah usage this cycle, MUST BE INTERGER variable type!
 *		h1	Lowest discharge ever,
 *		h2  current lowest discharge,
 *		h3  avg discharge
 *		h4	Number of full charge cycles, h5  Number of full discharge cycles
 *		h6	Real Ah usage this cycle, 	MUST BE INTERGER variable type!
 *		h7	Min Batt Voltage
 *		h8	Max Batt Voltage
 *		h9	Lowest ESR Pre
 *		h10	Lowest ESR Post
 */

#if defined(__18CXX)

typedef struct histtype { // C18 uses byte alignment
#else

typedef struct __attribute__((aligned(1))) histtype { // force C32 to byte alignment, 32bit alignment is still critical
#endif
    WORD rate, usoc, bsoc, bound_rate, bound_factor, samplei, sampleo, ah, drate, esr, rest_rate, rest_factor, esrp;
    SHORT h[HPARAM_SIZE]; // h[6]=cumulative battery Ah cc and inv (real),h[0]=cumulative battery Ah cc and inv (p_adj)
    LONG kwi, kwo, ttg, btest;
    LONG ahi, aho, ahir, ahop, thermo; // A stored in battery, A taken from battery, A from raw pv, peukert adjusted A
    LONG pv_eff, tot_eff; // pv generation eff factor, total system eff factor
    float peukert, cef, peukert_adj, cef_calc, cef_save;
}
volatile histtype;

typedef struct buttype {
    DWORD bvi, bvo;
    BYTE boc, boi;
    LONG bii, bio, bil;
} volatile buttype; // battery voltage in/out, battery  current in/out/load ,battery on charge, battery on inverter, battery inverter load

struct almtype {
    BYTE alm_flag, alm_count;
};

struct almbuffertype {
    BYTE alm_num, bn;
};

struct mbmccmdtype {
    WORD ready, cmd;
};

struct datadefaulttype {
    DWORD data_default;
};

struct lcdb {
    CHAR b[LCDW_SIZE];
};

struct timeruntype {
    DWORD hour, day, weeks;
};

struct mbmcnettype {
    BYTE *mbmc_byte;
    WORD mbmc_index, mbmc_len;
};

#define	HOST_REQ	'0'		// request mbmc ID
#define	HOST_ACK	'1'		// data ack code, returned when finished
#define	HOST_REAL	'2'		// send mbmc realtime data
#define	HOST_CELL	'3'		// send cell data stucture
#define	HOST_HIST	'4'		// send history data structure
#define HOST_SDC0	'5'		// send a SDCARD sector
#define	HOST_CMD_F	'F'		// send FORCEOUT command to ccvoltage controller
#define	HOST_CMD_V	'V'		// send charger toggle command to ccvoltage controller
#define	HOST_CMD_v	'v'		// send charger off command to ccvoltage controller
#define	HOST_CMD_SOC	'*'		// send set SOC command to ccvoltage controller
#define	HOST_CMD_UTC_S	'6'		// start xmit of UTC time to controller
#define	HOST_CMD_UTC_E	'7'		// end xmit of UTC time to controller

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

typedef struct __attribute__((aligned(1))) mbmcdata { // force C32 to byte alignment, 32bit alignment is still critical
#endif
    LONG ccvoltage, inputvoltage, primarypower_B1, primarypower_B2, systemvoltage;
    LONG currentin, current, currentload;
    LONG current_B1, current_B2;
    LONG thermo_batt, cef_boc; // cef*100
    LONG PRIPOWEROK, DIPSW;
    LONG pick, boi, boc, alert, bn;
    LONG misc1, misc2;
    LONG MBMCID, UTC;
    struct harvesttype harvest;
    struct portstype ports;
    struct diversiontype diversion;
    LONG crc;
}
volatile mbmctype;

typedef struct mbmcchart {
    struct mbmcdata data[MBMC_CHART_POINTS];
    DWORD sdate, edate, start;
    WORD pos, gap;
    float avg;
} mbmccharttype;

#if defined(__18CXX)
#else
#endif

typedef struct mbmcflagtype {
    WORD mbmc_cmd, mbmc_data, mbmc_ack;
    WORD host_cmd, host_data, host_ack;
    DWORD cmd_timeout, host_timeout, data_timeout, data_len, data_pos;
    BYTE rx_9bit, tx_9bit, mbmc_done, host_done, *data_ptr;
} volatile mbmcflagtype;

typedef struct mbmcstatustype {
    BYTE seq;
    BYTE real_valid;
    BYTE cell_valid;
    BYTE hist_valid;
    BYTE sdco_valid;
    BYTE cmd_valid;
    DWORD sent;
    DWORD received;
    DWORD cmdsent;
    DWORD cmdreceived;
    DWORD acksent;
    DWORD ackreceived;
} volatile mbmcstatustype;

typedef struct mbmclinktype {
    DWORD tx_cps, rx_cps;
} volatile mbmclinktype;

typedef struct R_data { // set only in adc_read
    long current, currentin, currentcharger, thermo_batt;
    unsigned long systemvoltage, ccvoltage, inputvoltage, primarypower[POWER_SLOTS];
} R_data;

typedef struct C_data { // set only in adc_read
    long currentload;
    int temp_drate;
    float t_comp;
} C_data;

typedef struct B_data {
    SHORT start_ahu, cef_raw; // must be int TYPE
    DWORD start_ahi, start_aho, absorp_ahi, absorp_time, charge_time_left; // unsigned long TYPE
    BYTE yesterday, today; // Harvest quality for the whole day, 0..100, uses time of harvest (seconds) -> input power (watts) -> max power (watts).
} volatile B_data; // of each measurement during that period.

struct battbufftype {
    unsigned long length, position;
    unsigned char busy, flag, good, copy;
};

typedef struct ccledtype {
    unsigned char flag, seconds, online;
    unsigned int count, ticks;
} volatile ccledtype;

struct alarmtype {
    BYTE absorp : 1;
    BYTE utility : 1;
    BYTE inverter : 1;
    BYTE cpu : 1;
    BYTE sdcard : 1;
    BYTE misc1 : 1;
    BYTE misc2 : 1;
    BYTE misc3 : 1;
};

union Alarm {
    struct alarmtype mbmc_alarm;
    BYTE alarm_byte;
};

#endif /* MBMC_H_INCLUDED */