// range: 0x2A1E50 0x2A1E80
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001813D0();                              /* extern */

s32 func_002A1E50(void) {
    return M2C_FIELD(func_001813D0(), s32 *, 0xC) == 0;
}
