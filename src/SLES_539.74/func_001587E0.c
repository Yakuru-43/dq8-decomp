// range: 0x1587E0 0x158870
#include "common.h"

extern s32 func_001FC820(s32, u32);
extern void func_001FC4E0(s32, s32);

void func_001587E0(char *arg0, s32 arg1, u32 arg2) {
    s32 temp_s0;
    char *var_v1;

    if (arg1 == 0x7FFF) {
        var_v1 = arg0 + 0x20;
    } else {
        if ((arg1 >= 0) && (arg1 < *(s32 *)(arg0 + 0xC))) {
            var_v1 = *(char **)(arg0 + 0x1C) + (arg1 << 4);
        } else {
            var_v1 = 0;
        }
    }
    if (var_v1 != 0) {
        temp_s0 = *(s32 *)(var_v1 + 0xC);
        if (temp_s0 != 0) {
            func_001FC4E0(temp_s0, func_001FC820(temp_s0, arg2));
        }
    }
}
