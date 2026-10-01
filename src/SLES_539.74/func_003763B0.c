// range: 0x3763B0 0x3763D0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001813D0();                              /* extern */

s32 func_003763B0(void) {
    return M2C_FIELD(func_001813D0(), s32 *, 0x14);
}
