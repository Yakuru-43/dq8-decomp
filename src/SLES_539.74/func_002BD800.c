// range: 0x2BD800 0x2BD840
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_003E0FF8;

void func_002BD800(s32 arg0) {
    if (arg0 == 0) {
        D_003E0FF8 = 0;
    }
    if (arg0 == 1) {
        D_003E0FF8 = 0;
    }
    if (arg0 == 2) {
        D_003E0FF8 = 1;
    }
}
