// range: 0x267AF0 0x267B50
#include "common.h"

extern void func_0013B760(char *, char *, f32);

void func_00267AF0(char *arg0, char *arg1, f32 arg2) {
    char *s0;

    s0 = *(char **)(arg1 + 0xB4) + (*(s32 *)(arg0 + 4) << 4);
    func_0013B760(arg1 + 0x10, s0, arg2);
    func_0013B760(s0, s0 + 0x10, arg2);
}
