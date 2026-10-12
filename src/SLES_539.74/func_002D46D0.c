// range: 0x2D46D0 0x2D4740
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_003757C0(s32, f32, f32, f32, f32);     /* extern */

void func_002D46D0(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_003757C0(temp_v0 + 0x30, fparg0, fparg1, fparg2, fparg3);
}
