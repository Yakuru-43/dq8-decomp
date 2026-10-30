// range: 0x221640 0x221690
#include "common.h"

M2C_UNK func_002214E0(f32, s32, s32);                /* extern */

void func_00221640(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_002214E0(1.0f, arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x14);
}
