// range: 0x29C720 0x29C740
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DEC80 __attribute__((section(".data")));

void *func_0029C720(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 4) = &D_003DEC80;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    return arg0;
}
