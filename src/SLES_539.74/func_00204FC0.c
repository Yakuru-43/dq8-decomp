// range: 0x204FC0 0x205010
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00205010(s32, M2C_UNK);                    /* extern */
s32 func_00205040();                                /* extern */

s32 func_00204FC0(s32 arg0, M2C_UNK arg1) {
    s32 temp_s0;

    temp_s0 = func_00205040();
    return temp_s0 - func_00205010(arg0, arg1);
}
