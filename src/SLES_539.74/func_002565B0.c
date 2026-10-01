// range: 0x2565B0 0x2565C0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003A6FA0 __attribute__((section(".data")));
extern M2C_UNK *D_003DFE50;

void func_002565B0(void) {
    D_003DFE50 = &D_003A6FA0;
}
