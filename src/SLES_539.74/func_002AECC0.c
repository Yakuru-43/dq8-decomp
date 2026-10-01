// range: 0x2AECC0 0x2AED10
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014E030(M2C_UNK);                     /* extern */
s32 func_0014E130(M2C_UNK, M2C_UNK);                /* extern */

void func_002AECC0(void *arg0, M2C_UNK arg1) {
    func_0014E030(arg1);
    M2C_FIELD(arg0, s32 *, 0) = func_0014E130(arg1, 0x40);
    func_0014E030(arg1);
    M2C_FIELD(arg0, s32 *, 4) = 0;
}
