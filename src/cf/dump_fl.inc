// dump_fl.inc
#include "at25df081a.h"

#undef AINSU_DUMP_EXTERN
#define AINSU_DUMP_EXTERN

/* Charley Shatttuck's rdumps() */

/* Tiny interpreter,
   similar to myforth's Standalone Interpreter
   This example code is in the public domain */

/* dump 16 bytes of RAM in hex with ascii on the side */

/*
void d_three_sp(void) {         // print three spaces
    for (int i = 3; i > 0; i--) {
        putch('\040');
    }
}


void d_two_sp(void) {
    putch('\040');
    putch('\040');
}

*/

/*
 55 #include "at25df081a.h"
 56 
 57   static uint8_t read_buff_b[4]; at25dfx_read(read_buff_b, 8, k);
*/

static uint8_t read_buff_d[1];



/*


 25 void dumpRAM() {
 26     char *ram;
 27     int p = psp[0];
 28     psp++;
 29     ram = (char *) p;
 30     printf("\n%4X: ", p);
*/
void dumpflROM() {
    char *rom;
    // pop address off TOS
    int p = psp[0];
    psp++;


    // read one byte of flash at flash address p
    at25dfx_read(read_buff_d, 1, p);

    // rom = (char *) p;
    rom = (char *) read_buff_d;

    // print address p followed by ':' in a formatted string:
    printf("\n%4X: ", p);



    int count = -1;
    for (int i = 0; i < 16; i++) {
        count++;
        if (i == 8)
            putch('\040');
        if (count > 3) {
            count = (count & 0x03);
            putch('\040');
        }

        p++; // increment flash address

        // char c = *rom++;
        at25dfx_read(read_buff_d, 1, p);
        p++;

        char c = (uint32_t) read_buff_d;
        printf(" %02X", (c & 0xff));
    }

    // rom = (char *) p;

    at25dfx_read(read_buff_d, 1, p);
    rom = (char *) read_buff_d;

    d_three_sp();

    for (int i = 0; i < 16; i++) {
        // print_string[0] = (uint32_t) * rom++;

        at25dfx_read(read_buff_d, 1, p);

        print_string[0] = (uint32_t) * rom; p++;

        if (print_string[0] > 0x7e || print_string[0] < ' ')
            print_string[0] = (uint32_t) '.';
        print_string[1] = '\0';
        chopped_acm_write(print_string);
    }
    psp--;
    psp[0] = p + 16;

}

/* dump 256 bytes of RAM */
CODE(dump) {                    /* adr n -- */
    int j = psp[0];
    psp++;
    for (int i = 0; i < j; i++) {
        // dumpRAM();
        dumpflROM();
    }
}
