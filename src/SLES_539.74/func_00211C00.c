// range: 0x211C00 0x211C30
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780();                                /* extern */
extern f32 D_003E0930;

s32 func_00211C00(void) {
    D_003E0930 = func_00166780();
    return 1;
}
