// range: 0x361260 0x361270
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00456E70 __attribute__((section(".data")));

M2C_UNK *func_00361260(void) {
    return &D_00456E70;
}
