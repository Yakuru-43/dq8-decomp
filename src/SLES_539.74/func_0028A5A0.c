// range: 0x28A5A0 0x28A5D0
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780();                                /* extern */
extern void *D_003E0E10;

s32 func_0028A5A0(void) {
    M2C_FIELD(D_003E0E10, f32 *, 0x11C) = func_00166780();
    return 1;
}
