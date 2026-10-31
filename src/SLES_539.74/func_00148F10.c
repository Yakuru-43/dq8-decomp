// range: 0x148F10 0x148F80
#include "common.h"

extern char *func_001428D0(s32, s32);
extern void func_0014E130(char *, s32);

s32 func_00148F10(s32 arg0, s32 arg1) {
    char *temp_v0;
    s32 temp_v1;
    s32 var_s0;

    temp_v0 = func_001428D0(arg0, arg1);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_v1 = arg1 - (*(s32 *)(temp_v0 + 0x28) + (*(s32 *)(temp_v0 + 0x2C) << 4));
    var_s0 = temp_v1 / 16;
    if (var_s0 > 0) {
        func_0014E130(temp_v0, var_s0);
    }
    return var_s0;
}
