// range: 0x1B3570 0x1B35B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002B9210();                                /* extern */
M2C_UNK func_002B9380(s32, s32);                    /* extern */

s32 func_001B3570(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_002B9210();
    if (temp_v0 != 0) {
        func_002B9380(temp_v0, M2C_FIELD(arg0, s32 *, 4));
        return 1;
    }
    return 0;
}
