// range: 0x188510 0x188520
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00188510(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x5365) == 0;
}
