// range: 0x1FF770 0x1FF780
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001FF770(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x84);
}
