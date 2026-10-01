// range: 0x37E700 0x37E750
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00373580(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0037E750(s32);                         /* extern */

void func_0037E700(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_0037E750(var_s0);
        var_s0 += 1;
    } while (var_s0 < 4);
    func_00373580(0, 0);
}
