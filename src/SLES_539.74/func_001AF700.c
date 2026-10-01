// range: 0x1AF700 0x1AF710
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_004119B0 __attribute__((section(".data")));

M2C_UNK *func_001AF700(void) {
    return &D_004119B0;
}
