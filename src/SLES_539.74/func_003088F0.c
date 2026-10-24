// range: 0x3088F0 0x308960
#include "common.h"

s32 func_003088F0(void *arg0, s32 arg1) {
    s32 *bitmap;
    s32 mask;
    s32 word;
    s32 bit;
    s32 value;

    if (arg1 < 0 || 0x800 <= arg1) {
        return -1;
    }
    bitmap = (s32 *)((char *)arg0 + 0x340);
    word = arg1 / 32;
    bit = arg1 % 32;
    value = bitmap[word];
    mask = 1 << bit;
    return (value & mask) != 0;
}
