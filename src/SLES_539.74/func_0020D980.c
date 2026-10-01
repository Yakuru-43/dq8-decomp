// range: 0x20D980 0x20D9D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0014EB30(M2C_UNK);                         /* extern */
M2C_UNK func_002106E0(s32);                         /* extern */
s32 func_00210910(s32);                             /* extern */
extern s32 D_003E08D0;

void func_0020D980(s32 arg0, s32 arg1) {
    s32 var_v0;

    D_003E08D0 = 0;
    if ((arg0 != 0) && (arg1 != 0)) {
        var_v0 = func_0014EB30(0x7800);
        if (var_v0 != 0) {
            var_v0 = func_00210910(var_v0);
        }
        D_003E08D0 = var_v0;
        func_002106E0(var_v0);
    }
}
