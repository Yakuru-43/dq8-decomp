// range: 0x2C06D0 0x2C0730
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001339E0(M2C_UNK, M2C_UNK *, s32);     /* extern */
s32 func_002C09E0();                                /* extern */
extern M2C_UNK D_003CD030 __attribute__((section(".data")));

s32 func_002C06D0(s32 arg0, M2C_UNK arg1) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        func_001339E0(arg1, &D_003CD030, func_002C09E0());
        return 1;
    }
    return 0;
}
