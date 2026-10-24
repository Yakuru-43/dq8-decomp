// range: 0x308A50 0x308AD0
#include "common.h"

struct Bitmap {
    char pad0[0x240];
    s32 words[0x40];
};

void func_00308A50(struct Bitmap *arg0, s32 arg1, s32 arg2) {
    s32 word;
    s32 bit;
    s32 mask;

    if (arg1 < 0 || 0x800 <= arg1) {
        return;
    }
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = 1 << bit;
    if (arg2 != 0) {
        arg0->words[word] = arg0->words[word] | mask;
        return;
    }
    arg0->words[word] = arg0->words[word] & ~mask;
}
