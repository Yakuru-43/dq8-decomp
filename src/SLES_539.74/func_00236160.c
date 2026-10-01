// range: 0x236160 0x236190
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0013FC60(s32);                         /* extern */
s32 func_0015F490();                                /* extern */

void func_00236160(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x208) = 0;
    func_0013FC60(func_0015F490());
}
