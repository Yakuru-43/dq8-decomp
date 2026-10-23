// range: 0x300AE0 0x300C00
#include "common.h"

void func_0013EBF0(void *, s32, s32);       /* extern */
void func_0013EF90(void *, s32, s32, s32);  /* extern */

struct Off { s16 x; s16 y; };
extern struct Off D_003ACCE0[40];

void func_00300AE0(void *obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct Off offs[40];
    struct Off *src;
    struct Off *dst;
    s32 i;
    u16 x0;
    u16 y0;
    u16 x1;
    u16 y1;
    s32 sumX;
    s32 sumY;
    s32 ex;
    s32 ey;

    if (obj == 0) {
        return;
    }
    src = D_003ACCE0;
    dst = offs;
    for (i = 0x28; i != 0; i--) {
        dst->x = src->x;
        dst->y = src->y;
        src = src + 1;
        dst = dst + 1;
    }
    dst = &offs[(arg1 & 0xFF) * 2];
    x0 = dst[0].x;
    y0 = dst[0].y;
    x1 = dst[1].x;
    y1 = dst[1].y;
    sumX = x1 + x0;
    sumY = y1 + y0;
    ex = arg4 + arg2;
    ey = arg5 + arg3;
    func_0013EBF0(obj, x0, y0);
    func_0013EF90(obj, arg2, arg3, 0);
    func_0013EBF0(obj, sumX, sumY);
    func_0013EF90(obj, ex, ey, 0);
}
