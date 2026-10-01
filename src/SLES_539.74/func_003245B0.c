// range: 0x3245B0 0x3245E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003245B0(void *arg0) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    if (var_v0 == NULL) {
        var_v0 = NULL;
    }
    if (var_v0 == NULL) {
        return -1;
    }
    M2C_FIELD(var_v0, s32 *, 0x1C) = 0;
    return 0;
}
