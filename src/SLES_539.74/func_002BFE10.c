// range: 0x2BFE10 0x2BFE80
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002BF030();                            /* extern */
M2C_UNK func_002BFB20(s32, M2C_UNK);                /* extern */

s32 func_002BFE10(s32 arg0, M2C_UNK arg1, s32 arg2) {
    if (arg2 == 2) {
        func_002BF030();
    }
    if (arg2 == 0) {
        func_002BFB20(arg0, arg1);
    }
    return 1;
}
