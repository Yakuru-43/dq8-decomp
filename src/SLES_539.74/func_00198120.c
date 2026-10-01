// range: 0x198120 0x1981E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0017AD40(f32);                             /* extern */
s32 func_002BAB80();                                /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */
f32 func_00198120(f32 arg0) {
    f32 var_f12;
    f32 var_f20;

    var_f12 = arg0 - 16000.0f;
    if (var_f12 <= 0.0f) {
        var_f12 = 0.0f;
    }
    var_f20 = 1.0f - (var_f12 / 16000.0f);
    if (!(var_f20 <= 1.0f)) {
        var_f20 = 1.0f;
    }
    if (var_f20 < 0.0f) {
        var_f20 = 0.0f;
    }
    if (func_0017AD40(var_f12) == 2) {
        if (func_002BAB80() == 0) {
            var_f20 = 1.0f;
        }
    }
    return var_f20;
}
