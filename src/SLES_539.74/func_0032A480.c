// range: 0x32A480 0x32A4B0
#include "common.h"

s32 func_0032A480(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 0x13) {
        return 1;
    }
    return temp_v1 == 0;
}
