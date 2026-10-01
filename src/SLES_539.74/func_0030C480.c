// range: 0x30C480 0x30C4C0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00296FD0(s32);                             /* extern */
M2C_UNK func_00356910(s32, s32);                    /* extern */

void func_0030C480(s32 arg0, void *arg1) {
    func_00356910(arg0, func_00296FD0(M2C_FIELD(arg1, s32 *, 0x158)));
}
