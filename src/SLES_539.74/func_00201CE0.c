// range: 0x201CE0 0x201D10
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_00415BB0 __attribute__((section(".data")));
extern s32 D_00415BB4 __attribute__((section(".data")));
extern s32 D_00415BB8 __attribute__((section(".data")));
extern s8 D_00415BBC __attribute__((section(".data")));

void func_00201CE0(void) {
    D_00415BB0 = 0;
    D_00415BB4 = 0;
    D_00415BB8 = 0;
    D_00415BBC = 0;
}
