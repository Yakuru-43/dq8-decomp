// range: 0x180F00 0x180F30
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DDB00 __attribute__((section(".data")));
extern M2C_UNK D_003DDB40 __attribute__((section(".data")));

void *func_00180F00(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DDB40;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DDB00;
    return arg0;
}
