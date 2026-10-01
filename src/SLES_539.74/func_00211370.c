// range: 0x211370 0x2113F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00211370(void *arg0, void *arg1, void *arg2) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 var_v0;

    temp_f3 = M2C_FIELD(arg0, f32 *, 0);
    if (temp_f3 < M2C_FIELD(arg1, f32 *, 0)) {
        return 0;
    }
    temp_f2 = M2C_FIELD(arg0, f32 *, 4);
    if (temp_f2 < M2C_FIELD(arg1, f32 *, 4)) {
        return 0;
    }
    temp_f1 = M2C_FIELD(arg0, f32 *, 8);
    if (temp_f1 < M2C_FIELD(arg1, f32 *, 8)) {
        return 0;
    }
    if (M2C_FIELD(arg2, f32 *, 0) < temp_f3) {
        return 0;
    }
    if (M2C_FIELD(arg2, f32 *, 4) < temp_f2) {
        return 0;
    }
    var_v0 = 1;
    if (!(M2C_FIELD(arg2, f32 *, 8) < temp_f1)) {
        var_v0 = 0;
    }
    return (var_v0 ^ 1) & 0xFF;
}
