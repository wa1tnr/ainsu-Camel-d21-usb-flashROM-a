// dump_fl.inc
#include "at25df081a.h"

#undef AINSU_DUMP_EXTERN
#define AINSU_DUMP_EXTERN

/* Charley Shatttuck's rdumps() */

/* Tiny interpreter,
   similar to myforth's Standalone Interpreter
   This example code is in the public domain */

/* dump 16 bytes of RAM in hex with ascii on the side */

static uint8_t read_buff_d[1];

void dumpflROM() {
    int p = psp[0]; psp++;
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
        at25dfx_read(read_buff_d, 1, p++);
        char c = (uint32_t) read_buff_d[0];
        printf(" %02X", (c & 0xff));
    }
    p = p - 16;
    d_three_sp();
    for (int i = 0; i < 16; i++) {
        at25dfx_read(read_buff_d, 1, p++); 
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
        dumpflROM();
    }
}
