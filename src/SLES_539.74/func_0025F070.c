// range: 0x25F070 0x25F0A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0025F070(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x6AEC);
    if ((temp_v1 != 3) && (temp_v1 != 1)) {
        return 0;
    }
    return 1;
}
