// range: 0x32A640 0x32A670
#include "common.h"

s32 func_0032A640(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 7) {
        return 1;
    }
    if (temp_v1 == 1) {
        return 1;
    }
    return temp_v1 == 0;
}
