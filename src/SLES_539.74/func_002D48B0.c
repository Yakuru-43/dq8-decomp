// range: 0x2D48B0 0x2D48F0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_002D4850(f32, s32);                    /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */
void func_002D48B0(f32 arg0) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002D4850(arg0, temp_v0 + 0x30);
}
