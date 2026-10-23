// range: 0x3054B0 0x305520
#include "common.h"

extern void func_00267420(s32);

void func_003054B0(char *arg0, s32 arg1, s32 arg2) {
    if (arg2) {
        M2C_FIELD(arg0, s32 *, 0x40) |= 1 << arg1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x40) &= ~(1 << arg1);
    }
    if (arg1 == 7) {
        func_00267420(arg2);
    }
}
