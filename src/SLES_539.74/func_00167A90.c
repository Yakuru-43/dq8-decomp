// range: 0x167A90 0x167AA0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00401EC0 __attribute__((section(".data")));

M2C_UNK *func_00167A90(void) {
    return &D_00401EC0;
}
