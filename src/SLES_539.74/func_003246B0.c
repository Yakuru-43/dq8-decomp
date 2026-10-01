// range: 0x3246B0 0x324700
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_003210C0(s32, M2C_UNK);                    /* extern */

s32 func_003246B0(void *arg0) {
    void *var_s0;

    if (M2C_FIELD(arg0, s32 *, 0) <= 0) {
        return -1;
    }
    var_s0 = M2C_FIELD(arg0, void **, 8);
    if (var_s0 == NULL) {
        var_s0 = NULL;
    }
    if (var_s0 == NULL) {
        return -1;
    }
    M2C_FIELD(var_s0, f32 *, 8) = func_003210C0(M2C_FIELD(arg0, s32 *, 4), 0);
    return 0;
}
