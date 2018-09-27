/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */
#include "atmel_start.h"
#include "usb_start.h"

extern void camelforth(void);

extern char ch[0]; // holds an 8-bit keystroke
extern int read_ln; // = 0; // how many chars were read


#if CONF_USBD_HS_SP
static uint8_t single_desc_bytes[] = {
    /* Device descriptors and Configuration descriptors list. */
    CDCD_ACM_HS_DESCES_LS_FS};
static uint8_t single_desc_bytes_hs[] = {
    /* Device descriptors and Configuration descriptors list. */
    CDCD_ACM_HS_DESCES_HS};
#define CDCD_ECHO_BUF_SIZ CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ_HS
#else
static uint8_t single_desc_bytes[] = {
    /* Device descriptors and Configuration descriptors list. */
    CDCD_ACM_DESCES_LS_FS};
#define CDCD_ECHO_BUF_SIZ CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ
#endif

static struct usbd_descriptors single_desc[]
    = {{single_desc_bytes, single_desc_bytes + sizeof(single_desc_bytes)}
#if CONF_USBD_HS_SP
       ,
       {single_desc_bytes_hs, single_desc_bytes_hs + sizeof(single_desc_bytes_hs)}
#endif
};

/** Buffers to receive and echo the communication bytes. */
char usbd_cdc_in_buffer[CDCD_ECHO_BUF_SIZ / 4];
char usbd_cdc_in_buffer[CDCD_ECHO_BUF_SIZ / 4];
char usbd_cdc_out_buffer[CDCD_ECHO_BUF_SIZ / 4];
char tib_buffer[CDCD_ECHO_BUF_SIZ / 4];
char msg_buffer[CDCD_ECHO_BUF_SIZ / 4];

uint8_t cdc_packet_buffer[CDCD_ECHO_BUF_SIZ / 4];

/** Ctrl endpoint buffer */
static uint8_t ctrl_buffer[64];


/* usb.c */

static volatile bool pending_read;
// static int32_t start_read(void);



bool STATE_KEYBOARD  = false; // false; no keystrokes waiting


void reset_boolean_keystroke(void) {
    STATE_KEYBOARD  = false;

    strcpy(msg_buffer, "reset_bkey() ");
    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    
}

void set_boolean_keystroke(void) {
    STATE_KEYBOARD  = true; // true; keystroke(s) waiting

/*
    strcpy(msg_buffer, "SET_bkey() ");
    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
*/
}


void a_short_delay(void) {
    for (volatile int i=133; i>0; i--) { }

}

bool local_process_keystroke(void) {
    strcpy(msg_buffer, "LPKS "); cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    a_short_delay(); a_short_delay(); a_short_delay();
    return false; // no error
}

/*
109 static int32_t start_read(void) {
110     pending_read = true;
111     int32_t result = cdcdf_acm_read(cdc_packet_buffer, CDC_BULKOUT_SIZE);
112     if (result != ERR_NONE) {
113         pending_read = false;
114     }
115     return result;
116 }
*/


bool process_keystroke(void) { // used with getKey()

// --------------------- NULL -----------------
//  usbd_cdc_in_buffer[0] = '\0'; // reset non-empty buffer, to
// --------------------- NULL -----------------

    while (strlen(usbd_cdc_in_buffer) == 0) {
        cdcdf_acm_read((uint8_t *)usbd_cdc_in_buffer, sizeof(usbd_cdc_in_buffer));
    }

    if (strlen(usbd_cdc_in_buffer) == 1) {
        strcpy(msg_buffer,"got one\n");
        cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
        a_short_delay();
    }

    strcpy(msg_buffer, "MADE: "); cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
    a_short_delay();

    ch[0]=usbd_cdc_in_buffer[0]; // collect, if any
    // ch[1]='\0';

    // works: // strcpy(msg_buffer, ch);

/*
    msg_buffer[0] = ch[0];
    msg_buffer[1] = '\n';
    msg_buffer[2] = '\0';

    cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
*/

    return false;
}




bool foo(void) {


    if (! STATE_KEYBOARD) {
        ch[0]=usbd_cdc_in_buffer[0]; // collect, if any
    }

    for (volatile int k=1024; k>0; k--) { // bad form is what amounts to an ISR
    }

    // usbd_cdc_in_buffer[0]='\0'; // force empty buffer - this worked to block input

    if (strlen(usbd_cdc_in_buffer) > 0) {
        set_boolean_keystroke();
    } else {
        reset_boolean_keystroke();
    }

    // seems like as soon as cdcdf_acm_read() execs the rest of this is bypassed
    // in favor of another async output path:

/*
    if ((uint8_t) usbd_cdc_out_buffer[0] == 'P') {

        usbd_cdc_out_buffer[0]='Q'; // SUCCESS - substitution is made

        usbd_cdc_out_buffer[1]='\0';

        tib_buffer[0]=usbd_cdc_out_buffer[0];
        tib_buffer[1]='\0';

        return -1;

    }
    return 0;
*/
    return 0;
}

/**
 * \brief Callback invoked when bulk OUT data received
 */

int count_output_Bytes = 0;

