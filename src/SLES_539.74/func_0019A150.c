// range: 0x19A150 0x19A1A0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0012D528();                             /* extern */

s32 func_0019A150(s8 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = ((*arg0 - 0x60) * 0x64) + func_0012D528(arg0 + 2);
    }
    return var_v0;
}
