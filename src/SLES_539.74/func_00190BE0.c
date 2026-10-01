// range: 0x190BE0 0x190C10
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0588;
extern s8 D_003E059C;
extern s8 D_003E05A4;
extern s8 D_003E05A8;
extern s8 D_0040FC00 __attribute__((section(".data")));
extern s8 D_0040FC80 __attribute__((section(".data")));
extern s8 D_0040FCC0 __attribute__((section(".data")));

void func_00190BE0(void) {
    D_003E059C = 0;
    D_0040FC00 = 0;
    D_003E05A4 = 0;
    D_0040FC80 = 0;
    D_003E05A8 = 0;
    D_0040FCC0 = 0;
    D_003E0588 = -1;
}
