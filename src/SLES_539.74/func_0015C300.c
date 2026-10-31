// range: 0x15C300 0x15C330
#include "common.h"

s32 func_0015C300(s32 arg0, s32 arg1) {
    if (arg1 == 3) {
        return 1;
    }
    if (arg1 == 2) {
        return 1;
    }
    return (u32)(arg1 ^ 1) < 1;
}
