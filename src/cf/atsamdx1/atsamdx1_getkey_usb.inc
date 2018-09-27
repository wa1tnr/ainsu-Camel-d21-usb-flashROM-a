// Tue Sep 11 00:49:37 UTC 2018

#include "atsamdx1.h"

// bogus approach.  need to propagate this from its one original source. wa1tnr KLUDGE
#if CONF_USBD_HS_SP
#define CDCD_ECHO_BUF_SIZCF CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ_HS
#else
#define CDCD_ECHO_BUF_SIZCF CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ
#endif

extern char usbd_cdc_buffer[CDCD_ECHO_BUF_SIZCF / 4];
extern char tib_buffer[CDCD_ECHO_BUF_SIZCF / 4];

extern bool process_keystroke(void);
extern void process_output(void);

// #include <atmel_start.h>

char ch[0]; // holds an 8-bit keystroke

int read_ln = 0; // how many chars were read

void _USART_read(void) { // hardware implementation-dependent keystroke reader
    process_keystroke();


    read_ln = 1;
}

unsigned int getKey(void) { // hardware-independent wrapper
    // _USART_read();
    while (strlen(usbd_cdc_in_buffer) == 0) {

        cdcdf_acm_read((uint8_t *)usbd_cdc_in_buffer, sizeof(usbd_cdc_in_buffer));
    }

    uint8_t ch_read = (uint32_t) usbd_cdc_in_buffer[0]; // ch[0];
    usbd_cdc_in_buffer[0] = '\0';
    usbd_cdc_in_buffer[1] = '\0';

/*
    ch[0] = '\0';
    ch[1] = '\0';
*/

/*
    strcpy(msg_buffer, "getKey ");
    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    for (volatile int i = 888; i>0; i--) { }

    strcpy(msg_buffer, "returns: ");
    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    for (volatile int i = 888; i>0; i--) { }

    msg_buffer[0] = ch_read;
    msg_buffer[1] = '\0';
    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    for (volatile int i = 888; i>0; i--) { }
*/

/*
    strcpy(msg_buffer, "<bracketed. ");
    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    for (volatile int i = 888; i>0; i--) { }
*/

    return ch_read;
}

void queryKey(void) {
    _USART_read();
}
