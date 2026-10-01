// range: 0x18B920 0x18B9A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018AF90(s32, s32, s32, M2C_UNK);          /* extern */

s32 func_0018B920(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
loop_1:
    temp_v0 = func_0018AF90(arg0, arg1, var_s0, arg2);
    if (temp_v0 < 0) {
        return -1;
    }
    if (temp_v0 == var_s0) {
        return arg1;
    }
    var_s0 = temp_v0;
    goto loop_1;
}
