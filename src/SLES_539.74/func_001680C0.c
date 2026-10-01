// range: 0x1680C0 0x1680D0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00401DF0 __attribute__((section(".data")));

M2C_UNK *func_001680C0(void) {
    return &D_00401DF0;
}
