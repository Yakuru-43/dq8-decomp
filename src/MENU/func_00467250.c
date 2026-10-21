// range: 0x467250 0x467290
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_004792A0 __attribute__((section(".data")));

s32 func_00467250(void) {
    func_370C00(func_201CD0(), &D_004792A0, 0);
    return 1;
}
