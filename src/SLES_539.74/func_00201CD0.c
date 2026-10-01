// range: 0x201CD0 0x201CE0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00415B00 __attribute__((section(".data")));

M2C_UNK *func_00201CD0(void) {
    return &D_00415B00;
}
