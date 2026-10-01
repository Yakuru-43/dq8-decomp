// range: 0x19B720 0x19B750
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780();                                /* extern */
extern void *D_003E0600;

s32 func_0019B720(void) {
    M2C_FIELD(D_003E0600, f32 *, 0x244) = func_00166780();
    return 1;
}
