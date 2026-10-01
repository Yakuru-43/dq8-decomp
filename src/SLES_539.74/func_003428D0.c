// range: 0x3428D0 0x342910
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_0042CDB4 __attribute__((section(".data")));

s32 func_003428D0(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if ((var_a0 < 0) || (var_a0 >= 0x2BA)) {
        var_a0 = 0;
    }
    return D_0042CDB4 + (var_a0 * 0x50);
}
