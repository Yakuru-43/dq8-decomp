// range: 0x0034B2A0 0x0034B350
#include "common.h"

extern u8 D_00453B60[] __attribute__((section(".data")));
extern void *func_0034B240(u8 *, s32);
extern s32 func_0024CEF0(s32, s32);

s32 func_0034B2A0(s32 *arg0, s32 *arg1) {
    s32 key2;
    void *rec1;
    void *rec2;
    s32 a;
    s32 b;

    key2 = arg1[0];
    rec1 = func_0034B240(D_00453B60, arg0[0]);
    rec2 = func_0034B240(D_00453B60, key2);
    a = func_0024CEF0(*(s16 *)rec1, 2);
    b = func_0024CEF0(*(s16 *)rec2, 2);
    if (b < a) {
        return 1;
    }
    return -(func_0024CEF0(*(s16 *)rec1, 2) < func_0024CEF0(*(s16 *)rec2, 2));
}
