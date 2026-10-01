// range: 0x307780 0x3077A0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001814D0();                              /* extern */

s16 func_00307780(void) {
    return M2C_FIELD(func_001814D0(), s16 *, 0x15E);
}
