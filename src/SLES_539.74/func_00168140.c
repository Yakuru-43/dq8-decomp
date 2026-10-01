// range: 0x168140 0x168150
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

M2C_UNK *func_00168140(void) {
    return &D_003FAFB0;
}
