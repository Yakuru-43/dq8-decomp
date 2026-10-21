// range: 0x476B00 0x476B20
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_3DF1E0 __attribute__((section(".data")));

char *func_00476B00(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_3DF1E0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    return arg0;
}
