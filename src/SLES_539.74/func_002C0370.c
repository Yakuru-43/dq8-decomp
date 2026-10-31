// range: 0x2C0370 0x2C0420
#include "common.h"

extern s32 func_002C0180(s32, s32);
extern void func_0018DCB0(void *, void *, void *);
extern void *func_0014E130(void *, s32);
extern void func_0014E030(void *);

void func_002C0370(void *arg0, s32 arg1) {
    s32 i;
    void *obj;

    i = 0;
    do {
        obj = (void *)func_002C0180(i, 1);
        func_0018DCB0(obj, 0, 0);
        if (arg1 != 0 && arg0 != 0) {
            void *v = func_0014E130(arg0, 0xABE);
            func_0018DCB0(obj, v, (void *)0xABE);
            func_0014E030(arg0);
        }
        i++;
    } while (i < 4);
}
