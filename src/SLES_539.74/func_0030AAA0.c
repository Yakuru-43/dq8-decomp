// range: 0x30AAA0 0x30AAE0
// auto: m2c, verified byte-exact
#include "common.h"

s64 func_0030AAE0(s32);                             /* extern */
M2C_UNK func_00356910(s32, s64);                    /* extern */

void func_0030AAA0(s32 arg0, void *arg1) {
    func_00356910(arg0, func_0030AAE0(M2C_FIELD(arg1, s32 *, 0x138)) >> 0x20);
}
