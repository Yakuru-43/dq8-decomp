// range: 0x16E370 0x16E3A0
#include "common.h"

s32 func_0016E370(s32 arg0, s32 arg1) {
    if (arg1 == 0x4E20) {
        return 1;
    }
    if (arg1 == 0x2713) {
        return 1;
    }
    return (u32)(arg1 ^ 0xA) < 1;
}
