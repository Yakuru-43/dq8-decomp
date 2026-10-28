// range: 0x16C660 0x16C6C0
#include "common.h"

extern void func_0016C480(s32, s32);

void func_0016C660(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 0) {
        return;
    }
    if (arg1 < 0) {
        return;
    }
    if (arg1 >= 0xC0) {
        return;
    }
    *(s32 *)((arg1 << 2) + arg0 + 0x3558) = arg2;
    if (arg3 != 0) {
        func_0016C480(arg0, arg2);
    }
}
