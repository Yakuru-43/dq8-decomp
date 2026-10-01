// range: 0x168150 0x168160
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003FAAA0 __attribute__((section(".data")));

M2C_UNK *func_00168150(void) {
    return &D_003FAAA0;
}
