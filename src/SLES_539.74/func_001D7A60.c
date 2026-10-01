// range: 0x1D7A60 0x1D7A70
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_004148A4 __attribute__((section(".data")));

void func_001D7A60(s8 arg0) {
    D_004148A4 = arg0;
}
