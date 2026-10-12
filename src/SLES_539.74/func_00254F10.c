// range: 0x254F10 0x254F40
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014A810(s32, s32);                    /* extern */
extern s32 D_003E0C04;

void func_00254F10(s32 arg0) {

    if (!(D_003E0C04 != 0)) {
        return;
    }

    func_0014A810(D_003E0C04, arg0);
}
