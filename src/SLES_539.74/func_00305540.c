// range: 0x305540 0x305580
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167A80();                                /* extern */
M2C_UNK func_00371CC0(f32, s32, M2C_UNK);           /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */
void func_00305540(f32 arg0) {
    func_00371CC0(arg0, func_00167A80(), 2);
}
