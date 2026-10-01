// range: 0x1C2600 0x1C2650
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0020CC10(s32);                           /* extern */
extern s32 D_003E0664;

s32 func_001C2600(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(func_0020CC10(D_003E0664), s32 *, 0xC);
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_a0;
    }
    return 1;
}
