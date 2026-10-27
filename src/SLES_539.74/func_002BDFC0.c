// range: 0x002BDFC0 0x002BE010
#include "common.h"

extern void func_0014A8C0(void *obj, f32 *vec);

void func_002BDFC0(void *obj, f32 x, f32 y, f32 z)
{
    u8 buf[16];
    u8 *p = buf;
    u32 n = 16;

    if (p != 0) {
        do {
            *p = 0;
            n = n - 1;
            p = p + 1;
        } while (n != 0);
    }
    *(f32 *)&buf[0] = x;
    *(f32 *)&buf[4] = y;
    *(f32 *)&buf[8] = z;
    func_0014A8C0(obj, (f32 *)buf);
}
