// range: 0x2E2480 0x2E24E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002E2480(s32 arg0) {
    s32 temp_v1;

    temp_v1 = arg0 & 0xFFFF;
    if ((temp_v1 != 0xFD12) && (temp_v1 != 0xFD14) && (temp_v1 != 0xFD25) && (temp_v1 != 0xFD26) && (temp_v1 != 0xFD27) && (temp_v1 != 0xFD28)) {
        return 0;
    }
    return 1;
}
