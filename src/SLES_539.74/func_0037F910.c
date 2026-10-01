// range: 0x37F910 0x37F990
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001FFB60(s32, M2C_UNK);                /* extern */
M2C_UNK func_00221770(s32, M2C_UNK, s8);            /* extern */
extern s8 D_003E15AC;
extern s16 D_00415E94 __attribute__((section(".data")));
extern s32 D_00415EB8 __attribute__((section(".data")));

void func_0037F910(void) {
    M2C_UNK var_s0;

    var_s0 = 0x4650;
    if (D_00415E94 == 6) {
        var_s0 = 0x4664;
    }
    if (D_00415E94 == 0xD) {
        var_s0 = 0x467A;
    }
    func_00221770(D_00415EB8, 0, D_003E15AC);
    func_001FFB60(D_00415EB8, var_s0);
    D_00415E94 += 1;
}
