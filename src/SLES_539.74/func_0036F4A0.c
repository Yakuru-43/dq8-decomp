// range: 0x36F4A0 0x36F4D0
#include "common.h"

extern s32 D_00458780[0x20];

void func_0036F4A0(void) {
    s32 i;
    s32 *p;

    i = 0;
    do {
        p = &D_00458780[i];
        i += 1;
        *p = 0;
    } while (i < 0x20);
}
