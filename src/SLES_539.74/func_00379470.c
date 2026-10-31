// range: 0x379470 0x3794B0
#include "common.h"

extern void func_002D38E0(s32, s32, s32, s32);

void func_00379470(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_002D38E0(arg0, 0x2730, 1, -1);
    } else {
        func_002D38E0(arg0, 0x2730, 0, -1);
    }
}
