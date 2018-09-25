/**
 * \file
 *
 * \brief Application implement
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <atmel_start.h>
#include "at25df081a.h"

/* Test size */
#define AT25DFX_TEST_DATA_SIZE (1024)

/* Test block start address */
#define AT25DFX_TEST_BLOCK_ADDR (0)

/* Buffer used to write in this example */
static uint8_t write_buff[AT25DFX_TEST_DATA_SIZE];

/* Buffer used to read in this example */
static uint8_t read_buff[AT25DFX_TEST_DATA_SIZE];
/*
void error(void)
{
	gpio_set_pin_level(USER_LED, true);
}
*/

void delay_some(void) {
    for (volatile int i=23000; i>0; i--) { }
}

void blink(void) {
	gpio_set_pin_level(USER_LED, true);
        delay_some();
	gpio_set_pin_level(USER_LED, false);
        delay_some();
        delay_some();
        delay_some();
}

void blinks(void) {
    blink();
    blink();
    blink();
    blink();
    blink();
    blink();
    blink();
}

void error(void)
{
	// gpio_set_pin_level(USER_LED, true);
        // blinks();
        while(1) {
                blink(); blink();
                delay_some(); delay_some(); delay_some(); delay_some(); delay_some();
                delay_some(); delay_some(); delay_some(); delay_some(); delay_some();
                delay_some(); delay_some(); delay_some(); delay_some(); delay_some();
                blink();
        }
}

void error_special(void)
{
                blink(); blink(); delay_some(); delay_some(); delay_some(); delay_some(); delay_some();
                blink(); blink(); delay_some(); delay_some(); delay_some(); delay_some(); delay_some();
                blink(); blink(); delay_some(); delay_some(); delay_some(); delay_some(); delay_some();
}

void nice(void) {
    blinks();
}

int main(void)
{
	uint16_t i;

	atmel_start_init();
        // nice();

        // while(1) { }

	at25dfx_init_interface();

	/* Unprotect the chip */
	if (at25dfx_protect_chip(AT25_TYPE_UNPROTECT) == AT25_SUCCESS) {
		gpio_set_pin_level(USER_LED, false);
	} else {
		error();
	}

	/* Check if the SerialFlash is valid */

	if (at25dfx_mem_check() == AT25_SUCCESS) {
		gpio_set_pin_level(USER_LED, false);
	} else {
		error();
	}


	/* Prepare half of the SerialFlash sector as 0xAA */
	for (i = 0; i < AT25DFX_TEST_DATA_SIZE / 2; i++) {
		write_buff[i] = 0xAA;
		read_buff[i]  = 0;
	}

	/* And the remaining half as 0x55 */
	for (; i < AT25DFX_TEST_DATA_SIZE; i++) {
		write_buff[i] = 0x55;
		read_buff[i]  = 0;
	}

	/* Erase the block before write */
	at25dfx_erase_block(AT25DFX_TEST_BLOCK_ADDR);

	/* Write the data to the SerialFlash */
	at25dfx_write(write_buff, AT25DFX_TEST_DATA_SIZE, AT25DFX_TEST_BLOCK_ADDR);

	/* Read back this sector and compare them with the expected values */
	at25dfx_read(read_buff, AT25DFX_TEST_DATA_SIZE, AT25DFX_TEST_BLOCK_ADDR);

	for (i = 0; i < AT25DFX_TEST_DATA_SIZE / 2; i++) {
		if (read_buff[i] != 0xAA) {
			error();
                        // error_special();
		}
	}
        // error_special();
	for (; i < AT25DFX_TEST_DATA_SIZE; i++) {
		if (read_buff[i] != 0x55) {
			error();
                        // error_special();
		}
	}
        error_special();
	while (1) {
	}
}
