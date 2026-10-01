// range: 0x185F30 0x185F70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00185F30(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = M2C_FIELD(arg1, f32 *, 0xD8);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0xD8);
    if (!(temp_f0 <= temp_f1)) {
        return 1;
    }
    var_v0 = 1;
    if (!(temp_f0 < temp_f1)) {
        var_v0 = 0;
    }
    return -(var_v0 & 0xFF);
}
