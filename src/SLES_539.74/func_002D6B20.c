// range: 0x2D6B20 0x2D6BB0
#include "common.h"

extern s32 func_002D73C0(void *, void *, s32 *, s32 *);
extern void func_002D6D10(void *, void *);
extern void func_002D7120(void *, void *, s32, s32);

s32 func_002D6B20(void *a0, void *a1, void *a2, s32 a3, s32 t0)
{
    s32 out1;
    s32 out2;

    if (func_002D73C0(a0, a1, &out1, &out2) == 0) {
        return 0;
    }
    func_002D6D10(a0, a2);
    func_002D7120(a0, a2, out1 + a3, out2 + t0);
    return 1;
}
