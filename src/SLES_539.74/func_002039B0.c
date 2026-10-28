// range: 0x2039B0 0x203A30
#include "common.h"

s32 func_00203A30(s32, s32, s32);

s32 func_002039B0(s32 arg0, s32 arg1) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (func_00203A30(arg0, i, arg1) != 0) {
            count++;
        }
        i++;
    } while (i < 4);
    return count;
}
