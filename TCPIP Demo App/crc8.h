#ifndef CRC_H_INCLUDED
#define CRC_H_INCLUDED
#define poly 0x1021

unsigned char crc8_calculate(unsigned char*, unsigned int);
unsigned short crc16(unsigned char* , unsigned int , unsigned short );    // XMODEM crc-16
unsigned short crc16_ccitt(unsigned char*, unsigned int );    // CCITT

#endif /* CRC_H_INCLUDED */