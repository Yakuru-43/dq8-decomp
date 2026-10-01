// range: 0x3515C0 0x351690
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
M2C_UNK func_0012EB08(M2C_UNK);                     /* extern */
M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_0014E130(M2C_UNK, u32);                    /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
M2C_UNK func_002A1C70(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK D_003D36F0 __attribute__((section(".data")));
extern M2C_UNK D_003D3710 __attribute__((section(".data")));
extern M2C_UNK D_003D3720 __attribute__((section(".data")));
extern s32 D_003E138C;

void func_003515C0(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;
    s32 temp_v0;
    u32 var_a1;

    D_003E138C = 0;
    if (func_001629F0(&D_003D36F0, arg0, &sp3C) != 0) {
        if (sp3C >= 0x21800) {
            DebugPrintf(&D_003D3720);
            func_0012EB08(1);
        }
        if (!(sp3C & 0xF)) {
            var_a1 = (u32) sp3C >> 4;
        } else {
            var_a1 = ((u32) sp3C >> 4) + 1;
        }
        temp_v0 = func_0014E130(arg1, var_a1);
        D_003E138C = temp_v0;
        func_00130FD0(temp_v0, arg0, sp3C);
    }
    func_002A1C70(arg0, 0, 1, &D_003D3710);
}
