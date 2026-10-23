// range: 0x306220 0x306290
#include "common.h"

void func_00306220(f32 *arg0) {
    f32 bound;
    f32 v;
    f32 rate;

    rate = arg0[1];
    if (rate == 0.0f) {
        return;
    }
    v = arg0[0] + rate;
    if (0.0f < rate) {
        bound = arg0[2];
        if (v > bound) {
            arg0[1] = 0.0f;
            v = bound;
        }
    } else {
        bound = arg0[2];
        if (v < bound) {
            arg0[1] = 0.0f;
            v = bound;
        }
    }
    arg0[0] = v;
}
