// range: 0x211BB0 0x211C00
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_0013BCA0(f32);                             /* extern */
f32 func_00166780();                                /* extern */
extern f32 D_003DF4B4;
extern f32 D_003E0934;

s32 func_00211BB0(void) {
    D_003E0934 = func_0013BCA0(D_003DF4B4 * (func_00166780() / 180.0f));
    return 1;
}
