// range: 0x33FC80 0x33FCB0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(M2C_UNK *, s32);              /* extern */
s32 func_00166760();                                /* extern */
extern M2C_UNK D_00453840 __attribute__((section(".data")));

s32 func_0033FC80(void) {
    func_001340C0(&D_00453840, func_00166760());
    return 1;
}
