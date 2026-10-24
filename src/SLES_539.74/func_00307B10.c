// range: 0x307B10 0x307BB0
#include "common.h"

extern s32 func_00362650(s32 id);

static inline s32 IsValidFlag(s32 index) {
    if (index < 0 || index >= 0x800) {
        return 0;
    }
    return 1;
}

s32 func_00307B10(void *arg0, s32 arg1) {
    s32 *bitmap;
    s32 index;
    s32 mask;
    s32 bit;
    s32 word;
    s32 result;

    index = func_00362650(arg1);
    if (!IsValidFlag(index)) {
        result = 0;
    } else {
        bitmap = (s32 *)((char *)arg0 + 0x50);
        mask = 1;
        bit = index % 32;
        mask = mask << bit;
        word = bitmap[index / 32];
        result = (word & mask) != 0;
    }
    return result;
}
