// range: 0x228120 0x228190
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00227DB0(s32, M2C_UNK);                /* extern */
M2C_UNK func_002F5F90(s32, M2C_UNK, s16, M2C_UNK);  /* extern */
extern s32 D_003E0A98;
extern s32 D_003E0A9C;
extern s32 D_00415EF8 __attribute__((section(".data")));
extern s16 D_00415F60 __attribute__((section(".data")));
extern s16 D_00415F62 __attribute__((section(".data")));
extern s16 D_00415F64 __attribute__((section(".data")));
extern s16 D_00415F66 __attribute__((section(".data")));
extern s32 D_00415F68 __attribute__((section(".data")));
extern s32 D_00415F6C __attribute__((section(".data")));

void func_00228120(s16 arg0, s16 arg1) {
    D_00415F60 = arg1;
    D_00415F64 = 0;
    D_00415F62 = arg0;
    D_00415F66 = 0;
    D_00415F68 = D_00415EF8;
    D_00415F6C = D_003E0A9C;
    func_002F5F90(D_003E0A9C, 0, arg0, 0);
    func_00227DB0(D_003E0A98 + 0x5A, 0);
}
