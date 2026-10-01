// range: 0x201CA0 0x201CB0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00415900 __attribute__((section(".data")));

M2C_UNK *func_00201CA0(void) {
    return &D_00415900;
}
