// range: 0x3045A0 0x304600
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_00191EB0(s32);                             /* extern */
M2C_UNK func_00304600(s32, s32);                    /* extern */
s32 func_00308870(s32, M2C_UNK);                    /* extern */

void func_003045A0(void) {
    s32 temp_s0;

    temp_s0 = func_00308870(func_00191EB0(func_001814D0()), 0x15);
    func_00304600(temp_s0, func_00308870(func_00191EB0(func_001814D0()), 0x16));
}
