// range: 0x307D90 0x307E00
#include "common.h"

s32 func_00307D90(void *arg0, s32 arg1) {
    s32 *bitmap;
    s32 mask;
    s32 bit;

    if (arg1 <= 0 || arg1 >= 0x280) {
        return 0;
    }
    bitmap = (s32 *)((char *)arg0 + 0x2D0);
    mask = 1;
    bit = arg1 % 32;
    mask = mask << bit;
    bitmap += arg1 / 32;
    return (mask & *bitmap) != 0;
}
