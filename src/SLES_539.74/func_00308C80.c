// range: 0x308C80 0x308CB0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00308C80(s64 *arg0, s64 arg1) {
    if ((arg1 >= 0) && (arg1 < 0x18)) {
        *arg0 = (s64) (arg1 << 0x20) >> 0x20;
    }
}
