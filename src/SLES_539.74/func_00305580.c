// range: 0x305580 0x3055D0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00167A80();                                /* extern */
M2C_UNK func_00371890(s32, M2C_UNK, f32, f32);      /* extern */

void func_00305580(f32 fparg0, f32 fparg1) {
    func_00371890(func_00167A80(), 2, fparg0, fparg1);
}
