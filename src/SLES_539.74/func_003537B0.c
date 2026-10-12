// range: 0x3537B0 0x353800
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00159630(s32, M2C_UNK);                /* extern */
s32 func_0015F450();                                /* extern */
M2C_UNK func_0016A430(s32, M2C_UNK);                /* extern */
M2C_UNK func_00192380();                            /* extern */

void func_003537B0(s32 arg0) {

    if (!(arg0 != 0)) {
        return;
    }

    func_00192380();
    func_00159630(func_0015F450(), 0xA4);
    func_0016A430(arg0, 0x20);
}
