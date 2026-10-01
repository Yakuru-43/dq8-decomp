// range: 0x2D8070 0x2D80F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D8070(void *arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8 *, 0x2A);
    if ((temp_v1 != 6) && (temp_v1 != 7) && (temp_v1 != 8) && (temp_v1 != 9) && (temp_v1 != 0x13) && (temp_v1 != 0x14) && (temp_v1 != 0x18) && (temp_v1 != 0x19)) {
        return 1;
    }
    return 0;
}
