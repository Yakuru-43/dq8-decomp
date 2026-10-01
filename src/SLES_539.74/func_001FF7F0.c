// range: 0x1FF7F0 0x1FF830
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00142B90(s32, s32);                    /* extern */
M2C_UNK func_001487A0(s32);                         /* extern */
s32 func_0015F490();                                /* extern */
extern s32 D_003E0880;

void func_001FF7F0(void) {
    s32 temp_v0;

    temp_v0 = func_0015F490();
    func_00142B90(temp_v0, D_003E0880);
    func_001487A0(temp_v0);
}
