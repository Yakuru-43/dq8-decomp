// range: 0x356430 0x356480
#include "common.h"

s32 func_00356430(char *arg0, f32 arg1) {
    s8 t0;
    f32 f0;

    t0 = *(s8 *)(arg0 + 4);
    if (t0 == 1) {
        f0 = *(f32 *)arg0;
    } else if (t0 == 0) {
        f0 = (f32)*(s32 *)arg0;
    } else {
        f0 = 0.0f;
    }

    if (arg1 == f0) {
        return 1;
    }
    return 0;
}
