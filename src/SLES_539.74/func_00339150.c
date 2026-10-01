// range: 0x339150 0x339190
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00134750(M2C_UNK *, s32, M2C_UNK);     /* extern */
s32 func_00166760();                                /* extern */
extern M2C_UNK D_00453490 __attribute__((section(".data")));
extern s8 D_0045349B __attribute__((section(".data")));

s32 func_00339150(void) {
    func_00134750(&D_00453490, func_00166760(), 0xB);
    D_0045349B = 0;
    return 1;
}
