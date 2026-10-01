// range: 0x1BD1E0 0x1BD230
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0017ACB0(M2C_UNK);                         /* extern */

s32 func_001BD1E0(void *arg0) {
    s32 temp_a0;

    temp_a0 = func_0017ACB0(1) & 0xFF;
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_a0;
    }
    return 1;
}
