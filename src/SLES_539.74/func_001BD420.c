// range: 0x1BD420 0x1BD470
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002BD4C0();                                /* extern */

s32 func_001BD420(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_002BD4C0();
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
