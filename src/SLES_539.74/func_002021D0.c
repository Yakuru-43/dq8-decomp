// range: 0x2021D0 0x202230
#include "common.h"

s32 func_00202230(s32, s32, s32);

s32 func_002021D0(s32 arg0) {
    s32 sum;
    s32 i;

    sum = 0;
    i = 0;
    do {
        sum += func_00202230(arg0, i, 0);
        i++;
    } while (i < 5);
    return sum;
}
