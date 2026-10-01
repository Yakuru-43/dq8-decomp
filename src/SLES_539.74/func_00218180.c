// range: 0x218180 0x2181D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0021BCC0();                                /* extern */

s32 func_00218180(s32 arg0) {
    s32 var_s0;

    var_s0 = 1;
    if (arg0 < 0x3E8) {
        var_s0 = 7;
    }
    if (func_0021BCC0() == 1) {
        var_s0 = 1;
    }
    return var_s0;
}
