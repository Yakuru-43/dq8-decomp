// range: 0x206080 0x2060B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00206080(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = M2C_FIELD(arg0, u16 *, 0x14) & (1 << arg1);
    if (var_v0 != 0) {
        var_v0 = 1;
    }
    return var_v0;
}
