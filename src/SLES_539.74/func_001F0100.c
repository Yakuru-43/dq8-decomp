// range: 0x1F0100 0x1F0190
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_001F0190();                                /* extern */
extern f32 D_003DFCDC;
extern f32 D_003DFCE0;
extern f32 D_003DFCE4;
extern f32 D_003DFCE8;

s32 func_001F0100(void) {
    f32 temp_f0;
    s32 var_v0;

    temp_f0 = func_001F0190();
    var_v0 = 2;
    if (!(temp_f0 < D_003DFCDC) && (temp_f0 < D_003DFCE0)) {
        var_v0 = 3;
    }
    if (!(temp_f0 < D_003DFCE0) && (temp_f0 < D_003DFCE4)) {
        var_v0 = 0;
    }
    if (!(temp_f0 < D_003DFCE4) && (temp_f0 < D_003DFCE8)) {
        var_v0 = 1;
    }
    return var_v0;
}
