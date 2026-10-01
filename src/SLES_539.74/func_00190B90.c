// range: 0x190B90 0x190BB0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0020CC10();                              /* extern */

s32 func_00190B90(void) {
    return M2C_FIELD(func_0020CC10(), s32 *, 0xC);
}
