/**
 * \file
 *
 * \brief API driver for AT25DF081A SerialFlash component.
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef AT25DF08A1_H_
#define AT25DF08A1_H_

/** AT25 device ID */
#define AT25DFX_DEV_ID 0x0001451F
/** AT25 total size */
#define AT25DFX_SIZE (1 * 1024 * 1024)

/** The page size of AT25DF series is always 256 */
#define AT25DFX_PAGE_SIZE 256

/** Device ready/busy status bit */
#define AT25_STATUS_RDYBSY (1 << 0)
/** Device is ready */
#define AT25_STATUS_RDYBSY_READY (0 << 0)
/** Device is busy with internal operations */
#define AT25_STATUS_RDYBSY_BUSY (1 << 0)
/** Write enable latch status bit */
#define AT25_STATUS_WEL (1 << 1)
/** Device is not write enabled */
#define AT25_STATUS_WEL_DISABLED (0 << 1)
/** Device is write enabled */
#define AT25_STATUS_WEL_ENABLED (1 << 1)
/** Software protection status bitfield */
#define AT25_STATUS_SWP (3 << 2)
/** All sectors are software protected */
#define AT25_STATUS_SWP_PROTALL (3 << 2)
/** Some sectors are software protected */
#define AT25_STATUS_SWP_PROTSOME (1 << 2)
/** No sector is software protected */
#define AT25_STATUS_SWP_PROTNONE (0 << 2)
/** Write protect pin status bit */
#define AT25_STATUS_WPP (1 << 4)
/** Write protect signal is not asserted */
#define AT25_STATUS_WPP_NOTASSERTED (0 << 4)
/** Write protect signal is asserted */
#define AT25_STATUS_WPP_ASSERTED (1 << 4)
/** Erase/program error bit */
#define AT25_STATUS_EPE (1 << 5)
/** Erase or program operation was successful */
#define AT25_STATUS_EPE_SUCCESS (0 << 5)
/** Erase or program error is detected */
#define AT25_STATUS_EPE_ERROR (1 << 5)
/** Sector protection registers locked bit */
#define AT25_STATUS_SPRL (1 << 7)
/** Sector protection registers are unlocked */
#define AT25_STATUS_SPRL_UNLOCKED (0 << 7)
/** Sector protection registers are locked */
#define AT25_STATUS_SPRL_LOCKED (1 << 7)

/** Read array command code */
#define AT25_READ_ARRAY_100MHz 0x1B
#define AT25_READ_ARRAY_85MHz 0x0B
#define AT25_READ_ARRAY_50MHz 0x03
#define AT25_DUAL_READ_ARRAY_85MHz 0x3B

/** Block erase command code (4K block) */
#define AT25_BLOCK_ERASE_4K 0x20
#define AT25_BLOCK_ERASE_32K 0x52
#define AT25_BLOCK_ERASE_64K 0xD8
#define AT25_CHIP_ERASE_1 0x60
#define AT25_CHIP_ERASE_2 0xC7

/** Byte/page program command code */
#define AT25_BYTE_PAGE_PROGRAM 0x02
#define AT25_DUAL_BYTE_PAGE_PROGRAM 0xA2

#define AT25_SEQUENTIAL_PROGRAM_1 0xAD
#define AT25_SEQUENTIAL_PROGRAM_2 0xAF

/** Write enable command code */
#define AT25_WRITE_ENABLE 0x06
#define AT25_WRITE_DISABLE 0x04
#define AT25_PROTECT_SECTOR 0x36
#define AT25_UNPROTECT_SECTOR 0x39
#define AT25_READ_SECTOR_PROT 0x3C

/** Security commands code */
#define AT25_SECTOR_LOCKDOWN 0x33
#define AT25_FREEZ_SECTOR_LOCKDOWN 0x34
#define AT25_READ_SECTOR_LOCKDOWN_REG 0x35
#define AT25_PROG_OTP_SEC_REG 0x9B
#define AT25_READ_OTP_SEC_REG 0x77

/** Read status register command code */
#define AT25_READ_STATUS 0x05
#define AT25_WRITE_STATUS 0x01

/** Miscellaneous commands */
#define AT25_RESET 0xF0
#define AT25_READ_JEDEC_ID 0x9F
#define AT25_DEEP_PDOWN 0xB9
#define AT25_RES_DEEP_PDOWN 0xAB

/** Global protection data */
#define AT25_GLOBAL_PROTECT_VALUE 0x3C

/** Sector Protection Register value is 1 (sector is protected) */
#define AT25_SECTOR_PROTECTED_VALUE 0xff

/** Sector Protection Register value is 0 (sector is unprotected) */
#define AT25_SECTOR_UNPROTECTED_VALUE 0x0

/** Protect type code */
#define AT25_TYPE_PROTECT 0x1

/** Unprotect type code */
#define AT25_TYPE_UNPROTECT 0x0

/** AT25 operation status, each operation returns one of the following status */
typedef enum at25_status {
	AT25_SUCCESS = 0,        /** Current operation successful */
	AT25_SECTOR_PROTECTED,   /** Sector protected */
	AT25_SECTOR_UNPROTECTED, /** Sector unprotected */
	AT25_ERROR_INIT,         /** Initialization error: p_at25->pdesc is not initialized */
	AT25_ERROR_NOT_FOUND,    /** The specific SerialFlash Not found  */
	AT25_ERROR_WRITE,        /** Write error returned by the SerialFlash */
	AT25_ERROR_BUSY,         /** Current operation failed, SerialFlash is busy */
	AT25_ERROR_PROTECTED,    /** Current operation failed, SerialFlash is protected */
	AT25_ERROR_SPI,          /** SPI transfer failed */
	AT25_ERROR               /** Current operation failed */
} at25_status_t;

void          at25dfx_init_interface(void);
at25_status_t at25dfx_read_dev_id(uint32_t *dev_id);

at25_status_t at25dfx_mem_check(void);
at25_status_t at25dfx_read_status(uint8_t *status);
at25_status_t at25dfx_write_status(uint8_t status);
at25_status_t at25dfx_read_sector_protect_status(uint32_t address);
at25_status_t at25dfx_protect_sector(uint32_t address, uint8_t protect_type);
at25_status_t at25dfx_protect_chip(uint8_t protect_type);
at25_status_t at25dfx_erase_chip(void);
at25_status_t at25dfx_erase_block(uint32_t address);
at25_status_t at25dfx_read(uint8_t *data, uint16_t size, uint32_t address);
at25_status_t at25dfx_write(uint8_t *data, uint16_t size, uint32_t address);

#endif /* AT25DF08A1_H_ */
