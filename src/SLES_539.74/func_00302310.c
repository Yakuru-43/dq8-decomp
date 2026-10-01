// range: 0x302310 0x302360
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00302310(void *arg0) {
    s32 var_v0;

    if ((M2C_FIELD(arg0, s32 *, 4) != 0) && (M2C_FIELD(arg0, s32 *, 0x10) != 0)) {
        var_v0 = 1;
        if (!(M2C_FIELD(arg0, f32 *, 0x24) <= 0.0f)) {
            return 0;
        }
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = 0;
    return var_v0;
}
