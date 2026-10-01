// range: 0x13BD20 0x13BDA0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern f32 D_003DF478;
extern f32 D_003DF4B4;
extern f32 D_003DF53C;
extern f32 D_003DF540;

s32 func_0013BD20(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 var_f1;
    s32 var_v0;

    var_f1 = fparg0 - fparg1;
    if (var_f1 == 0.0f) {
        return 0;
    }
    if (!(var_f1 <= D_003DF4B4)) {
        var_f1 -= D_003DF478;
    }
    if (var_f1 < D_003DF53C) {
        var_f1 += D_003DF540;
    }
    if (!(var_f1 <= fparg2)) {
        return 1;
    }
    var_v0 = 1;
    if (!(var_f1 < -fparg2)) {
        var_v0 = 0;
    }
    return -(var_v0 & 0xFF);
}
