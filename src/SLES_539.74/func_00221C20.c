// range: 0x221C20 0x221C70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002E6740(s32, s32, M2C_UNK);           /* extern */

void func_00221C20(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_002E6740(arg0, var_s0, 0);
        var_s0 += 1;
    } while (var_s0 < 0x14);
}
