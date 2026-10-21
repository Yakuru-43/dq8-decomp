// range: 0x460AB0 0x460AD0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_3DEFE0 __attribute__((section(".data")));

char *func_00460AB0(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_3DEFE0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    return arg0;
}
