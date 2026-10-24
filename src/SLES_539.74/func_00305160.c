// range: 0x305160 0x3051C0
#include "common.h"

extern s32 *func_00305240(void *);

s32 func_00305160(void *arg0, s32 arg1, s32 arg2) {
    s32 *ptr;
    s32 value;

    ptr = func_00305240(arg0);
    if (ptr != 0) {
        value = *ptr + arg2;
        if (value > 99999) {
            value = 99999;
        }
        if (value < 0) {
            value = 0;
        }
        *ptr = value;
    }
    return 0;
}
