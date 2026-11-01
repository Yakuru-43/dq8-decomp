// range: 0x235250 0x2352E0
#include "common.h"

s32 func_00235250(s32 arg0, s32 *arg1, s32 arg2) {
    s32 found;
    s32 ret;
    s32 i;
    s32 j;
    s32 *p;

    found = 0;
    ret = 0;
    for (i = 0; i < arg2; i++) {
        if (arg1[i * 3] == arg0) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        for (j = 0; j < arg2; j++) {
            p = &arg1[j * 3];
            if (*p < 0) {
                *p = arg0;
                ret = 1;
                break;
            }
        }
    }
    return ret;
}
