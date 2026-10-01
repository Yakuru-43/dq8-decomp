// range: 0x30AC80 0x30ACC0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0030A720(s32);                             /* extern */
M2C_UNK func_00356910(s32, s32);                    /* extern */

void func_0030AC80(s32 arg0, void *arg1) {
    func_00356910(arg0, func_0030A720(M2C_FIELD(arg1, s32 *, 0x138)));
}
