// range: 0x25E3B0 0x25E430
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0017A770();                       /* extern */
M2C_UNK func_00309BA0();           /* extern */
extern s32 D_003DFEAC;
extern s16 D_003E0C70;
extern s128 D_0041E320 __attribute__((section(".data")));

void func_0025E3B0(s32 arg0, s128 *arg1) {
    s128 temp_a1;
    u32 temp_a0;

    D_003DFEAC = arg0;
    D_003E0C70 = 1;
    temp_a0 = arg0 - 0x3E8;
    temp_a1 = *arg1;
    D_0041E320 = temp_a1;
    if (temp_a0 < 2U) {
        D_003E0C70 = 2;
    } else if (func_0017A770(temp_a0, temp_a1) != 0) {
        func_00309BA0(func_0017A770(), D_003DFEAC, 0);
    }
}
