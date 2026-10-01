// range: 0x2219A0 0x2219F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002F5FE0(s32, s32, M2C_UNK);           /* extern */

void func_002219A0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_002F5FE0(arg0, var_s0, -1);
        var_s0 += 1;
    } while (var_s0 < 0x10);
}
