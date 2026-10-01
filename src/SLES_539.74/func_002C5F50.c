// range: 0x2C5F50 0x2C5F60
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E100C;

s32 func_002C5F50(void) {
    return M2C_FIELD(D_003E100C, s8 *, 1) > 0;
}
