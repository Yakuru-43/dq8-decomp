// range: 0x3080E0 0x308160
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x50];
    s32 bits[4];
} S_flags;

void func_003080E0(void *arg0, s32 arg1, s32 arg2) {
    S_flags *flags;
    s32 mask;
    s32 word;
    s32 bit;

    if (arg1 < 0 || arg1 >= 0x80) {
        return;
    }
    flags = (S_flags *)((char *)arg0 + 0x270);
    mask = 1;
    word = arg1 / 32;
    bit = arg1 % 32;
    mask = mask << bit;
    if (arg2) {
        flags->bits[word] |= mask;
    } else {
        flags->bits[word] &= ~mask;
    }
}
