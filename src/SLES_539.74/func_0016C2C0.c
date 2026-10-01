// range: 0x16C2C0 0x16C320
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(char *, s32);                 /* extern */

s32 func_0016C2C0(char *arg0, s32 arg1, s32 arg2) {
    if ((arg2 != 0) && (arg1 != 0)) {
        M2C_FIELD(arg0, s32 *, 0) = 0;
        M2C_FIELD(arg0, s32 *, 0x38) = arg1;
        func_001340C0(arg0 + 8, arg2);
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 4);
        return 0;
    }
    return -1;
}
