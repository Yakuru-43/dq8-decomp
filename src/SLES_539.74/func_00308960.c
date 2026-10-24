// range: 0x308960 0x3089E0
#include "common.h"

struct Bitmap {
    char pad0[0x340];
    s32 words[0x40];
};

void func_00308960(struct Bitmap *arg0, s32 arg1, s32 arg2) {
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
