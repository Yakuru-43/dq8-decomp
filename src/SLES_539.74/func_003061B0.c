// range: 0x3061B0 0x306220
#include "common.h"

void func_003061B0(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0[2] = arg1;
    if (arg1 < 0.0f) {
        arg0[2] = 0.0f;
    }
    if (1.0f < arg0[2]) {
        arg0[2] = 1.0f;
    }
    arg0[1] = (arg0[2] - arg0[0]) / arg2 / arg3;
}
