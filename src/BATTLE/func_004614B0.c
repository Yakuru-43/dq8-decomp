// range: 0x4614B0 0x461500
#include "common.h"

extern void func_151A20(void *, void *, f32, f32, f32);

void func_004614B0(void *arg0, f32 a, f32 b, f32 c) {
    f32 buf[4];
    u8 *p;
    s32 i;

    i = 16;
    p = (u8 *)buf;
    if (p != 0) {
        do {
            *p++ = 0;
        } while (i -= 1);
    }
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    func_151A20(arg0, buf, a, b, c);
}
