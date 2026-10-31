// range: 0x3087E0 0x308870
#include "common.h"

struct FlagObj {
    char pad0[0x440];
    u32 flags[0x40];
};

void func_003087E0(struct FlagObj *arg0, s32 arg1, s32 arg2) {
    s64 value;
    s32 word;
    s32 bit;
    s64 mask;

    if (arg1 < 0 || arg1 >= 0x800) {
        return;
    }
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = 1 << bit;
    if (arg2) {
        value = arg0->flags[word];
        arg0->flags[word] = (s32)(value | mask);
    } else {
        value = arg0->flags[word];
        arg0->flags[word] = (s32)(value & ~mask);
    }
}
