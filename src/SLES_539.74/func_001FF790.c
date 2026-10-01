// range: 0x1FF790 0x1FF7F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00143030(s32, s32);                    /* extern */
M2C_UNK func_00143160(f32, s32);                    /* extern */
M2C_UNK func_00148830(s32);                         /* extern */
M2C_UNK func_001488C0(s32);                         /* extern */
s32 func_0015F490();                                /* extern */
f32 func_001FF5E0(s32);                             /* extern */

void func_001FF790(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_0015F490();
    func_00143160(func_001FF5E0(arg0), temp_s0);
    func_00143030(temp_s0, arg0);
    func_00148830(temp_s0);
    func_001488C0(temp_s0);
}
