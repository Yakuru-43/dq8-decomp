// range: 0x3081D0 0x308250
// auto: hand, verified byte-exact
#include "common.h"

void func_003081D0(void *arg0, s32 arg1, s32 arg2) {
    s32 *bitmap;
    s32 mask;
    s32 word;
    s32 bit;

    if (arg1 < 0 || arg1 >= 0x80) {
        return;
    }
    bitmap = (s32 *)((char *)arg0 + 0x270);
    mask = 1;
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = mask << bit;
    if (arg2) {
        bitmap[word] |= mask;
    } else {
        bitmap[word] &= ~mask;
    }
}
