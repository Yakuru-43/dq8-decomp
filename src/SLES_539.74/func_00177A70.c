// range: 0x177A70 0x177B30
#include "common.h"

M2C_UNK func_0016CFA0(s32, s32, M2C_UNK, M2C_UNK);  /* extern */

void func_00177A70(s32 arg0, M2C_UNK arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    do {
        func_0016CFA0(arg0, var_s0, arg1, 0);
        if (var_s0 < 4) {
            var_s1 = 0;
            do {
                func_0016CFA0(arg0, var_s1 + ((var_s0 * 3) + 8), arg1, 0);
                var_s1 += 1;
            } while (var_s1 < 3);
        }
        var_s0 += 1;
    } while (var_s0 < 4);
}
