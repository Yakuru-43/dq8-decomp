// range: 0x308D80 0x308DD0
// auto: hand
#include "common.h"

extern void func_00131188(char *, s32, s32);

void func_00308D80(s32 *arg0) {
    s32 *obj;

    obj = arg0;
    if (obj != 0) {
        func_00131188((char *)obj, 0, 0x30);
        obj[4] = 5;
        obj[5] = 5;
        obj[6] = 5;
        obj[1] = 0;
        obj[2] = 1;
    }
}
