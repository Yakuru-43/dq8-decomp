// range: 0x386990 0x3869C0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0015A320(s32, s32);                    /* extern */
s32 func_0015F450();                                /* extern */
extern s32 D_003E15E8;

void func_00386990(void) {
    s32 temp_a0;

    temp_a0 = func_0015F450();

    if (!(D_003E15E8 != 0)) {
        return;
    }

    func_0015A320(temp_a0, D_003E15E8);
}
