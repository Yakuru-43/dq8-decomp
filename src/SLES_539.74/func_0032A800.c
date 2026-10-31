// range: 0x32A800 0x32A830
#include "common.h"

s32 func_0032A800(s32 arg0, s32 arg1) {
    u32 v1 = arg1 & 0xFF;
    if (v1 == 9) {
        return 1;
    }
    if (v1 == 8) {
        return 1;
    }
    return v1 == 0;
}
