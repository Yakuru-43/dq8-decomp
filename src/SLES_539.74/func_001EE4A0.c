// range: 0x1EE4A0 0x1EE4F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00166700(M2C_UNK *, s32);              /* extern */
extern s32 D_003E0778;
extern M2C_UNK D_00414F60 __attribute__((section(".data")));
extern M2C_UNK D_00414F70 __attribute__((section(".data")));

s32 func_001EE4A0(s32 arg0) {
    D_003E0778 = 1;
    func_00166700(&D_00414F60, arg0);
    func_00166700(&D_00414F70, arg0 + 0x18);
    return 1;
}
