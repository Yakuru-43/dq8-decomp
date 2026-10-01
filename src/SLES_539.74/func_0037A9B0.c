// range: 0x37A9B0 0x37AA00
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_0037AA00(s32, M2C_UNK, M2C_UNK, s32);  /* extern */

void func_0037A9B0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_0037AA00(arg0, arg1, arg2, func_002D34C0());
}
