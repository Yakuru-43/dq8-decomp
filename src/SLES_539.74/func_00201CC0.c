// range: 0x201CC0 0x201CD0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00415B20 __attribute__((section(".data")));

M2C_UNK *func_00201CC0(void) {
    return &D_00415B20;
}
