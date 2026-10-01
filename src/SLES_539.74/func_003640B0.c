// range: 0x3640B0 0x364100
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0036F6A0(s32);                             /* extern */

s32 func_003640B0(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 >= 0xBB8) {
        var_a0 = var_a0 % 3000;
    }
    if ((var_a0 >= 0) && (var_a0 < 0x2BA)) {
        return func_0036F6A0(var_a0);
    }
    return 0;
}
