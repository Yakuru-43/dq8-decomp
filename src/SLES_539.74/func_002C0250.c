// range: 0x2C0250 0x2C02D0
#include "common.h"

extern s32 func_002C02D0(s32, s32 *);
extern void *func_0016D5B0(void *, s32);

void func_002C0250(void *arg0, s32 arg1, s32 arg2) {
    s32 buf[4];
    s32 i;
    void *v;

    func_002C02D0(arg1, buf);
    i = 0;
    do {
        v = func_0016D5B0(arg0, buf[i]);
        *(s32 *)(arg2 + (i << 2)) = (s32)v;
        i++;
    } while (i < 4);
}
