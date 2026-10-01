// range: 0x34D580 0x34D5B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167B20();                                /* extern */
M2C_UNK func_002224E0(s32, s32);                    /* extern */
extern s32 D_00453B90 __attribute__((section(".data")));

void func_0034D580(void) {
    func_002224E0(D_00453B90, func_00167B20());
}
