// range: 0x308CC0 0x308D10
// auto: hand
#include "common.h"

s32 func_00308CC0(s32 *arg0, s32 arg1) {
    s32 mask;
    s32 bit;
    s32 word;

    mask = 1;
    bit = arg1 % 32;
    mask = mask << bit;
    word = arg1 / 32;
    return (mask & arg0[word]) != 0;
}
