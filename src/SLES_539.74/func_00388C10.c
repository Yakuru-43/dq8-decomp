// range: 0x388C10 0x388C60
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D48B0(s32, M2C_UNK, f32);           /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void func_00388C10(f32 fparg0) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();
    func_002D48B0(temp_v0, 0x139A, fparg0);
    func_002D48B0(temp_v0, 0x139B, fparg0);
}
