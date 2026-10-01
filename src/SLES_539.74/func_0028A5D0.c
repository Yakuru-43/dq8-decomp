// range: 0x28A5D0 0x28A600
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780();                                /* extern */
extern void *D_003E0E10;

s32 func_0028A5D0(void) {
    M2C_FIELD(D_003E0E10, f32 *, 0x114) = func_00166780();
    return 1;
}