// 13 SEP 06:17 UTC, hey this worked:
void buffer_translate(void) { // also works to affect program behavior
    if ((uint8_t) usbd_cdc_out_buffer[0] != '\0') { // bad assumption here TODO KLUDGE wa1tnr
        count_output_Bytes++;
        if (count_output_Bytes == 10) {
            count_output_Bytes = 0;
        } else { // if we haven't seen ten bytes ..
            usbd_cdc_out_buffer[0] = '\0';
        }
    }
    if ((uint8_t) usbd_cdc_out_buffer[0] == 'P') {
        // usbd_cdc_out_buffer[0]='R';
        usbd_cdc_out_buffer[0]='K';
        usbd_cdc_out_buffer[1]='\0';

        tib_buffer[0]=usbd_cdc_out_buffer[0];
        tib_buffer[1]='\0';
    }
}

uint32_t counted = 0;

// void process_output(uint32_t count) {
void process_output(void) {
        // buffer_translate();


        // ONLY output 14 SEP 01:29 UTC:
        // 14 SEP 02:23 UTC, commented out one line:
        // cdcdf_acm_write((uint8_t *)usbd_cdc_out_buffer, counted);

        // NOTE 14 SEP 02:23 UTC: this means acm_write is ONLY
        // called from emit() in forth.c.
}

static bool usb_device_cb_bulk_out(const uint8_t ep,
    const enum usb_xfer_code rc, const uint32_t count)
{
	cdcdf_acm_read((uint8_t *)usbd_cdc_in_buffer, sizeof(usbd_cdc_in_buffer));

        // counted = count;
        // process_output();
        // cdcdf_acm_write((uint8_t *)usbd_cdc_out_buffer, count);

	// No error. //
	return false;
}


/**
 * \brief Callback invoked when bulk IN data received
 */

static bool usb_device_cb_bulk_in(const uint8_t ep, const enum usb_xfer_code rc, const uint32_t count)
{
	// Echo data. //
	// cdcdf_acm_read((uint8_t *)usbd_cdc_in_buffer, sizeof(usbd_cdc_in_buffer));
        // start_read();
	// cdcdf_acm_read((uint8_t *)usbd_cdc_in_buffer, sizeof(usbd_cdc_in_buffer));

	// No error. //
	return false;
}

/**
 * \brief Callback invoked when Line State Change
 */
static bool usb_device_cb_state_c(usb_cdc_control_signal_t state)
{
	if (state.rs232.DTR) {
		/* Callbacks must be registered after endpoint allocation */
		cdcdf_acm_register_callback(CDCDF_ACM_CB_READ, (FUNC_PTR)usb_device_cb_bulk_in);
		// cdcdf_acm_register_callback(CDCDF_ACM_CB_READ, (FUNC_PTR)my_put_fcn);

		cdcdf_acm_register_callback(CDCDF_ACM_CB_WRITE, (FUNC_PTR)usb_device_cb_bulk_out);
		// cdcdf_acm_register_callback(CDCDF_ACM_CB_WRITE, (FUNC_PTR)my_get_fcn);

		/* Start Rx */ // BIG KLUDGE 05:22 UTC 13 SEP REVISIT TODO wa1tnr DEBUG
                // start_read();
		cdcdf_acm_read((uint8_t *)usbd_cdc_in_buffer, sizeof(usbd_cdc_in_buffer));

// --------------------- NULL -----------------
        //      usbd_cdc_in_buffer[0] = '\0'; // reset non-empty buffer, to
// --------------------- NULL -----------------

	}
        strcpy(msg_buffer, "\ncb_state_c");
        cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
        for (volatile int i=208; i>0; i--) { }

        strcpy(msg_buffer, "() \n");
        cdcdf_acm_write((uint8_t *)msg_buffer, strlen(msg_buffer));
        for (volatile int i=208; i>0; i--) { }

// --------------------- NULL -----------------
//      usbd_cdc_in_buffer[0] = '\0'; // reset non-empty buffer, to
// --------------------- NULL -----------------
// NEED ONE HERE?
        // start_read();

        // for (volatile int i=922048; i>0; i--) { }

	/* No error. */
	return false;
}

/**
 * \brief CDC ACM Init
 */
void cdc_device_acm_init(void)
{
	/* usb stack init */
	usbdc_init(ctrl_buffer);

	/* usbdc_register_funcion inside */
	cdcdf_acm_init();

	usbdc_start(single_desc);
	usbdc_attach();
}

/**
 * Example of using CDC ACM Function.
 * \note
 * In this example, we will use a PC as a USB host:
 * - Connect the DEBUG USB on XPLAINED board to PC for program download.
 * - Connect the TARGET USB on XPLAINED board to PC for running program.
 * The application will behave as a virtual COM.
 * - Open a HyperTerminal or other COM tools in PC side.
 * - Send out a character or string and it will echo the content received.
 */
void cdcd_acm_example(void)
{
	while (!cdcdf_acm_is_enabled()) {
		// wait cdc acm to be installed
	};

	cdcdf_acm_register_callback(CDCDF_ACM_CB_STATE_C, (FUNC_PTR)usb_device_cb_state_c);

        camelforth();

	while (1) {
/*
            usbd_cdc_out_buffer[0] = 'S'; // random selection: OUT buffer - did not think this thru
            usbd_cdc_out_buffer[1] = '\0';
*/
            /*
            */
	}
}

void usb_init(void)
{ 
	cdc_device_acm_init();
}
