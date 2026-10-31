// range: 0x36E060 0x36E0F0
#include "common.h"

s32 func_002E6770(s32, s32);

s32 func_0036E060(s32 arg0, s32 arg1) {
    s32 best;
    s32 i;
    s32 val;

    best = 0;
    i = 0;
    do {
        val = func_002E6770(arg0, i);
        if (val >= best) {
            best = func_002E6770(arg0, i);
        }
        i++;
    } while (i < 0x14);
    return arg1 < best;
}
