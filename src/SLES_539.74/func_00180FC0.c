// range: 0x180FC0 0x181030
#include "common.h"

extern void func_00131188(void *, s32, s32);

void *func_00180FC0(void *arg0) {
    s32 *p;

    func_00131188(arg0, 0, 0x2C);
    p = (s32 *)arg0;
    p[0] = -1;
    p[3] = -1;
    p[4] = -1;
    p[2] = 1;
    p[5] = 1;
    p[6] = 0x3F800000;
    p[7] = 0;
    p[8] = -1;
    p[9] = 0;
    p[10] = 0;
    return arg0;
}
