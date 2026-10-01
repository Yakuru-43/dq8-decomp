// range: 0x36F810 0x36F860
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, s32);                    /* extern */
s32 func_0036F860(M2C_UNK);                         /* extern */

s32 func_0036F810(s32 arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = func_0036F860(arg1);
    if ((arg0 != 0) && (temp_v0 != 0)) {
        func_001340C0(arg0, temp_v0);
        return 1;
    }
    return 0;
}
