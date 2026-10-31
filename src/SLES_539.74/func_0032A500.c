// range: 0x32A500 0x32A530
#include "common.h"

s32 func_0032A500(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 0x11) {
        return 1;
    }
    return temp_v1 == 0;
}
