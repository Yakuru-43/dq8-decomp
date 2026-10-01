// range: 0x18E640 0x18E680
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018F060();                                /* extern */

s32 func_0018E640(void) {
    s32 var_s0;

    var_s0 = 0;
    if (func_0018F060() & 1) {
        var_s0 = 1;
    }
    return var_s0;
}
