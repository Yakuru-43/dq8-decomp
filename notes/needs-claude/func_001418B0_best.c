// range: 0x1418B0 0x1419A0
#include "common.h"

extern void func_00141020(void *a0, void *a1, s32 *a2, void *a3, s32 a4, s32 a5);

void func_001418B0(void *a0, void *a1, s32 *rect, void *a3, s32 x, s32 y)
{
    s32 vec[8];
    s32 *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7;

    if (a1 == 0) {
        return;
    }
    if (a3 == 0) {
        return;
    }
    p0 = &vec[0];
    p1 = &vec[1];
    p2 = &vec[2];
    p3 = &vec[3];
    p4 = &vec[4];
    p5 = &vec[5];
    p6 = &vec[6];
    p7 = &vec[7];
    *p4 = rect[0];
    *p5 = rect[1];
    *p6 = rect[2];
    *p7 = rect[3] << 4;
    *p0 = y << 4;
    *p1 = x << 4;
    *p2 = (y + (rect[2] - rect[0])) << 4;
    *p3 = (x + (rect[3] - rect[1])) << 4;
    *p4 <<= 4;
    *p5 <<= 4;
    *p6 <<= 4;
    func_00141020(a0, a1, p4, a3, x, y);
}
