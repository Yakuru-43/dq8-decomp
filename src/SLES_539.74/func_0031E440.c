// range: 0x31E440 0x31E470
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0031E440(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x58);
    if ((temp_v1 != 1) && (temp_v1 != 2)) {
        return M2C_FIELD(arg0, s32 *, 4);
    }
    return M2C_FIELD(arg0, s32 *, 0);
}
