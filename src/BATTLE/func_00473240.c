// range: 0x473240 0x473290
#include "common.h"

extern void func_1E9EC0(void *, void *);

void func_00473240(void *arg0, f32 a, f32 b, f32 c) {
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
    func_1E9EC0(arg0, buf);
}
