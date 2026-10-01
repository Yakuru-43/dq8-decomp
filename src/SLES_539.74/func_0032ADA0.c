// range: 0x32ADA0 0x32ADF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00337310();                            /* extern */

void *func_0032ADA0(void *arg0, s32 arg1, s32 arg2) {
    func_00337310();
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    return arg0;
}
