// range: 0x203DF0 0x203E20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00206B80(s32, M2C_UNK, M2C_UNK);           /* extern */

s32 func_00203DF0(s32 arg0, M2C_UNK arg1) {
    return 0x3E7 - func_00206B80(arg0 + 0x1E0, 4, arg1);
}
