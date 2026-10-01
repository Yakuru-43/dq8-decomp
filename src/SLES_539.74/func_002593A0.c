// range: 0x2593A0 0x259420
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0013B7B0(s32, s32, M2C_UNK);           /* extern */

void func_002593A0(s32 arg0, M2C_UNK arg1) {
    s32 temp_a0;
    s32 var_s0;

    var_s0 = 0;
    do {
        if (M2C_FIELD((arg0 + (var_s0 * 2)), s16 *, 0x780) > 0) {
            temp_a0 = arg0 + (var_s0 * 0x10);
            func_0013B7B0(temp_a0, temp_a0, arg1);
        }
        var_s0 += 1;
    } while (var_s0 < 0x3C);
}
