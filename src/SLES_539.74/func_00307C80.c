// range: 0x307C80 0x307CF0
#include "common.h"

s32 func_00307C80(void *arg0, s32 arg1) {
    s32 *bitmap;
    s32 mask;
    s32 word;
    s32 bit;

    if (arg1 < 0 || 0x80 <= arg1) {
        return 0;
    }
    bitmap = (s32 *)((char *)arg0 + 0x350);
    mask = 1;
    bit = arg1 % 32;
    mask = mask << bit;
    word = arg1 / 32;
    return (mask & bitmap[word]) != 0;
}
