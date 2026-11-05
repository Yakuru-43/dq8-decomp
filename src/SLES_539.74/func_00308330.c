// range: 0x308330 0x3083C0
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    /* 0x000 */ u8 pad[0x250];
    /* 0x250 */ u32 words[4];
} Bits0250;

s32 func_00308330(void *arg0, s32 arg1, s32 arg2) {
    Bits0250 *obj;
    u32 mask;
    s32 word;
    s32 bit;
    u32 old;
    s32 result;

    if (arg1 < 0 || arg1 >= 0x80) {
        return 0;
    }
    obj = (Bits0250 *)arg0;
    mask = 1;
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = mask << bit;
    old = obj->words[word];
    result = (mask & old) != 0;
    if (arg2) {
        obj->words[word] |= mask;
    } else {
        obj->words[word] = old & ~mask;
    }
    return result;
}
