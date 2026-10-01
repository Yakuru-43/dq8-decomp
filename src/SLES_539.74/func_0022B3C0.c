// range: 0x22B3C0 0x22B410
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00164100(M2C_UNK *, s32);                  /* extern */
extern s32 D_003E0AE0;
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

s32 func_0022B3C0(s32 arg0) {
    if (D_003E0AE0 & arg0) {
        goto block_1;
    }
    if (func_00164100(&D_003FAFB0, arg0) != 0) {
        return 1;
    }
block_1:
    return 0;
}
