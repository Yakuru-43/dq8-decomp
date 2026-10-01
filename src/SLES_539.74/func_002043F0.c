// range: 0x2043F0 0x204430
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00308CC0(s32);                             /* extern */

s32 func_002043F0(s32 arg0, s32 arg1) {
    if ((arg1 > 0) && (arg1 < 0x200)) {
        return func_00308CC0(arg0 + 0xA78);
    }
    return 0;
}
