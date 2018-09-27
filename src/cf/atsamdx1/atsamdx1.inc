/****h* camelforth/atsamdx1/atsamdx1.inc
 *
 * from:
 ****h* camelforth/tivaio.c
 *
 * NAME
 *  atsamdx1.inc
 * DESCRIPTION
 *  Terminal I/O, and main entry point for
 *  CamelForth in C, for the ATSAMD51J19A and ATSAMD21G18A
 *  Adafruit Metro M4 Express target board,
 *  Adafruit Feather M0 Express target board.
 * SYNOPSIS
 *  Provides the functions
 *      void putch(char c)      write one character to terminal
 *      char getch(void)        await/read one character from keyboard
 *      int getquery(void)      return true if keyboard char available
 *      void initTermios(void)  NOT IMPLEMENTED - configure terminal for Forth
 *      void resetTermios(void) NOT IMPLEMENTED - reset terminal configuration, if req'd
 *      void camelforth(void)   main entry point for SAMDx1.   UPSTREAM: int main(void)
 *
 * AUTHORS
 *  Brad Rodriguez
 *  wa1tnr
 ******
 * LICENSE TERMS
 *  CamelForth in C
 *  copyright (c) 2016,2017 Bradford J. Rodriguez.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Commercial inquiries should be directed to the author at
 *  115 First St., #105, Collingwood, Ontario L9Y 4W3 Canada
 *  or via email to bj@camelforth.com
 */

#include <atmel_start.h>
#include <stdio.h>
#include "atsamdx1.h"

/*
extern char ch[];
*/
extern void queryKey(void);
extern int read_ln;
extern unsigned int getKey(void); // hardware-independent wrapper

/*
#include <stdint.h>
#include <stdbool.h>
*/

// #define NULL 0  // already defined for Atmel Start and gcc:

/*
 * Terminal I/O functions
 */

int length_print_string = 0; // would like to shed this global

#include "cut.inc" // string cutter utility, for long USB printf's:




/* USB based */
#define printf(format,integer) \
    length_print_string = 0; \
    print_string[0] = (uint32_t) "\0"; \
    sprintf(print_string, format, integer); \
    length_print_string = strlen(print_string); \
        chopped_acm_write(print_string)

//  io_write(io, (uint8_t *)print_string, length_print_string)




#ifdef OBSOLETE_AINSU
/* USB based */
#define printf(format,integer) \
    length_print_string = 0; \
    print_string[0] = (uint32_t) "\0"; \
    sprintf(print_string, format, integer); \
    length_print_string = strlen(print_string); \
    if (length_print_string > CHOP_LN) { \
        chopped_acm_write(print_string); \
    } else { \
        cdcdf_acm_write((uint8_t *)print_string, strlen(print_string)); \
    }

//  io_write(io, (uint8_t *)print_string, length_print_string)
#endif // #ifdef OBSOLETE_AINSU




/* USART based
#define printf(format,integer) \
    length_print_string = 0; \
    print_string[0] = (uint32_t) "\0"; \
    sprintf(print_string, format, integer); \
    length_print_string = strlen(print_string); \
    io_write(io, (uint8_t *)print_string, length_print_string)
*/

void fake_aa(char * s, int l) {
}

// #define printf UARTprintf
// #define print_this(s,l) io_write(io, (uint8_t *)s, l);
#define print_this(s,l) fake_aa(s, l);

// #define getch UARTgetc
#define getch getKey


/*
void putch(char c) {
    char *p;
    p = &c;
    io_write(io, (uint8_t *) p, 1);
}
*/


void putch(char c) {
    char *p;
    p = &c;
    c = *p + 0;
    // io_write(io, (uint8_t *) p, 1);
}


/*
int getquery(void) {
    // return(UARTCharsAvail(UART0_BASE) != 0);
    int l_read_ln = 0;
    int not_found = 1;
    while(not_found) {
        queryKey(); // sets read_ln;
        if (read_ln > 0) not_found = 0; // escape loop
    }
    // return(UARTCharsAvail(UART0_BASE) != 0);
    io_write(io, (uint8_t *)" !chars! ", 9);
    l_read_ln = read_ln;
    read_ln = 0;
    return l_read_ln; // can be more than 1
}

*/

int getquery(void) {
    return -1;
}




/****f* main/main
 * NAME
 *  main
 * SYNOPSIS
 *  int main(void)
 * DESCRIPTION
 *  Main program, entered after an MCU reset.
 ******
 */

void interpreter(void);         /* forward reference */

void camelforth(void) {

    // for (volatile int i=8001002; i>0; i--) {

    for (volatile int i=3030303; i>0; i--) {
        // empty loop to delay
    }

    strcpy(tib_buffer, "\n\ncamel");
    for (volatile int i=2048; i>0; i--) { }
    cdcdf_acm_write((uint8_t *)tib_buffer, strlen(tib_buffer));

    for (volatile int i=2048; i>0; i--) { }

    strcpy(tib_buffer, "forth");
    for (volatile int i=2048; i>0; i--) { }
    cdcdf_acm_write((uint8_t *)tib_buffer, strlen(tib_buffer));

    for (volatile int i=2048; i>0; i--) { }

    strcpy(tib_buffer, "()\n\n"); // length: 15
    for (volatile int i=2048; i>0; i--) { }
    cdcdf_acm_write((uint8_t *)tib_buffer, strlen(tib_buffer));

    for (volatile int i=2048; i>0; i--) { }

    // above line modded for newline output 14 SEP 02:00 UTC.
    // cdcdf_acm_write((uint8_t *)tib_buffer, strlen(tib_buffer));

    while (1) {     /* loop in case interpreter() ever terminates */

        interpreter();
        strcpy(tib_buffer, " ~NOterpr ~");
        cdcdf_acm_write((uint8_t *)tib_buffer, strlen(tib_buffer));
        for (volatile int i=2048; i>0; i--) { }
        // 14 SEP 02:00 appears that interpreter() is called and
        // perhaps calls 'emit()' at least once.  ISRT that the
        // signon message has lots of emit()s that should be seen,
        // once live code is running.
        // right now it's boilerplate (should repeat though, perhaps?)
        // that is, emit() should still be called more than one time.
    }
}
