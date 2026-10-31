// range: 0x37BAB0 0x37BB10
#include "common.h"

extern void func_003724B0(char *, s32);

void func_0037BAB0(char **arg0) {
    s32 i;
    char *p;

    i = 0;
    do {
        p = arg0[i];
        if (p != 0) {
            func_003724B0(p, 1);
        }
        i++;
    } while (i < 4);
}
