// range: 0x2C18B0 0x2C1910
// auto: m2c, verified byte-exact
#include "common.h"

s32 *func_00182330();                               /* extern */
M2C_UNK func_0022BF20(s32 *, s32);                  /* extern */

s32 func_002C18B0(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = func_00182330();
    if ((temp_v0 != NULL) && (*temp_v0 == 3)) {
        func_0022BF20(temp_v0, arg0);
        return 1;
    }
    return 0;
}
