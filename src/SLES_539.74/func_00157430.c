// range: 0x157430 0x157480
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013B720();                /* extern */

void func_00157430(char *arg0, s32 arg1, s128 *arg2, M2C_UNK arg3) {
    func_0013B720();
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) *arg2;
    func_0013B720(arg0 + 0x20, arg3);
}
