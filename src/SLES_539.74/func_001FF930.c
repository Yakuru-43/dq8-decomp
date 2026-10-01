// range: 0x1FF930 0x1FF980
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001488C0(s32);                         /* extern */
M2C_UNK func_0015DD80(s32);                         /* extern */
M2C_UNK func_0015DDC0(s32, s32);                    /* extern */
s32 func_0015F490();                                /* extern */
M2C_UNK func_001FFA40();                            /* extern */
extern s32 D_003E0834;

void func_001FF930(void) {
    func_001FFA40();
    func_001488C0(func_0015F490());
    func_0015DD80(D_003E0834 + 0x10);
    func_0015DDC0(D_003E0834 + 0x20, D_003E0834 + 0x60);
}
