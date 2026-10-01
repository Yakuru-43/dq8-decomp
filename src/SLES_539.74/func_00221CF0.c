// range: 0x221CF0 0x221D40
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00221D40(s32, s32);                    /* extern */

void func_00221CF0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_00221D40(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x14);
}
