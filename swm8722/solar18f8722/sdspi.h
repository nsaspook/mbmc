#ifndef SDSPI_H_INCLUDED
#define SDSPI_H_INCLUDED

#include <p18cxxx.h>
#include <spi.h>
#include "mbmc.h"
#include "mbmc_shared.h"

void send_dummys(void); // Send 80 clocks to SD card
int16_t initsd(void);
int16_t disk_initialize(void); // Check for card and init via SPI
int16_t MMC_get_volume_info(void); // Read card info
void init_sdspi(void); // open spi port and config
uint8_t xmit_spi(uint8_t); // Send 1 byte to card
uint8_t rcvr_spi(void); // Receive 1 byte from card
int16_t mmc_write_block(uint32_t); // Write SDBUFFERSIZE bytes to card at block address (SDHC style)
int16_t mmc_read_block(uint32_t); // Read SDBUFFERSIZE bytes from card at block address (SHDC style)
void wipe_sdbuffer(void); // write all zeros to sd card buffer

extern uint8_t csd[SD_18], cid[SD_18];
extern VOLUME_INFO_TYPE MMC_volume_Info, *vinf;
extern far int8_t block_buffer[SDBUFFERSIZE + SDBUFFER_EXTRA];
extern void wdttime(uint32_t);

#endif /* SDSPI_H_INCLUDED */

