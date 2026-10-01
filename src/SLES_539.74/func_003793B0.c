// range: 0x3793B0 0x379430
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_002D5410(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_003763F0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_00376410(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern s32 D_003E1530;
extern s8 D_003E157C;
extern M2C_UNK D_00458BB0 __attribute__((section(".data")));

s32 func_003793B0(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    func_002D38E0(arg1, 0x2745, 1, -1);
    temp_v0 = func_002D5410(arg1, 0x2746);
    func_003763F0(&D_00458BB0, temp_v0);
    func_00376410(&D_00458BB0, temp_v0, 0);
    D_003E1530 = arg3;
    D_003E157C = 0;
    return 1;
}
