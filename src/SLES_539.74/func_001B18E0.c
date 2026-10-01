// range: 0x1B18E0 0x1B18F0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00410FA0 __attribute__((section(".data")));

M2C_UNK *func_001B18E0(void) {
    return &D_00410FA0;
}
