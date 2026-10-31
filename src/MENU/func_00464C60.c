// range: 0x464C60 0x464CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00479100 __attribute__((section(".data")));

s32 func_00464C60(s32 arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x273A, 0, -1);
    func_370C00(func_201CD0(), &D_00479100, 0);
    return 1;
}
