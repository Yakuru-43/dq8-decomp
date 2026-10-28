// range: 0x203E20 0x203E90
#include "common.h"

s32 func_00204000(s32, s32, s32);

s32 func_00203E20(s32 arg0, s32 arg1) {
    s32 sum;
    s32 i;

    sum = 0;
    i = 0;
    do {
        sum += func_00204000(arg0, i, arg1);
        i++;
    } while (i < 5);
    return sum;
}
