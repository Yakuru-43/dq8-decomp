// range: 0x3012F0 0x301350
#include "common.h"

s32 func_003012F0(s32 *arg0) {
    s32 local[16];
    s32 *src;
    s32 *dst;
    s32 i;

    src = (s32 *)(arg0[1] + (arg0[7] << 6));
    dst = local;
    for (i = 8; i > 0; i--) {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    }
    return local[3] / 100;
}
