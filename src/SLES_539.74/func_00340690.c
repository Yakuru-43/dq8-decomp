// range: 0x340690 0x3406F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340690(s32 *arg0) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 0x254) && (temp_v1 != 0x5C) && (temp_v1 != 0x18) && (temp_v1 != 0x42) && (temp_v1 != 0xAF)) {
        return 0;
    }
    return 1;
}
