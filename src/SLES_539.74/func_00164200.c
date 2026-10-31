// range: 0x164200 0x1642A0
// flags: -flag divbyzerocheck
#include "common.h"

f32 func_00164200(s32 *arg0) {
    s32 v;
    s32 q;

    v = arg0[3] - 0x80;
    if (v >= 50 || v <= -50) {
        q = (v > 0) ? ((v - 49) << 7) / 78 : ((v + 50) << 7) / 78;
    } else {
        q = 0;
    }
    return (f32)q / 128.0f;
}
