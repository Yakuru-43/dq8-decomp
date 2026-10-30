// range: 0x374BB0 0x374C90
#include "common.h"

extern void *D_003E0874;
extern void func_00312440(void *, void *, s32, s32, s32);
extern void func_00311FD0(void *, s32, s32);

void func_00374BB0(void *arg0, s32 arg1)
{
    void *s0 = D_003E0874;
    void *s2 = arg0;
    s32 s1 = arg1;

    if (s1 == 0) {
        func_00312440(s0, s2, 1, -1, 0);
        func_00311FD0(s0, 2, 0);
    }

    if (s1 == 1) {
        func_00312440(s0, s2, 2, 1, 0);
        func_00311FD0(s0, 3, 0);
    }

    if (s1 == 2) {
        func_00312440(s0, s2, 2, 2, 0);
        func_00311FD0(s0, 4, 0);
    }
}
