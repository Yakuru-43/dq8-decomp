// range: 0x1CD7A0 0x1CD7F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern s32 D_003E06D8;
extern M2C_UNK D_00412C30 __attribute__((section(".data")));
extern M2C_UNK D_00412C70 __attribute__((section(".data")));

s32 func_001CD7A0(void) {
    D_003E06D8 = -1;
    func_00131188(&D_00412C30, 0, 0x40);
    func_00131188(&D_00412C70, 0, 0x40);
    return 1;
}
