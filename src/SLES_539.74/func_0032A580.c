// range: 0x32A580 0x32A5B0
#include "common.h"

s32 func_0032A580(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 14) {
        return 1;
    }
    if (temp_v1 == 8) {
        return 1;
    }
    return temp_v1 == 0;
}
