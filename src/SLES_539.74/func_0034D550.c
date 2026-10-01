// range: 0x34D550 0x34D580
// auto: m2c, verified byte-exact
#include "common.h"

extern s16 D_003E00A0;
extern s32 D_00453BD0 __attribute__((section(".data")));
extern s32 D_00453BD4 __attribute__((section(".data")));
extern s32 D_00453BD8 __attribute__((section(".data")));

void func_0034D550(void) {
    D_00453BD8 = 4;
    D_00453BD4 = 4;
    D_00453BD0 = D_003E00A0 * 0xA;
}
