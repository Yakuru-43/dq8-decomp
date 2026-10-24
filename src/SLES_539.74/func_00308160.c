// range: 0x308160 0x3081D0
// auto: hand, verified byte-exact
#include "common.h"

s32 func_00308160(void *arg0, s32 arg1) {
    s32 *bitmap;
    s32 mask;
    s32 word;
    s32 bit;

    if (arg1 < 0 || arg1 >= 0x80) {
        return 0;
    }
    bitmap = (s32 *)((char *)arg0 + 0x270);
    mask = 1;
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = mask << bit;
    return (bitmap[word] & mask) != 0;
}
