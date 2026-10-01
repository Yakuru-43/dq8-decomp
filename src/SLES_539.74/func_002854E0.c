// range: 0x2854E0 0x285510
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern s32 D_00420A7C __attribute__((section(".data")));
extern s32 D_00420A80 __attribute__((section(".data")));

s32 func_002854E0(void) {
    D_00420A7C = 1;
    D_00420A80 = func_001667C0();
    return 1;
}
