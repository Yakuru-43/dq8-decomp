// range: 0x2E3480 0x2E3500
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_0014E240(M2C_UNK, s32);                    /* extern */
s32 func_0036F000(M2C_UNK *, s32, s32 *);           /* extern */
extern M2C_UNK D_003CEB80 __attribute__((section(".data")));
extern s32 D_003E10AC;

s32 func_002E3480(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;
    s32 temp_v0;

    if (func_0036F000(&D_003CEB80, arg0, &sp3C) != 0) {
        temp_v0 = func_0014E240(arg1, (sp3C >> 4) + 1);
        D_003E10AC = temp_v0;
        func_00130FD0(temp_v0, arg0, sp3C);
    }
    return sp3C;
}
