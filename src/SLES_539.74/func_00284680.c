// range: 0x284680 0x2846C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0015F450();                            /* extern */
extern s32 D_004209E0 __attribute__((section(".data")));

s32 func_00284680(void) {
    if (D_004209E0 == 0) {
        return 0;
    }
    func_0015F450();
    return 1;
}
