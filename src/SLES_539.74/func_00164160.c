// range: 0x164160 0x164200
// flags: -flag divbyzerocheck
#include "common.h"

f32 func_00164160(s32 *arg0) {
    s32 v;
    s32 q;

    v = arg0[2] - 0x80;
    if (v >= 50 || v <= -50) {
        q = (v > 0) ? ((v - 49) << 7) / 78 : ((v + 50) << 7) / 78;
    } else {
        q = 0;
    }
    return (f32)q / 128.0f;
}
