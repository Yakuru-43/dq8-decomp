// range: 0x194700 0x194720
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_003E05C8;
extern s32 D_003E05CC;
extern s8 D_003E05D0;
extern s8 D_00410470 __attribute__((section(".data")));

void func_00194700(void) {
    D_003E05C8 = 0;
    D_00410470 = 0;
    D_003E05CC = 0;
    D_003E05D0 = -1;
}
