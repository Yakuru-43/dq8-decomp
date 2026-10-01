// range: 0x1FF830 0x1FF880
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00142C60(s32, s32, M2C_UNK);               /* extern */
M2C_UNK func_001487A0(s32);                         /* extern */
s32 func_0015F490();                                /* extern */
M2C_UNK func_001FF880(s32);                         /* extern */
extern s32 D_003E0838;
extern s32 D_003E0880;

void func_001FF830(void) {
    s32 temp_v0;

    temp_v0 = func_0015F490();
    D_003E0880 = func_00142C60(temp_v0, D_003E0838, 0);
    func_001FF880(D_003E0838);
    func_001487A0(temp_v0);
}
