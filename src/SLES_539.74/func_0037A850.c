// range: 0x37A850 0x37A8A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_0037A8A0(s32, M2C_UNK, M2C_UNK, s32);  /* extern */

void func_0037A850(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_0037A8A0(arg0, arg1, arg2, func_002D34C0());
}
