// range: 0x16FB80 0x16FBA0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0016FB80(void *arg0) {
    s32 var_v0;

    var_v0 = M2C_FIELD(arg0, s32 *, 0x218) != 0;
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg0, s8 *, 0x220) > 0;
    }
    return var_v0 & 0xFF;
}
