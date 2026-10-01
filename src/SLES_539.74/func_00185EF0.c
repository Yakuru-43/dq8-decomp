// range: 0x185EF0 0x185F30
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00376340();                                /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */
f32 func_00185EF0(void) {
    f32 var_f20;

    var_f20 = 1.0f;
    if (func_00376340() != 0) {
        var_f20 = -1.0f;
    }
    return var_f20;
}
