/****************************** crc8.c **************************************\

Functions to calculate 8 bit checksums.

This code was created by Henrik Bj�rkman using examples
from crc_v3.txt written by Ross N. Williams
You are free to use the code as long as you keep a
comment about where you got it.

History:

1.0 Created by Henrik Bjorkman 1996-05-02
1.1 Mod for pic18 fgb

\*****************************************************************************/

/***************************** includes **************************************/

#include <stdlib.h>
#include <stdio.h>
#include "crc8.h"


/********************* Macros for 8 bit CRC functions ************************/



/* CRC algorithm */
#define CRC8_COMPUTE(crc,ch) (crc8_table[crc ^ ch])


/**************** static variables for 8  bit CRC functions  *****************/

/* Table used to compute CRC-8  with */
#if defined(__18CXX)
const rom unsigned char crc8_table[256] =
#else
const unsigned char crc8_table[256] =
#endif
{
    0x00, 0x85, 0x8F, 0x0A, 0x9B, 0x1E, 0x14, 0x91, 0xB3, 0x36,
    0x3C, 0xB9, 0x28, 0xAD, 0xA7, 0x22, 0xE3, 0x66, 0x6C, 0xE9,
    0x78, 0xFD, 0xF7, 0x72, 0x50, 0xD5, 0xDF, 0x5A, 0xCB, 0x4E,
    0x44, 0xC1, 0x43, 0xC6, 0xCC, 0x49, 0xD8, 0x5D, 0x57, 0xD2,
    0xF0, 0x75, 0x7F, 0xFA, 0x6B, 0xEE, 0xE4, 0x61, 0xA0, 0x25,
    0x2F, 0xAA, 0x3B, 0xBE, 0xB4, 0x31, 0x13, 0x96, 0x9C, 0x19,
    0x88, 0x0D, 0x07, 0x82, 0x86, 0x03, 0x09, 0x8C, 0x1D, 0x98,
    0x92, 0x17, 0x35, 0xB0, 0xBA, 0x3F, 0xAE, 0x2B, 0x21, 0xA4,
    0x65, 0xE0, 0xEA, 0x6F, 0xFE, 0x7B, 0x71, 0xF4, 0xD6, 0x53,
    0x59, 0xDC, 0x4D, 0xC8, 0xC2, 0x47, 0xC5, 0x40, 0x4A, 0xCF,
    0x5E, 0xDB, 0xD1, 0x54, 0x76, 0xF3, 0xF9, 0x7C, 0xED, 0x68,
    0x62, 0xE7, 0x26, 0xA3, 0xA9, 0x2C, 0xBD, 0x38, 0x32, 0xB7,
    0x95, 0x10, 0x1A, 0x9F, 0x0E, 0x8B, 0x81, 0x04, 0x89, 0x0C,
    0x06, 0x83, 0x12, 0x97, 0x9D, 0x18, 0x3A, 0xBF, 0xB5, 0x30,
    0xA1, 0x24, 0x2E, 0xAB, 0x6A, 0xEF, 0xE5, 0x60, 0xF1, 0x74,
    0x7E, 0xFB, 0xD9, 0x5C, 0x56, 0xD3, 0x42, 0xC7, 0xCD, 0x48,
    0xCA, 0x4F, 0x45, 0xC0, 0x51, 0xD4, 0xDE, 0x5B, 0x79, 0xFC,
    0xF6, 0x73, 0xE2, 0x67, 0x6D, 0xE8, 0x29, 0xAC, 0xA6, 0x23,
    0xB2, 0x37, 0x3D, 0xB8, 0x9A, 0x1F, 0x15, 0x90, 0x01, 0x84,
    0x8E, 0x0B, 0x0F, 0x8A, 0x80, 0x05, 0x94, 0x11, 0x1B, 0x9E,
    0xBC, 0x39, 0x33, 0xB6, 0x27, 0xA2, 0xA8, 0x2D, 0xEC, 0x69,
    0x63, 0xE6, 0x77, 0xF2, 0xF8, 0x7D, 0x5F, 0xDA, 0xD0, 0x55,
    0xC4, 0x41, 0x4B, 0xCE, 0x4C, 0xC9, 0xC3, 0x46, 0xD7, 0x52,
    0x58, 0xDD, 0xFF, 0x7A, 0x70, 0xF5, 0x64, 0xE1, 0xEB, 0x6E,
    0xAF, 0x2A, 0x20, 0xA5, 0x34, 0xB1, 0xBB, 0x3E, 0x1C, 0x99,
    0x93, 0x16, 0x87, 0x02, 0x08, 0x8D
};

#if defined(__18CXX)
const rom unsigned short crc16tab[256] =
#else
const unsigned short crc16tab[256] =
#endif
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
    0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

/* returns a 8  bit checksum for the buffer. */
unsigned char crc8_calculate(unsigned char* buf, unsigned int size)
{
    unsigned int i = 0;
    unsigned char crc = 0;

    for (i = 0; i < size; i++) {
	crc = CRC8_COMPUTE(crc, buf[i]);
    }
    return (crc);
}

/* On entry, addr=>start of data
	     num = length of data
	     crc = incoming CRC     */
unsigned short crc16(unsigned char* addr, unsigned int num, unsigned short crc) // XMODEM crc-16
{
    int i;

    for (; num > 0; num--) /* Step through bytes in memory */ {
	crc = crc ^ (*addr++ << 8); /* Fetch byte from memory, XOR into CRC top byte*/
	for (i = 0; i < 8; i++) /* Prepare to rotate 8 bits */ {
	    if (crc & 0x10000) /* b15 is set... */
		crc = (crc << 1) ^ poly; /* rotate and XOR with XMODEM polynomic */
	    else /* b15 is clear... */
		crc <<= 1; /* just rotate */
	} /* Loop for 8 bits */
	crc &= 0xFFFF; /* Ensure CRC remains 16-bit value */
    } /* Loop until num=0 */
    return (crc); /* Return updated CRC */
}

/* CRC16 implementation acording to CCITT standards */
unsigned short crc16_ccitt(unsigned char* buf, unsigned int len)
{
    int counter;
    unsigned short crc = 0;
    for (counter = 0; counter < len; counter++)
	crc = (crc << 8) ^ crc16tab[((crc >> 8) ^ *(char *) buf++)&0x00FF];
    return crc;
}