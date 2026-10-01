// range: 0x23DCA0 0x23DD00
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014E500(s32, s32);                    /* extern */
extern void *D_003E0B20;
extern void *D_003E0B24;

s32 func_0023DCA0(void) {
    s32 temp_a0;
    s32 temp_a1;

    temp_a1 = M2C_FIELD(D_003E0B24, s32 *, 0x28);
    if (temp_a1 == 0) {
        return 0;
    }
    temp_a0 = M2C_FIELD(D_003E0B20, s32 *, 4);
    if ((temp_a0 != 0) && (temp_a1 != 0)) {
        func_0014E500(temp_a0, temp_a1);
    }
    M2C_FIELD(D_003E0B24, s32 *, 0x28) = 0;
    M2C_FIELD(D_003E0B24, s32 *, 0x2C) = 0;
    return 1;
}
