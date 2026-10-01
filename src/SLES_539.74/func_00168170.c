// range: 0x168170 0x168180
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003FB230 __attribute__((section(".data")));

M2C_UNK *func_00168170(void) {
    return &D_003FB230;
}
