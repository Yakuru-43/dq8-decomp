// range: 0x2B0270 0x2B02C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014E030(M2C_UNK);                     /* extern */
s32 func_0014E130(M2C_UNK, M2C_UNK);                /* extern */

void func_002B0270(s32 *arg0, M2C_UNK arg1) {
    *arg0 = func_0014E130(arg1, 0x1800);
    func_0014E030(arg1);
}
