// range: 0x1EE440 0x1EE470
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00166700(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_00414F40 __attribute__((section(".data")));

s32 func_001EE440(s32 arg0) {
    func_00166700(&D_00414F40, arg0);
    return 1;
}
