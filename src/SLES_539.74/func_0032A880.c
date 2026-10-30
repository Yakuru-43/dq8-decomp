// range: 0x32A880 0x32A8B0
#include "common.h"

s32 func_0032A880(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 2) {
        return 1;
    }
    if (temp_v1 == 1) {
        return 1;
    }
    return temp_v1 == 0;
}
