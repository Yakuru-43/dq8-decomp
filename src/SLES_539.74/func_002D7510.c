// range: 0x2D7510 0x2D7560
#include "common.h"

extern void *func_002D4150(void);

void func_002D7510(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    void *temp_v0;

    *arg3 = 0.0f;
    *arg2 = 0.0f;
    temp_v0 = func_002D4150();
    if (temp_v0 != 0) {
        *arg2 = *(f32 *)((char *)temp_v0 + 0x20);
        *arg3 = *(f32 *)((char *)temp_v0 + 0x24);
    }
}
