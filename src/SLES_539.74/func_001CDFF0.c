// range: 0x1CDFF0 0x1CE020
#include "common.h"

extern s32 D_00412150[0x20];

s32 func_001CDFF0(void) {
    s32 i;
    s32 *p;

    i = 0;
    do {
        p = &D_00412150[i];
        i += 1;
        *p = 0;
    } while (i < 0x20);
    return 1;
}
