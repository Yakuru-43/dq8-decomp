// range: 0x1CDD00 0x1CDD50
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern s32 D_003E06D4;
extern M2C_UNK D_00412BB0 __attribute__((section(".data")));
extern M2C_UNK D_00412BF0 __attribute__((section(".data")));

s32 func_001CDD00(void) {
    D_003E06D4 = -1;
    func_00131188(&D_00412BB0, 0, 0x40);
    func_00131188(&D_00412BF0, 0, 0x40);
    return 1;
}
