// range: 0x304A20 0x304A40
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00304A20(void *arg0) {
    s32 var_v0;

    var_v0 = 3;
    if ((M2C_FIELD(arg0, s32 *, 0x4054) + 0xA) >= 0x64) {
        var_v0 = 4;
    }
    return var_v0;
}
