// range: 0x1E24D0 0x1E24F0
#include "common.h"

s32 func_001E24D0(s32 arg0, s32 arg1) {
    if (arg1 == 10007) {
        return 1;
    }
    return (u32)(arg1 ^ 10005) < 1;
}
