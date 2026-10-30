// range: 0x2B1DB0 0x2B1E20
#include "common.h"

s32 func_002B11F0(s32, s32);

s32 func_002B1DB0(s32 arg0) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (func_002B11F0(arg0, i) != 0) {
            count++;
        }
        i++;
    } while (i < 12);
    return count;
}
