// range: 0x1EB230 0x1EB260
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780();                                /* extern */
extern void *D_003E0748;

s32 func_001EB230(void) {
    M2C_FIELD(D_003E0748, f32 *, 0x168) = func_00166780();
    return 1;
}
