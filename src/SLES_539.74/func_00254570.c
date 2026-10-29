// range: 0x254570 0x2545C0
#include "common.h"

extern void func_00131188(void *, s32, s32);

void func_00254570(s8 *arg0) {
    s32 *p;

    func_00131188(arg0, 0, 0xE0);
    p = (s32 *)arg0;
    p[0x58 / 4] = -1;
    *(s16 *)&p[0xD4 / 4] = -1;
    p[0x5C / 4] = -1;
    p[0xAC / 4] = 0;
    p[0xB0 / 4] = 0;
    p[0xC0 / 4] = 0;
    p[0xD0 / 4] = 0;
}
