// range: 0x193520 0x193560
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001978C0();                            /* extern */
extern s8 D_003E05BC;
extern s32 D_003E05E8;
extern s8 D_0040FFA2 __attribute__((section(".data")));

void func_00193520(void) {
    D_003E05E8 = 0;
    if (D_003E05BC != 0) {
        D_0040FFA2 = 1;
        func_001978C0();
    }
}
