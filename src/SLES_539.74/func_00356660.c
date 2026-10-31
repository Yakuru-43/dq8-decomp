// range: 0x356660 0x356710
#include "common.h"

s32 func_00356660(char *arg0, char *arg1) {
    s8 t0, t1;
    f32 f0, f1;

    t0 = *(s8 *)(arg0 + 4);
    if (t0 == 0) {
        t1 = *(s8 *)(arg1 + 4);
        if (t1 == 0) {
            return *(s32 *)arg0 == *(s32 *)arg1;
        }
    }

    if (t0 == 1) {
        f1 = *(f32 *)arg0;
    } else if (t0 == 0) {
        f1 = (f32)*(s32 *)arg0;
    } else {
        f1 = 0.0f;
    }

    t1 = *(s8 *)(arg1 + 4);
    if (t1 == 1) {
        f0 = *(f32 *)arg1;
    } else if (t1 == 0) {
        f0 = (f32)*(s32 *)arg1;
    } else {
        f0 = 0.0f;
    }

    if (f1 == f0) {
        return 1;
    }
    return 0;
}
