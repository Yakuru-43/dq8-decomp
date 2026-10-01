// range: 0x2D4740 0x2D4850
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_002D4850(s32, f32);                    /* extern */
f32 func_002D4860(s32, s32);                        /* extern */
M2C_UNK func_003756E0(s32, M2C_UNK, f32, f32);      /* extern */

void func_002D4740(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 var_f20;
    f32 var_f21;
    s32 temp_s0;

    var_f21 = fparg1;
    var_f20 = fparg2;
    temp_s0 = func_002D4150();
    if (var_f20 == -1.0f) {
        var_f20 = func_002D4860(arg0, arg1);
    }
    if (temp_s0 != 0) {
        if (!(var_f20 < 0.0f)) {
            func_002D4850(temp_s0 + 0x30, var_f20);
        }
        if ((fparg0 < var_f20) && !(var_f21 <= 0.0f)) {
            var_f21 *= -1.0f;
        }
        func_003756E0(temp_s0 + 0x30, 3, fparg0, var_f21);
    }
}
