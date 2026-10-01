// range: 0x37CCA0 0x37CD20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002020F0(s32);                             /* extern */
M2C_UNK func_0037CD20(s32, M2C_UNK);                /* extern */

void func_0037CCA0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if ((func_002020F0(var_s0) != 0) && (arg0 != 0)) {
            func_0037CD20(var_s0, 1);
        } else {
            func_0037CD20(var_s0, 0);
        }
        var_s0 += 1;
    } while (var_s0 < 4);
}
