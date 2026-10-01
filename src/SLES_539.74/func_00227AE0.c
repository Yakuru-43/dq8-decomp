// range: 0x227AE0 0x227B30
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00227C50();                            /* extern */
M2C_UNK func_00373580(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_003738F0(s32, M2C_UNK);                /* extern */

void func_00227AE0(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_003738F0(var_s0, -1);
        var_s0 += 1;
    } while (var_s0 < 4);
    func_00373580(1, 0);
    func_00227C50();
}
