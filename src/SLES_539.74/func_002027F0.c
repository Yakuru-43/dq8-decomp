// range: 0x2027F0 0x202840
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00202840(s32, s32);                    /* extern */

void func_002027F0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_00202840(var_s0, arg0);
        var_s0 += 1;
    } while (var_s0 < 4);
}
