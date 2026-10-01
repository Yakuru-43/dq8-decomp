// range: 0x2F74E0 0x2F7540
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00167A00();                                /* extern */
f32 func_00305310();                                /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
f32 func_002F74E0(void *arg0) {
    f32 temp_f20;

    if (M2C_FIELD(arg0, u8 *, 0x18C) == 1) {
        return 0.0f;
    }
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x188) * func_00167A00();
    return temp_f20 * func_00305310();
}
