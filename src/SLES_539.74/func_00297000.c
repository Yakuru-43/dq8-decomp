// range: 0x297000 0x297010
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00297000(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x74);
}
