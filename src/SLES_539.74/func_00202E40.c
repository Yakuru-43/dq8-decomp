// range: 0x202E40 0x202E80
#include "common.h"

s32 func_00202E40(s32 *arg0, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        if (arg2 == arg0[i]) {
            return 1;
        }
    }
    return 0;
}
