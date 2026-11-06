// range: 0x1885A0 0x188630
#include "common.h"

typedef struct {
    u8 pad1[0x6B10];
    f32 time;
} Clock;

s32 func_001885A0(Clock *clock) {
    f32 time = clock->time;
    s32 ret = 0;

    if (18.0f <= time || time < 1.0f) {
        ret = 1;
    } else if (1.0f <= time && time < 6.0f) {
        ret = 2;
    }
    if (ret == 2) {
        ret = 1;
    }
    return ret;
}
