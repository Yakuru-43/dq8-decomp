// range: 0x3245E0 0x324610
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003245E0(void *arg0) {
    void *var_a0;

    var_a0 = M2C_FIELD(arg0, void **, 8);
    if (var_a0 == NULL) {
        var_a0 = NULL;
    }
    if (var_a0 == NULL) {
        return -1;
    }
    M2C_FIELD(var_a0, s32 *, 0x1C) = 1;
    return 0;
}
