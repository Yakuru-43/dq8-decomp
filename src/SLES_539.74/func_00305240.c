// range: 0x305240 0x3052A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002AFF70(M2C_UNK *);                       /* extern */
extern M2C_UNK D_004392A0 __attribute__((section(".data")));

s32 func_00305240(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_002AFF70(&D_004392A0);
    if ((temp_v0 >= 0) && (temp_v0 < 0x200)) {
        return arg0 + (temp_v0 << 5) + 0x40;
    }
    return 0;
}
