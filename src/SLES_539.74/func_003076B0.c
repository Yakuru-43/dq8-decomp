// range: 0x3076B0 0x3076E0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001814D0();                              /* extern */

s32 func_003076B0(void) {
    return (M2C_FIELD(func_001814D0(), s32 *, 0x50) & 0x04000000) != 0;
}
