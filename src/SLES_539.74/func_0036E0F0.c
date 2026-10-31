// range: 0x36E0F0 0x36E160
#include "common.h"

s32 func_002E6770(s32, s32);

s32 func_0036E0F0(s32 arg0) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (0 < func_002E6770(arg0, i)) {
            count++;
        }
        i++;
    } while (i < 10);
    return count;
}
