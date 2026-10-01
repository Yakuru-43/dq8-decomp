// range: 0x223890 0x223AD0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_0014E130(s32, s32);                        /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
M2C_UNK func_00163E10(M2C_UNK *);                   /* extern */
extern M2C_UNK D_003C82B0 __attribute__((section(".data")));
extern M2C_UNK D_003C82C0 __attribute__((section(".data")));
extern M2C_UNK D_003C82D0 __attribute__((section(".data")));
extern M2C_UNK D_003C82E0 __attribute__((section(".data")));
extern M2C_UNK D_003C82F0 __attribute__((section(".data")));
extern M2C_UNK D_003C8300 __attribute__((section(".data")));
extern M2C_UNK D_003C8310 __attribute__((section(".data")));
extern s32 D_003E0A0C;
extern s32 D_003E0A10;
extern s32 D_003E0A14;
extern s32 D_003E0A18;
extern s32 D_003E0A1C;
extern s32 D_003E0A20;

void func_00223890(s32 arg0, s32 arg1) {
    s32 sp4C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;

    if ((arg0 != 0) && (arg1 != 0)) {
        func_00163E10(&D_003C82B0);
        if (func_001629F0(&D_003C82C0, arg0, &sp4C) != 0) {
            temp_v0 = func_0014E130(arg1, (sp4C >> 4) + 1);
            if (temp_v0 != 0) {
                func_00130FD0(temp_v0, arg0, sp4C);
                D_003E0A0C = temp_v0;
            }
        }
        if (func_001629F0(&D_003C82D0, arg0, &sp4C) != 0) {
            temp_v0_2 = func_0014E130(arg1, (sp4C >> 4) + 1);
            if (temp_v0_2 != 0) {
                func_00130FD0(temp_v0_2, arg0, sp4C);
                D_003E0A10 = temp_v0_2;
            }
        }
        if (func_001629F0(&D_003C82E0, arg0, &sp4C) != 0) {
            temp_v0_3 = func_0014E130(arg1, (sp4C >> 4) + 1);
            if (temp_v0_3 != 0) {
                func_00130FD0(temp_v0_3, arg0, sp4C);
                D_003E0A14 = temp_v0_3;
            }
        }
        if (func_001629F0(&D_003C82F0, arg0, &sp4C) != 0) {
            temp_v0_4 = func_0014E130(arg1, (sp4C >> 4) + 1);
            if (temp_v0_4 != 0) {
                func_00130FD0(temp_v0_4, arg0, sp4C);
                D_003E0A18 = temp_v0_4;
            }
        }
        if (func_001629F0(&D_003C8300, arg0, &sp4C) != 0) {
            temp_v0_5 = func_0014E130(arg1, (sp4C >> 4) + 1);
            if (temp_v0_5 != 0) {
                func_00130FD0(temp_v0_5, arg0, sp4C);
                D_003E0A1C = temp_v0_5;
            }
        }
        if (func_001629F0(&D_003C8310, arg0, &sp4C) != 0) {
            temp_v0_6 = func_0014E130(arg1, (sp4C >> 4) + 1);
            if (temp_v0_6 != 0) {
                func_00130FD0(temp_v0_6, arg0, sp4C);
                D_003E0A20 = temp_v0_6;
            }
        }
        func_00163E10(NULL);
    }
}
