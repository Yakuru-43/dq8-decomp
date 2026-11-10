// range: 0x164470 0x164500
#include "common.h"

void func_00164470(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    u32 bit;
    s32 *words;
    s32 *entry;
    s32 w0;
    u32 inv;

    bit = 1;
    if (arg3 < 2) {
        arg3 = 2;
    }
    if (arg2 < 2) {
        arg2 = 2;
    }
    words = arg0 + 52;
    for (i = 0; i < 32; i++) {
        if (arg1 & bit) {
            w0 = words[0];
            entry = words + i;
            inv = ~bit;
            words[0] = w0 | bit;
            words[1] = words[1] & inv;
            entry[2] = 0;
            entry[34] = arg2;
            entry[66] = arg3;
        }
        bit <<= 1;
    }
}
