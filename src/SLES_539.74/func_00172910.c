// range: 0x172910 0x172930
// auto: m2c draft, verified byte-exact
#include "common.h"

extern s128 D_00408670 __attribute__((section(".data")));
extern s128 D_00408680 __attribute__((section(".data")));

void func_00172910(s128 *arg0, s128 *arg1) {
    D_00408670 = *arg0;
    D_00408680 = *arg1;
}
