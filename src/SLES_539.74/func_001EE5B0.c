// range: 0x1EE5B0 0x1EE5E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001EF010(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_00414F80 __attribute__((section(".data")));

s32 func_001EE5B0(s32 arg0, M2C_UNK arg1) {
    func_001EF010(&D_00414F80, arg0, arg1);
    return 1;
}
