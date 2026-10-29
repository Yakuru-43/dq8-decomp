// range: 0x2D78D0 0x2D7920
#include "common.h"

void *func_002D4150();
void *func_002DE3D0(void *);

u32 func_002D78D0(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0_2 = func_002D4150();
    if (!temp_v0_2) {
        return 0;
    }
    temp_v0 = func_002DE3D0(temp_v0_2);
    if (!temp_v0) {
        return 0;
    }
    return (u32)temp_v0 + (arg2 << 5);
}
