// range: 0x376370 0x376390
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001813D0();                              /* extern */

s32 func_00376370(void) {
    return M2C_FIELD(func_001813D0(), s32 *, 4);
}
