// range: 0x1EED90 0x1EEDB0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DDDE0 __attribute__((section(".data")));

void *func_001EED90(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x68) = &D_003DDDE0;
    return arg0;
}
