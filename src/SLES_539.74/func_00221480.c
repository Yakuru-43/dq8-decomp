// range: 0x221480 0x2214E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002214E0(s32, s32, f32);               /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
void func_00221480(s32 arg0, f32 fparg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_002214E0(arg0, var_s0, fparg0);
        var_s0 += 1;
    } while (var_s0 < 0x14);
}
