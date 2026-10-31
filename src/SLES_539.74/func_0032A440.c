// range: 0x32A440 0x32A470
#include "common.h"

s32 func_0032A440(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 0x14) {
        return 1;
    } else {
        return temp_v1 == 0;
    }
}
