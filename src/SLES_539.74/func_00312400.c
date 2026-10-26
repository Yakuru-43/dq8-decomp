// range: 0x312400 0x312440
#include "common.h"

s32 func_00312400(s32 arg0, s32 *arg1, s32 arg2) {
    s32 i = 0;

    while (i < arg2) {
        if (arg1[i] == arg0) {
            return i;
        }
        i++;
    }
    return -1;
}
