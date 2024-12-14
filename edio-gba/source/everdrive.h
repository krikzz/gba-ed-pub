/* 
 * File:   everdrive.h
 * Author: krik
 *
 * Created on December 15, 2015, 1:50 PM
 */

#ifndef EVERDRIVE_H
#define	EVERDRIVE_H

#include "sys.h"

#define ED_USB_BUFF 32767

#define SD_SPD_LO 0
#define SD_SPD_HI 1


#define SD_MODE1 0
#define SD_MODE2 2
#define SD_MODE4 4
#define SD_MODE8 6

#define ED_SAV_EEP     16
#define ED_SAV_SRM     32
#define ED_SAV_FLA64   64
#define ED_SAV_FLA128  80
#define ED_SAV_BITS (ED_SAV_EEP | ED_SAV_FLA128 | ED_SAV_FLA64 | ED_SAV_SRM)
#define ED_RAM_BNK_0 0
#define ED_RAM_BNK_1 128
#define ED_RAM_BNK_2 256
#define ED_RAM_BNK_3 384

#define ED_CART_FEA_RTC         0x0001
#define ED_CART_FEA_SPD         0x0002
#define ED_CART_FEA_BAT         0x0004
#define ED_CART_FEA_CRC_RAM     0x0008
#define ED_CART_TYPE            0xff00

#define EEP_SIZE_512 6
#define EEP_SIZE_8K  14

#define GBA_WAITCNT *((vu32 *)0x4000204)
#define GBA_TIMER1_VAL *((vu16 *)0x4000104)
#define GBA_TIMER1_CFG *((vu16 *)0x4000106)
#define IRQ_ACK_REG *(vu16 *) 0x4000202
#define IRQ_GAME_PAK 0x2000

u8 ed_init();
void ed_lock_regs();
void ed_unlock_regs();
void ed_dma_mem(void *src, void *dst, int len);
u8 ed_sd_dma_wr(void *src);
void ed_sd_read_crc_ram(void *dst) ;

void ed_sd_cmd_wr(u8 data);
u8 ed_sd_cmd_rd();
u8 ed_sd_cmd_val();
void ed_sd_dat_wr(u8 data);
u8 ed_sd_dat_rd();
u8 ed_sd_dma_rd(void *dst, int slen);

void ed_sd_mode(u8 mode);
void ed_sd_speed(u8 speed);

u8 ed_eep_write(void *src, u16 addr, u16 len);
u8 ed_eep_read(void *dst, u16 addr, u16 len);
void ed_set_eep_size(u8 size);
void ed_set_save_type(u8 save_type);

u16 ed_flash_id();
void ed_flash_erase_chip();
void ed_flash_erase_sector(u8 sector);
void ed_flash_write(void *src, u32 addr, u32 len);
void ed_flash_set_bank(u8 bank);

void ed_sram_read(void *dst, u32 offset, u32 len);
void ed_sram_write(void *src, u32 offset, u32 len);
u16 ed_get_fpga_ver();

void ed_rtc_on();
void ed_rtc_off();



void ed_set_rom_bank(u8 bank);
void ed_set_rom_mask(u32 rom_size);
void ed_reboot(u8 quick_boot);


#endif	/* EVERDRIVE_H */

