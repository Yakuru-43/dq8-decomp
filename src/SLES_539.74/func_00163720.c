// range: 0x163720 0x163770
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00163910(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_003C2618 __attribute__((section(".data")));
extern M2C_UNK D_003C2620 __attribute__((section(".data")));
extern s32 D_003E02D4;
extern s32 D_003E02E8;
extern M2C_UNK D_003F27C0 __attribute__((section(".data")));
extern M2C_UNK D_003F27C8 __attribute__((section(".data")));

void func_00163720(void) {
    D_003E02D4 = 0;
    func_00163910(&D_003F27C0, &D_003C2618);
    func_00163910(&D_003F27C8, &D_003C2620);
    D_003E02E8 = 2;
}
