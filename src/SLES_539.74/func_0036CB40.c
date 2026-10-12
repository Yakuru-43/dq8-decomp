// range: 0x36CB40 0x36CBD0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0035E590(s32);                             /* extern */
M2C_UNK func_00364130(s32, s32, s32);               /* extern */
M2C_UNK func_0036CBD0(s32, s32);                    /* extern */

void func_0036CB40(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_v0;


    if (!(arg2 != 0)) {
        return;
    }

    var_v0 = 0;
    if (arg1 != 0) {
        var_v0 = func_0035E590(arg1);
    }
    func_00364130(arg0, arg2, var_v0);
    if (arg3 != 0) {
        func_0036CBD0(arg2, arg1);
    }
}
