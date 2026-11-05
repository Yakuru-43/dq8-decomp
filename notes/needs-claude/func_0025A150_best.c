// range: 0x0025A150 0x0025A340
#include "common.h"

extern s32 D_003A7350[32];

s32 func_0025A150(s32 arg0, s32 arg1, s16 *arg2, u8 *arg3) {
    u8 *p;
    s16 *out;
    char *coef;
    char *state;
    s32 value;
    u32 count;
    u32 index;
    s32 gainUp;
    s32 gainDown;
    s32 *w0;
    s32 *w1;
    s32 *w2;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 y0;
    s32 y1;
    s32 sum;
    s32 i;

    value = (s32)(u16)((arg3[1] << 8) | arg3[0]);
    count = *(s32 *)(*(s32 *)(arg0 + 0x78) + 0xC);
    index = (value >> 10) & 0x1F;
    gainUp = D_003A7350[(value >> 5) & 0x1F];
    gainDown = D_003A7350[value & 0x1F];
    if (index >= count) {
        index = 0;
    }
    state = (char *)arg0 + arg1 * 12;
    w0 = (s32 *)(state + 0x7C);
    w1 = (s32 *)(state + 0x80);
    w2 = (s32 *)(state + 0x84);
    x0 = *w0;
    x1 = *w1;
    x2 = *w2;
    coef = (char *)(*(s32 *)(arg0 + 0x78)) + index * 12;
    c0 = *(s32 *)(coef + 0x10);
    c1 = *(s32 *)(coef + 0x14);
    c2 = *(s32 *)(coef + 0x18);
    out = arg2;
    p = arg3 + 2;
    for (i = 32; i > 0; i -= 2) {
        u32 packed = *p++;
        u32 nibbleUp = packed >> 4;
        u32 nibbleDown = packed & 0xF;

        sum = -(c0 * x0 + c1 * x1 + c2 * x2);
        if (nibbleUp < 8) {
            y0 = (sum + nibbleUp * gainUp) >> 12;
        } else {
            y0 = (sum + (nibbleUp - 16) * gainDown) >> 12;
        }
        if (y0 >= 0x8000) {
            y0 = 0x7FFF;
        }
        if (y0 < -0x8000) {
            y0 = -0x8000;
        }
        sum = -(c0 * y0 + c1 * x0 + c2 * x1);
        if (nibbleDown < 8) {
            y1 = (sum + nibbleDown * gainUp) >> 12;
        } else {
            y1 = (sum + (nibbleDown - 16) * gainDown) >> 12;
        }
        if (y1 >= 0x8000) {
            y1 = 0x7FFF;
        }
        if (y1 < -0x8000) {
            y1 = -0x8000;
        }
        *out++ = y0;
        *out++ = y1;
        x2 = x0;
        x1 = y0;
        x0 = y1;
    }
    *w0 = y1;
    *w1 = y0;
    *w2 = x2;
    return p - arg3;
}
