// range: 0x164010 0x164040
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001645C0(s32, M2C_UNK);                /* extern */
extern s32 D_003E0340;

void func_00164010(void) {

    if (!(D_003E0340 != 0)) {
        return;
    }

    func_001645C0(D_003E0340, 1);
}
