// range: 0x235FB0 0x235FC0
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_00416281 __attribute__((section(".data")));

void func_00235FB0(s8 arg0) {
    D_00416281 = arg0;
}
