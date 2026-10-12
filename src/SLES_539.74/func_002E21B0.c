// range: 0x2E21B0 0x2E2230
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_001340C0(s32, s32);                    /* extern */
u32 func_001341D8(s32);                             /* extern */
M2C_UNK func_002E33E0(M2C_UNK *);                   /* extern */
extern M2C_UNK D_003CE9A0 __attribute__((section(".data")));

void func_002E21B0(s32 arg0, s32 arg1) {

    if (!(arg1 != 0)) {
        return;
    }

    if (func_001341D8(arg1) < 0x80U) {
        func_00131188(arg0, 0, 0x80);
        func_001340C0(arg0, arg1);
        return;
    }
    func_002E33E0(&D_003CE9A0);
}
