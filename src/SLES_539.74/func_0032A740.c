// range: 0x32A740 0x32A770
#include "common.h"

s32 func_0032A740(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFF;
    if (temp_v1 == 0x10) {
        return 1;
    }
    return temp_v1 == 0;
}
