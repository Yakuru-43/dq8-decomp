// range: 0x30B000 0x30B060
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0030AAE0(s32);                             /* extern */
s32 func_0030B060(s32, s32);                        /* extern */
M2C_UNK func_00356910(s32, s32);                    /* extern */

void func_0030B000(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_s0;
    s32 var_a1;

    temp_a0 = M2C_FIELD(arg1, s32 *, 0x128);
    var_a1 = temp_a0 != 0;
    if (var_a1 != 0) {
        temp_s0 = func_0030B060(temp_a0, var_a1);
        var_a1 = (temp_s0 & func_0030AAE0(M2C_FIELD(arg1, s32 *, 0x134))) != 0;
    }
    func_00356910(arg0, var_a1);
}
