// range: 0x1FFBA0 0x1FFBE0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001FFBA0(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    if ((var_a1 < 0) || (var_a1 >= 0x2BA)) {
        var_a1 = 0;
    }
    return M2C_FIELD(arg0, s32 *, 4) + (var_a1 * 0x50);
}
