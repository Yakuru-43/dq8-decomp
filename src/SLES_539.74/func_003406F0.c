// range: 0x3406F0 0x340740
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003406F0(s32 *arg0) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 0x1D3) && (temp_v1 != 0x21) && (temp_v1 != 0xB1) && (temp_v1 != 0xB0)) {
        return 0;
    }
    return 1;
}
