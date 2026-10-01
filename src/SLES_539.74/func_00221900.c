// range: 0x221900 0x221950
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002F5F90(s32, s32, M2C_UNK, M2C_UNK);  /* extern */

void func_00221900(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_002F5F90(arg0, var_s0, 0, 0);
        var_s0 += 1;
    } while (var_s0 < 0x10);
}
