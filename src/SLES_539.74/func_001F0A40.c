// range: 0x1F0A40 0x1F0A60
#include "common.h"

s32 func_001F0A40(s32 arg0, s32 arg1) {
    if (arg1 == 10011) {
        return 1;
    }
    return (u32)(arg1 ^ 10010) < 1;
}
