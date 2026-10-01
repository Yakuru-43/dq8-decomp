// range: 0x37AE20 0x37AE60
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00201CD0();                                /* extern */
M2C_UNK func_002D34C0();                            /* extern */
M2C_UNK func_00370C00(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_003D54D0 __attribute__((section(".data")));

void func_0037AE20(void) {
    func_002D34C0();
    func_00370C00(func_00201CD0(), &D_003D54D0, 0);
}
