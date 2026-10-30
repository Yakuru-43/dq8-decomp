// range: 0x2D48F0 0x2D4930
#include "common.h"

s32 func_003760C0(u16 *, s32);
s32 func_002D4150(void);

s32 func_002D48F0(void) {
    s32 temp_v0;

    temp_v0 = func_002D4150();
    if (temp_v0 != 0) {
        return func_003760C0((u16 *)(temp_v0 + 0x30), 2) != 0;
    }
    return 0;
}
