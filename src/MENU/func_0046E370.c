// range: 0x46E370 0x46E3F0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D5440(s32, M2C_UNK, M2C_UNK *);       /* extern */
M2C_UNK func_2D55E0(s32, M2C_UNK, s32);             /* extern */
s32 func_374B90(s32, M2C_UNK);                      /* extern */
extern M2C_UNK D_00479518 __attribute__((section(".data")));

void func_0046E370(s32 arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_2D34C0();

    if (!(temp_v0 != 0)) {
        return;
    }

    temp_v0_2 = func_374B90(arg0, 1);
    if (temp_v0_2 > 0) {
        func_2D55E0(temp_v0, 0x4B3, temp_v0_2 + 0x5208);
    } else {
        func_2D5440(temp_v0, 0x4B3, &D_00479518);
    }
}
