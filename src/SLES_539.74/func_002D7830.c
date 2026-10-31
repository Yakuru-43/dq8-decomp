// range: 0x2D7830 0x2D7880
#include "common.h"

void *func_002D4150();
void *func_002DE280(void *);

u32 func_002D7830(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0_2 = func_002D4150();
    if (!temp_v0_2) {
        return 0;
    }
    temp_v0 = func_002DE280(temp_v0_2);
    if (!temp_v0) {
        return 0;
    }
    return (u32)temp_v0 + (arg2 * 0xC);
}
