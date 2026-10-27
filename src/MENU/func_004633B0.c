// range: 0x4633B0 0x4633F0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_37EB00(M2C_UNK);                       /* extern */
extern M2C_UNK D_00478F18 __attribute__((section(".data")));

s32 func_004633B0(void) {
    func_37EB00(0);
    func_370C00(func_201CD0(), &D_00478F18, 0);
    return 1;
}
