// range: 0x259C80 0x259CF0
#include "common.h"

extern void func_00131188(void *, s32, s32);

void func_00259C80(s8 *arg0) {
    s8 *p;

    p = arg0;
    func_00131188(p, 0, 0x3C0);
    func_00131188(p + 0x3C0, 0, 0x3C0);
    func_00131188(p + 0x780, 0, 0xF0);
    func_00131188(p + 0x920, 0, 0x3C0);
    *(s32 *)(p + 0x8F0) = 0;
    *(s32 *)(p + 0x8E8) = 0;
}
