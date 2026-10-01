// range: 0x201FE0 0x202020
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00202020();                                /* extern */

s32 func_00201FE0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        return func_00202020() < 1;
    }
    return 0;
}
