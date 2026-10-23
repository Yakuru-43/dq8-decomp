// range: 0x307E00 0x307E80
#include "common.h"

void func_00307E00(void *arg0, s32 arg1, s32 arg2) {
    s32 *bitmap;
    s32 mask;
    s32 word;
    s32 bit;

    if (arg1 <= 0 || arg1 >= 0x280) {
        return;
    }
    bitmap = (s32 *)((char *)arg0 + 0x2D0);
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
