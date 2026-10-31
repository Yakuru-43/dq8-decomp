// range: 0x32A600 0x32A630
#include "common.h"

s32 func_0032A600(s32 arg0, s32 arg1) {
    u32 v = arg1 & 0xFF;

    if (v == 0xC) {
        return 1;
    }
    if (v == 8) {
        return 1;
    }
    return v == 0;
}
