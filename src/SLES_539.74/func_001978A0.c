// range: 0x1978A0 0x1978B0
// auto: m2c, verified byte-exact
#include "common.h"

extern s16 D_0040FFD6 __attribute__((section(".data")));

void func_001978A0(s16 arg0) {
    D_0040FFD6 = arg0;
}
