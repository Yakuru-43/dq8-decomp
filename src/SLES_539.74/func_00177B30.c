// range: 0x177B30 0x177BD0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0016CFA0();  /* extern */

void func_00177B30(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 var_s0;

    func_0016CFA0();
    if (arg1 < 4) {
        var_s0 = 0;
        do {
            func_0016CFA0(arg0, var_s0 + ((arg1 * 3) + 8), arg2, arg3);
            var_s0 += 1;
        } while (var_s0 < 3);
    }
}
