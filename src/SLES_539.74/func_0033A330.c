// range: 0x33A330 0x33A380
#include "common.h"

extern s32 func_0014EA80(s32);
extern s32 func_00100630(s32, void *, s32, s32, s32);
extern void func_0033A2B0(void);

void func_0033A330(s32 *arg0) {
    s32 tmp;

    tmp = func_0014EA80(0x4410);
    arg0[2] = func_00100630(tmp, func_0033A2B0, 0, 0x220, 0x20);
}
