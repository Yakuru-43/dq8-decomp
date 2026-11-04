// range: 0x34AAB0 0x34ACA0
// flags: -flag divbyzerocheck
#include "common.h"

void func_0022B020();

void func_0034AAB0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9,
                   s32 arg10) {
    s32 twice = arg8 << 1;
    s32 total = (arg2 + arg4) - arg8;
    s32 cursor = arg2 + arg8;
    s32 n = arg4 - twice;
    s32 temp;
    s32 count;
    s32 rest;
    s32 i;

    if (n <= 0) {
        cursor = 0;
        n = 0;
    }
    func_0022B020(arg0, arg1, arg2, arg3, arg8, arg5, arg6, arg7, arg8, arg9,
                  arg10, 128);
    count = n / arg8;
    temp = arg6 + arg8;
    for (i = 0; i < count; i++) {
        func_0022B020(arg0, arg1, cursor, arg3, arg8, arg5, temp, arg7, arg8,
                      arg9, arg10, 128);
        cursor += arg8;
    }
    rest = total - cursor;
    if (0 < rest) {
        func_0022B020(arg0, arg1, cursor, arg3, rest, arg5, temp, arg7, arg8,
                      arg9, arg10, 128);
    }
    func_0022B020(arg0, arg1, total, arg3, arg8, arg5, arg6 + twice, arg7,
                  arg8, arg9, arg10, 128);
}
