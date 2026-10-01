// range: 0x227840 0x227860
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0020CC10();                              /* extern */

s32 func_00227840(void) {
    return M2C_FIELD(func_0020CC10(), s32 *, 8);
}
