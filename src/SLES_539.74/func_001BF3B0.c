// range: 0x1BF3B0 0x1BF400
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002C8E10();                                /* extern */

s32 func_001BF3B0(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_002C8E10();
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
