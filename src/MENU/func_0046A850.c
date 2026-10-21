// range: 0x46A850 0x46A8A0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_37CEE0(M2C_UNK);                       /* extern */
extern M2C_UNK D_00479380 __attribute__((section(".data")));

s32 func_0046A850(void) {
    func_22AB50(0);
    func_37CEE0(0);
    func_370C00(func_201CD0(), &D_00479380, 0);
    return 1;
}
