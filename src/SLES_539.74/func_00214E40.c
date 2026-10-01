// range: 0x214E40 0x214E80
// auto: m2c, verified byte-exact
#include "common.h"

void func_00214E40(s32 *arg0, s32 arg1) {
    *arg0 += arg1;
    if (*arg0 < 0) {
        *arg0 = 0;
    }
    if (*arg0 >= 0x81) {
        *arg0 = 0x80;
    }
}
