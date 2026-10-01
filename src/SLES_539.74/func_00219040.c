// range: 0x219040 0x2190B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002207B0();                                /* extern */
s32 func_002F60A0(s32);                             /* extern */
extern s32 D_003E0978;
extern s32 D_00415D48 __attribute__((section(".data")));

s32 func_00219040(void *arg0) {
    if (D_003E0978 != 0) {
        goto block_1;
    }
    if ((func_002F60A0(D_00415D48) == 3) && (func_002207B0() != 0)) {
        D_003E0978 = 1;
        M2C_FIELD(arg0, s32 *, 0xC) = 0xA;
        return 1;
    }
block_1:
    return 0;
}
