// range: 0x1AE130 0x1AE140
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00411A10 __attribute__((section(".data")));

M2C_UNK *func_001AE130(void) {
    return &D_00411A10;
}
