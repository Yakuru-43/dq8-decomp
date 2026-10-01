// range: 0x2C0740 0x2C07B0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001339E0(M2C_UNK, M2C_UNK *, s32, M2C_UNK); /* extern */
s32 func_002C09E0();                                /* extern */
extern M2C_UNK D_003CD060 __attribute__((section(".data")));

s32 func_002C0740(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        func_001339E0(arg1, &D_003CD060, func_002C09E0(), arg2);
        return 1;
    }
    return 0;
}
