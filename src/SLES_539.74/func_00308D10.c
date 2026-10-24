// range: 0x308D10 0x308D78
// auto: hand
#include "common.h"

s32 func_00308D10(s32 *arg0, s32 arg1, s32 arg2) {
    s32 mask;
    s32 bit;
    s32 word;
    s32 old;

    mask = 1;
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = mask << bit;
    old = (mask & arg0[word]) != 0;
    if (arg2) {
        arg0[word] = arg0[word] | mask;
    } else {
        arg0[word] = arg0[word] & ~mask;
    }
    return old;
}
