// range: 0x460A70 0x460A90
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_3DEFE0 __attribute__((section(".data")));

char *func_00460A70(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_3DEFE0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    return arg0;
}
