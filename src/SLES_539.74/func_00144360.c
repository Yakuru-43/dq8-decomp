// range: 0x144360 0x144370
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00144360(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x270), s32 *, 0x24);
}
