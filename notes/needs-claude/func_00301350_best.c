// range: 0x301350 0x3014F0
#include "common.h"

s32 func_002B0A30(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_0042EA80 __attribute__((section(".data")));

s32 func_00301350(s32 *arg0, s32 *arg1) {
    s32 local[16];
    s32 *src;
    s32 *dst;
    f32 sum;
    s32 count;
    s32 mode;
    s32 found;
    s32 changed;
    s32 cnt;
    s32 i;

    changed = 0;
    sum = 0.0f;
    for (i = 0; i < arg1[0]; i++) {
        cnt = arg1[i * 2 + 2];
        sum += (f32)func_002B0A30(&D_0042EA80, arg1[i * 2 + 1]) * (f32)cnt;
    }

    src = (s32 *)(arg0[1] + (arg0[7] << 6));
    dst = local;
    for (i = 8; i > 0; i--) {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    }

    mode = local[3] / 100;

    for (;;) {
        f32 threshold = 180.0f;
        if (mode == 35) {
            threshold = 160.0f;
        }
        if (sum <= threshold) {
            break;
        }
        count = arg1[0];
        found = 0;
        for (i = 0; i < count; i++) {
            if (arg1[i * 2 + 2] >= 2) {
                found = 1;
                changed = found;
                sum -= (f32)func_002B0A30(&D_0042EA80, arg1[i * 2 + 1]);
                arg1[i * 2 + 2] = arg1[i * 2 + 2] - 1;
                break;
            }
        }
        if (found == 0) {
            break;
        }
    }
    return changed;
}
