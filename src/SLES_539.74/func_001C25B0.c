// range: 0x1C25B0 0x1C2600
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0020CC10(s32);                           /* extern */
extern s32 D_003E0664;

s32 func_001C25B0(void *arg0) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(func_0020CC10(D_003E0664), f32 *, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), f32 *, 4) = temp_f0;
    }
    return 1;
}
