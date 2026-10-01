// range: 0x18ACD0 0x18AD30
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00159630(s32, s32);                    /* extern */
s32 func_0015F450();                                /* extern */
M2C_UNK func_001FA840(s32);                         /* extern */

void func_0018ACD0(s32 arg0) {
    s32 temp_s1;
    s32 var_s0;

    temp_s1 = func_0015F450();
    var_s0 = 1;
    do {
        func_00159630(temp_s1, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x3F);
    func_001FA840(arg0 + 0x4190);
}
