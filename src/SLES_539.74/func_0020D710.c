// range: 0x20D710 0x20D750
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002103D0(s32, s32, M2C_UNK, M2C_UNK);      /* extern */
extern s32 D_003E08D0;

s32 func_0020D710(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if (D_003E08D0 != 0) {
        return func_002103D0(D_003E08D0, arg0, arg1, arg2);
    }
    return 0;
}
