// range: 0x3089E0 0x308A50
#include "common.h"

struct Bitmap {
    char pad0[0x240];
    s32 words[0x40];
};

s32 func_003089E0(struct Bitmap *arg0, s32 arg1) {
    s32 mask;
    s32 word;
    s32 bit;
    s32 value;

    if (arg1 < 0 || 0x800 <= arg1) {
        return -1;
    }
    word = arg1 / 32;
    bit = arg1 % 32;
    value = arg0->words[word];
    mask = 1 << bit;
    return (value & mask) != 0;
}
