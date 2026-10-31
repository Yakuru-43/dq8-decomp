// range: 0x257430 0x257470
#include "common.h"

s32 func_00257430(s32 *arg0, s16 arg1, s32 arg2, s32 arg3, s16 arg4, s32 arg5) {
    char *p;
    s32 i;

    p = (char *)(*arg0 + arg2 * 12);
    for (i = 0; i < arg3; i++) {
        *(s16 *)(p + 0) = arg1;
        *(s16 *)(p + 2) = arg4;
        *(s32 *)(p + 4) = arg5;
        p = p + 12;
    }
    return 1;
}
