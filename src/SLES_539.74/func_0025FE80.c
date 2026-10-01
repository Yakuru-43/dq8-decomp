// range: 0x25FE80 0x25FEC0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0017AD40();                                /* extern */

s32 func_0025FE80(void) {
    s32 var_s0;

    var_s0 = 0;
    if (func_0017AD40() == 2) {
        var_s0 = 1;
    }
    return var_s0;
}
