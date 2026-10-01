// range: 0x18E970 0x18E9B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018F090();                                /* extern */

s32 func_0018E970(void) {
    s32 var_s0;

    var_s0 = 0;
    if (func_0018F090() & 3) {
        var_s0 = 1;
    }
    return var_s0;
}
