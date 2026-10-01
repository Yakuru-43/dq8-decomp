// range: 0x3400C0 0x3400F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(M2C_UNK *, s32);              /* extern */
s32 func_00166760();                                /* extern */
extern M2C_UNK D_004537B0 __attribute__((section(".data")));

s32 func_003400C0(void) {
    func_001340C0(&D_004537B0, func_00166760());
    return 1;
}
