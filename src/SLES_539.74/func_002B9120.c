// range: 0x2B9120 0x2B9130
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0F94;
extern s32 D_003E0F98;

void func_002B9120(s32 arg0, s32 arg1) {
    D_003E0F94 = arg0;
    D_003E0F98 = arg1;
}
