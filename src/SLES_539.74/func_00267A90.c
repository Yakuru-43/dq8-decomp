// range: 0x267A90 0x267AF0
#include "common.h"

extern void func_0013B760(char *, char *, f32);

void func_00267A90(s32 *arg0, char *arg1, f32 arg2) {
    f32 f;
    char *temp_s0;

    f = arg2;
    temp_s0 = *(char **)(arg1 + 0xB4) + (arg0[1] << 4);
    func_0013B760(arg1 + 0x20, temp_s0, f);
    func_0013B760(temp_s0, temp_s0 + 0x10, f);
}
