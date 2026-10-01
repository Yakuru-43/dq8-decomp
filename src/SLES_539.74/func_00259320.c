// range: 0x259320 0x2593A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_00308B50(s32, M2C_UNK);                    /* extern */
s32 func_00308C70(s32);                             /* extern */

s32 func_00259320(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0 != 0) {
        goto block_1;
    }
    temp_s0 = func_00308C70(func_001814D0() + 0x470);
    temp_v0 = func_00308B50(func_001814D0() + 0x470, 6);
    if ((temp_s0 <= 0) || (temp_s0 >= 7) || ((temp_s0 == 6) && (temp_v0 >= 6))) {
        return 1;
    }
block_1:
    return 0;
}
