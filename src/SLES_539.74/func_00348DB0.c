// range: 0x348DB0 0x348EB0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, u32);               /* extern */
s32 func_0014E130(s32, u32);                        /* extern */
s32 func_001629F0(M2C_UNK *, s32, u32 *);           /* extern */
M2C_UNK func_00163E10(M2C_UNK *);                   /* extern */
extern M2C_UNK D_003D33C0 __attribute__((section(".data")));
extern M2C_UNK D_003D33D0 __attribute__((section(".data")));
extern M2C_UNK D_003D33E0 __attribute__((section(".data")));
extern s32 D_003E1348;
extern s32 D_003E134C;

void func_00348DB0(s32 arg0, s32 arg1) {
    u32 sp3C;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 var_a1;
    u32 var_a1_2;

    D_003E134C = 0;
    D_003E1348 = 0;
    if ((arg0 != 0) && (arg1 != 0)) {
        func_00163E10(&D_003D33C0);
        if (func_001629F0(&D_003D33D0, arg0, &sp3C) != 0) {
            if (!(sp3C & 0xF)) {
                var_a1 = sp3C >> 4;
            } else {
                var_a1 = (sp3C >> 4) + 1;
            }
            temp_v0 = func_0014E130(arg1, var_a1);
            D_003E134C = temp_v0;
            func_00130FD0(temp_v0, arg0, sp3C);
        }
        if (func_001629F0(&D_003D33E0, arg0, &sp3C) != 0) {
            if (!(sp3C & 0xF)) {
                var_a1_2 = sp3C >> 4;
            } else {
                var_a1_2 = (sp3C >> 4) + 1;
            }
            temp_v0_2 = func_0014E130(arg1, var_a1_2);
            D_003E1348 = temp_v0_2;
            func_00130FD0(temp_v0_2, arg0, sp3C);
        }
        func_00163E10(NULL);
    }
}
