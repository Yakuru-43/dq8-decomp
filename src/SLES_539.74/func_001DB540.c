// range: 0x1DB540 0x1DB560
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001DB540(s32 arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = arg1 & 0xFF;
    var_v0 = 1;
    if (temp_v1 != 1) {
        var_v0 = temp_v1 == 0;
    }
    return var_v0;
}
