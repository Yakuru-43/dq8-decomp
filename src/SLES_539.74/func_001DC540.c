// range: 0x1DC540 0x1DC590
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0017AC60();                                /* extern */

s32 func_001DC540(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_0017AC60();
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
