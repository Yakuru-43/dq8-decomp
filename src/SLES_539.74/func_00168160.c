// range: 0x168160 0x168170
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003FB290 __attribute__((section(".data")));

M2C_UNK *func_00168160(void) {
    return &D_003FB290;
}
