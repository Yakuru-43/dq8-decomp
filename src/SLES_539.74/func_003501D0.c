// range: 0x3501D0 0x350200
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003501D0(void *arg0) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 4);
    var_v0 = 0;
    if (temp_a0 >= 7) {
        var_v0 = 1;
    }
    if (temp_a0 < -6) {
        var_v0 = 1;
    }
    return var_v0;
}
