// range: 0x1CB400 0x1CB450
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00370500();                                /* extern */

s32 func_001CB400(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_00370500();
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
