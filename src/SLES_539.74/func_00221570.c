// range: 0x221570 0x221640
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_002061A0(s32, s32);                        /* extern */
f32 func_00207B70(s32);                             /* extern */
M2C_UNK func_002214E0(s32, s32, f32);               /* extern */
M2C_UNK func_002E6780(s32, s32, M2C_UNK);           /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x54], gap at: 0x8. */
void func_00221570(s32 arg0, s32 arg1, s32 arg2) {
    f32 var_f20;
    s32 temp_v0;

    if ((arg1 >= 0) && (arg1 < 4)) {
        temp_v0 = func_00181420();
        var_f20 = 1.0f;
        if ((temp_v0 != 0) && (func_002061A0(temp_v0, arg1) != 0)) {
            var_f20 = func_00207B70(func_002061A0(temp_v0, arg1));
        }
        func_002214E0(arg0, arg2, var_f20);
    } else {
        func_002E6780(arg0, arg2, 0x80585A5B);
    }
}
