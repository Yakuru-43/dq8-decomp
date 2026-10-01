// range: 0x203FD0 0x204000
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00201DB0();                                /* extern */
M2C_UNK func_00206AE0(s32, M2C_UNK);                /* extern */

void func_00203FD0(s32 arg0, M2C_UNK arg1) {
    func_00206AE0(func_00201DB0(), arg1);
}
