// range: 0x2637C0 0x263800
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_0041E538 __attribute__((section(".data")));

void func_002637C0(s32 arg0) {
    if (arg0 == 0) {
        D_0041E538 = 1;
    }
    if (arg0 == 1) {
        D_0041E538 = 0;
    }
}
