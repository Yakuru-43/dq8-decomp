// range: 0x30EC50 0x30EC70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0030EC50(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (M2C_FIELD(arg0, f32 *, 0x24) <= M2C_FIELD(arg1, f32 *, 0x24)) {
        var_v0 = 0;
    }
    return var_v0 & 0xFF;
}
