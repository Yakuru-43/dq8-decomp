// range: 0x351470 0x3514C0
#include "common.h"

extern void func_001E9FB0(void *, void *);

void func_00351470(void *arg0, f32 a, f32 b, f32 c) {
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
    func_001E9FB0(arg0, buf);
}
