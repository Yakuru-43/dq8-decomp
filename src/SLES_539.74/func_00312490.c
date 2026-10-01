// range: 0x312490 0x312530
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00201DB0(s32);                             /* extern */
s32 func_002067E0(s32, s32, M2C_UNK);               /* extern */
s32 func_00206C20(s32, s32, M2C_UNK);               /* extern */
s32 func_003134A0(M2C_UNK, s32, s32);               /* extern */

s32 func_00312490(s32 arg0, M2C_UNK arg1) {
    if (func_003134A0(1, arg0, func_00206C20(func_00201DB0(func_00181420()), arg0, arg1)) == 0) {
        goto block_1;
    }
    if (func_002067E0(func_00201DB0(func_00181420()), arg0, arg1) != 0) {
        return 1;
    }
block_1:
    return 0;
}
