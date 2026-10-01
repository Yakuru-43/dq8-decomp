// range: 0x338850 0x338890
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00134750(M2C_UNK *, s32, M2C_UNK);     /* extern */
s32 func_00166760();                                /* extern */
extern M2C_UNK D_004534A0 __attribute__((section(".data")));
extern s8 D_004534AB __attribute__((section(".data")));

s32 func_00338850(void) {
    func_00134750(&D_004534A0, func_00166760(), 0xB);
    D_004534AB = 0;
    return 1;
}
