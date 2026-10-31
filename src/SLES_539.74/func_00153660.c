// range: 0x153660 0x153680
#include "common.h"

s32 func_00153660(s32 arg0, s32 arg1) {
    if (arg1 == 8) {
        return 1;
    }
    return (u32)(arg1 ^ 7) < 1;
}
