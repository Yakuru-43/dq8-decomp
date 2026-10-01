// range: 0x314310 0x314330
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00314310(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 >= 0;
    if (var_v0 != 0) {
        var_v0 = arg1 < 0x20;
    }
    return var_v0 & 0xFF;
}
