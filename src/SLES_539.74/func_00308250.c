// range: 0x308250 0x308330
#include "common.h"

static inline s32 TestBit(s32 *bitmap, s32 arg1) {
    s32 mask;
    s32 word;
    s32 bit;

    if (arg1 < 0 || arg1 >= 0x80) {
        return 0;
    }
    mask = 1;
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = mask << bit;
    return (bitmap[word] & mask) != 0;
}

u8 func_00308250(void *arg0, s32 arg1) {
    return TestBit((s32 *)((char *)arg0 + 0x250), arg1) &&
           TestBit((s32 *)((char *)arg0 + 0x260), arg1) == 0;
}
