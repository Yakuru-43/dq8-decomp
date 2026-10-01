// range: 0x217100 0x217130
// auto: m2c, verified byte-exact
#include "common.h"

void func_00217100(s32 *arg0, s32 *arg1, s32 arg2) {
    *arg0 = 0x190;
    *arg1 = 0x190;
    if (arg2 >= 0x133) {
        *arg0 = 0x14;
    }
}
