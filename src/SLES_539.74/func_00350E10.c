// range: 0x350E10 0x350E20
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E1374;

s32 func_00350E10(void) {
    return M2C_FIELD(D_003E1374, s32 *, 0xC);
}
