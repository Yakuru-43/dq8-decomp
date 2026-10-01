// range: 0x337FF0 0x338060
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_002C17F0();                                /* extern */
s32 func_003084D0(s32, s32);                        /* extern */
M2C_UNK func_00308550(s32, s32, M2C_UNK);           /* extern */

s32 func_00337FF0(s32 arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x45;
    if ((func_002C17F0() == 0) && (func_003084D0(func_001814D0(), temp_s0) != 0)) {
        return 0;
    }
    func_00308550(func_001814D0(), temp_s0, 1);
    return 1;
}
