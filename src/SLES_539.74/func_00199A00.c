// range: 0x199A00 0x199A40
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00199A00(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = M2C_FIELD(arg1, f32 *, 4);
    temp_f0 = M2C_FIELD(arg0, f32 *, 4);
    if (!(temp_f0 <= temp_f1)) {
        return 1;
    }
    var_v0 = 1;
    if (!(temp_f0 < temp_f1)) {
        var_v0 = 0;
    }
    return -(var_v0 & 0xFF);
}
