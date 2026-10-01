// range: 0x2BED40 0x2BEDB0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002BEDB0(s32, s32, M2C_UNK, s32);      /* extern */
s32 func_002C0180(s32, M2C_UNK);                    /* extern */

void func_002BED40(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        func_002BEDB0(arg0, arg1, arg2, func_002C0180(arg1, 1));
    }
}
