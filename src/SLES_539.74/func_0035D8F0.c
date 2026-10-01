// range: 0x35D8F0 0x35D920
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_0035D8F0(void *arg0) {
    f32 var_f0;

    var_f0 = 0.0f;
    if (M2C_FIELD(arg0, s32 *, 0x9C) & 1) {
        var_f0 = 0.03125f;
    }
    return var_f0;
}
