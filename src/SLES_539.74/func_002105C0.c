// range: 0x2105C0 0x210600
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00210600();                                /* extern */

s32 func_002105C0(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 == 0) {
        var_v0 = (func_00210600() + 0x1E) << 0xA;
    }
    return var_v0;
}
