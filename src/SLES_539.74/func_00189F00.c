// range: 0x189F00 0x189F80
#include "common.h"

extern void *func_0016D5B0(void *arg0, s32 arg1);
extern void func_00288270(void *arg0, s32 arg1);
extern void func_00288260(void *arg0, f32 arg1);

void func_00189F00(void *arg0) {
    s32 i;
    void *obj;

    i = 0;
    do {
        obj = func_0016D5B0(arg0, i);
        if (obj != 0) {
            func_00288270(obj, 0);
            func_00288260(obj, 1.0f);
        }
        i++;
    } while (i < 0xC0);
}
