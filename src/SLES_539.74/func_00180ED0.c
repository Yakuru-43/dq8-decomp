// range: 0x180ED0 0x180F00
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DDAE0 __attribute__((section(".data")));
extern M2C_UNK D_003DDB40 __attribute__((section(".data")));

void *func_00180ED0(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DDB40;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DDAE0;
    return arg0;
}
