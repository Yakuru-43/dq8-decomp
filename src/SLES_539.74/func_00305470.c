// range: 0x305470 0x3054B0
#include "common.h"

extern s8 D_003E1108;

void func_00305470(s32 value, s32 set) {
    if (set) {
        D_003E1108 |= (s8)value;
    } else {
        D_003E1108 &= (s8)~value;
    }
}
