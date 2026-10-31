// range: 0x465DD0 0x465E80
#include "common.h"

void func_00465E80(s8 *base, s32 idx, s8 value);

void func_00465DD0(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 mode;

    mode = 0;
    if (arg2 & 8) {
        mode = 3;
    }
    if (arg2 & 0x600000) {
        mode = 1;
    }
    if (arg2 & 0x40000) {
        mode = 4;
    }
    if (arg2 & 0x80000) {
        if (arg3 == 2 || arg3 == 0xB || arg3 == 0x11) {
            mode = 5;
        }
    }
    if (arg2 & 0x10) {
        mode = 2;
    }
    func_00465E80(arg0, arg1, mode);
}
