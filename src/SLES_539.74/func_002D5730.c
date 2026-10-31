// range: 0x2D5730 0x2D5790
// auto: m2c draft, verified byte-exact
#include "common.h"

u32 func_002D7830(s32, s32, s32);
M2C_UNK DebugPrintf(M2C_UNK *, s32);                /* extern */
extern M2C_UNK D_003CD8D0 __attribute__((section(".data")));

s32 func_002D5730(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_v0;

    temp_v0 = func_002D7830(arg0, arg1, 0);
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        return 1;
    }
    DebugPrintf(&D_003CD8D0, arg1);
    return 0;
}
