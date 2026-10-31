// range: 0x2D53E0 0x2D5410
#include "common.h"

extern u32 func_002D77E0(s32, s32, s32);

s32 func_002D53E0(s32 arg0, s32 arg1) {
    u32 temp_v0;

    temp_v0 = func_002D77E0(arg0, arg1, 0);
    if (temp_v0 != 0) {
        return *(s32 *)(temp_v0 + 4);
    }
    return 0;
}
