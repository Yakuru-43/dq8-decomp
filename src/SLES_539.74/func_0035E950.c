// range: 0x35E950 0x35E9A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0035E950(void *arg0) {
    s32 temp_v1;

    if (arg0 == NULL) {
        return 0;
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0xE0);
    if ((temp_v1 != 0x4E) && (temp_v1 != 0x4F) && (temp_v1 != 0x50)) {
        return 0;
    }
    return 1;
}
