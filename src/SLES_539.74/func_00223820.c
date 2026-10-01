// range: 0x223820 0x223840
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00223820(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg0 + 4;
    if (arg1 > 0) {
        var_v0 = arg0 + 8;
    }
    return var_v0;
}
