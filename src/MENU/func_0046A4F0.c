// range: 0x46A4F0 0x46A530
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0046A7A0(M2C_UNK);                     /* extern */
s32 func_201CD0();                                  /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00479360 __attribute__((section(".data")));

s32 func_0046A4F0(void) {
    func_0046A7A0(0);
    func_370C00(func_201CD0(), &D_00479360, 0);
    return 1;
}
