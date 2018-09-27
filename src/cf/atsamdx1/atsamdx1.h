#include <string.h>

#define timeStamp(t,l) \
    "Thu Sep 13 03:52:11 UTC 2018\n\n", 32
// current target branch:
#define branchStamp(b,l) \
    "ainsu_camelforth_USB_CDC_ab-    ", 32

// #define branchStamp(b,l) "master    ", 10

#define stack_buffer_length 64

/*
 20 char ch[0]; // holds an 8-bit keystroke
 21 
 22 int read_ln = 0; // how many chars were read
*/

extern char ch[0]; // holds an 8-bit keystroke
extern int read_ln; // = 0; // how many chars were read

// extern struct io_descriptor *io;
extern char print_string[stack_buffer_length];
// extern void USART_0_setup_local(void);
// extern void USART_0_loop_camelforth(void);
char print_string[stack_buffer_length];
extern void USB_loop_camelforth(void);

// 14 SEP 01:30 UTC:

// extern char tib_buffer[CDCD_ECHO_BUF_SIZCF / 4];


// 14 SEP 02:31 UTC:

// extern char tib_buffer[16];
// char tib_buffer[16];

// bogus approach.  need to propagate this from its one original source. wa1tnr KLUDGE
#if CONF_USBD_HS_SP
#define CDCD_ECHO_BUF_SIZCF CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ_HS
#else
#define CDCD_ECHO_BUF_SIZCF CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ
#endif
extern char usbd_cdc_in_buffer[CDCD_ECHO_BUF_SIZCF / 4];
extern char usbd_cdc_out_buffer[CDCD_ECHO_BUF_SIZCF / 4];
extern char tib_buffer[CDCD_ECHO_BUF_SIZCF / 4];
extern char tib_out_buffer[CDCD_ECHO_BUF_SIZCF / 4];
extern char msg_buffer[CDCD_ECHO_BUF_SIZCF / 4];
char tib_buffer[CDCD_ECHO_BUF_SIZCF / 4];
char tib_out_buffer[CDCD_ECHO_BUF_SIZCF / 4];
char msg_buffer[CDCD_ECHO_BUF_SIZCF / 4];

extern bool STATE_KEYBOARD; //  = 0; // usb_start.c
