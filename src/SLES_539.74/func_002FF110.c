// range: 0x2FF110 0x2FF1E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_0014E240(M2C_UNK, s32);                    /* extern */
s32 func_0036F000(M2C_UNK *, s32, s32 *);           /* extern */
extern M2C_UNK D_003CFFE0 __attribute__((section(".data")));
extern M2C_UNK D_003D0000 __attribute__((section(".data")));
extern s32 D_003E10C4;
extern s32 D_003E10C8;

s32 func_002FF110(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;
    s32 temp_v0;
    s32 temp_v0_2;

    if (func_0036F000(&D_003CFFE0, arg0, &sp3C) != 0) {
        temp_v0 = func_0014E240(arg1, (sp3C >> 4) + 1);
        D_003E10C4 = temp_v0;
        func_00130FD0(temp_v0, arg0, sp3C);
    }
    if (func_0036F000(&D_003D0000, arg0, &sp3C) != 0) {
        temp_v0_2 = func_0014E240(arg1, (sp3C >> 4) + 1);
        D_003E10C8 = temp_v0_2;
        func_00130FD0(temp_v0_2, arg0, sp3C);
    }
    return sp3C;
}
