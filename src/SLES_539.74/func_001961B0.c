// range: 0x1961B0 0x196220
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0012D528();                    /* extern */
M2C_UNK func_00196220();           /* extern */

void func_001961B0(s32 arg0, s8 *arg1) {
    s32 var_a1;

    var_a1 = 0;
    if (arg1 != NULL) {
        var_a1 = ((*arg1 - 0x60) * 0x64) + func_0012D528(arg1 + 2, 0);
    }
    func_00196220(arg0, var_a1, -1);
}
