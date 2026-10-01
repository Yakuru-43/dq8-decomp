// range: 0x167A80 0x167A90
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00401FE0 __attribute__((section(".data")));

M2C_UNK *func_00167A80(void) {
    return &D_00401FE0;
}
