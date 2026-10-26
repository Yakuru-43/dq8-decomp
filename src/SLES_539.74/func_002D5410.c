// range: 0x2D5410 0x2D5440
#include "common.h"

extern u32 func_002D7830(s32, s32, s32);

s32 func_002D5410(s32 arg0, s32 arg1) {
    u32 temp_v0;

    temp_v0 = func_002D7830(arg0, arg1, 0);
    if (temp_v0 != 0) {
        return *(s32 *)(temp_v0 + 4);
    }
    return 0;
}
