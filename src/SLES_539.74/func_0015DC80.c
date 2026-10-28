// range: 0x15DC80 0x15DCE0
#include "common.h"

extern void func_00144C60(void *, void *);
extern s8 *D_003E0298;

void func_0015DC80(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
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
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = arg2;
    buf[3] = arg3;
    func_00144C60(D_003E0298, buf);
}
