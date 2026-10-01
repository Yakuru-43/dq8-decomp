// range: 0x2111A0 0x2112C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_0014E130(M2C_UNK, s32);                    /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
s32 func_0018F5A0(s32);                             /* extern */
extern M2C_UNK D_003C7C40 __attribute__((section(".data")));
extern M2C_UNK D_003C7C60 __attribute__((section(".data")));
extern M2C_UNK D_003C7C80 __attribute__((section(".data")));
extern s32 D_003E0958;
extern s32 D_003E095C;
extern s32 D_003E0960;

void func_002111A0(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    D_003E0960 = 0;
    D_003E0958 = 0;
    D_003E095C = 0;
    if (func_001629F0(&D_003C7C40, arg0, &sp3C) != 0) {
        temp_v0 = func_0014E130(arg1, func_0018F5A0(sp3C));
        D_003E0960 = temp_v0;
        func_00130FD0(temp_v0, arg0, sp3C);
    }
    if (func_001629F0(&D_003C7C60, arg0, &sp3C) != 0) {
        temp_v0_2 = func_0014E130(arg1, func_0018F5A0(sp3C));
        D_003E0958 = temp_v0_2;
        func_00130FD0(temp_v0_2, arg0, sp3C);
    }
    if (func_001629F0(&D_003C7C80, arg0, &sp3C) != 0) {
        temp_v0_3 = func_0014E130(arg1, func_0018F5A0(sp3C));
        D_003E095C = temp_v0_3;
        func_00130FD0(temp_v0_3, arg0, sp3C);
    }
}
