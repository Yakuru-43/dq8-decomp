// range: 0x1F4A00 0x1F4A20
#include "common.h"

s32 func_001F4A00(s32 arg0, s32 arg1) {
    if (arg1 == 10012) {
        return 1;
    }
    return (u32)(arg1 ^ 10010) < 1;
}
