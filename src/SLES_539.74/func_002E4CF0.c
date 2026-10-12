// range: 0x2E4CF0 0x2E4D20
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001339E0(s32, M2C_UNK *, s32);         /* extern */
extern M2C_UNK D_003CF2D8 __attribute__((section(".data")));

void func_002E4CF0(s32 arg0, s32 arg1) {

    if (!(arg1 != 0)) {
        return;
    }

    func_001339E0(arg1, &D_003CF2D8, arg0);
}
