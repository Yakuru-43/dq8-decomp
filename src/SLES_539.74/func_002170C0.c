// range: 0x2170C0 0x217100
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0014E8A0(s32);                         /* extern */

s32 func_002170C0(s32 arg0) {
    func_0014E8A0(arg0 + 0x490);
    func_00131188(arg0, 0, 0x6E0);
    return arg0;
}
