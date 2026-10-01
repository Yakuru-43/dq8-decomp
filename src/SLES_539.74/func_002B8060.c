// range: 0x2B8060 0x2B8090
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00361A10(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern s32 D_003E0F94;
extern M2C_UNK D_00439560 __attribute__((section(".data")));
extern M2C_UNK D_004397D0 __attribute__((section(".data")));

void func_002B8060(void) {
    func_00361A10(&D_00439560, &D_004397D0, 0x1500);
    D_003E0F94 = 0;
}
