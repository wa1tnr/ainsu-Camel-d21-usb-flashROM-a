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
    // char *rom;
    int p = psp[0]; psp++; // pop address off TOS

    // at25dfx_read(read_buff_d, 1, p); // read one byte of flash at flash address p

    // rom = (char *) p;
    // rom = (char *) read_buff_d;

    // print address p followed by ':' in a formatted string:
    printf("\n%4X:jkl ", p);

    int count = -1;
    for (int i = 0; i < 16; i++) {
        count++;
        if (i == 8)
            putch('\040');
        if (count > 3) {
            count = (count & 0x03);
            putch('\040');
        }
        at25dfx_read(read_buff_d, 1, p++);

        char c = (uint32_t) read_buff_d;
        printf(" %02X", (c & 0xff));
    }
    p = p - 32;

    // at25dfx_read(read_buff_d, 1, p++);
    // rom = (char *) read_buff_d;

    d_three_sp();

    for (int i = 0; i < 16; i++) {
        // print_string[0] = (uint32_t) * rom++;

        at25dfx_read(read_buff_d, 1, p++); // p++;

        // print_string[0] = (uint32_t) * rom;
        print_string[0] = (uint32_t) * read_buff_d;

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
