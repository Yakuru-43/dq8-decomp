// range: 0x352980 0x352990
// auto: m2c draft, verified byte-exact
#include "common.h"

extern s128 D_00453CE0 __attribute__((section(".data")));

void func_00352980(s128 *arg0) {
    D_00453CE0 = *arg0;
}
