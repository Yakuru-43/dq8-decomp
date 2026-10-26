// range: 0x22AB70 0x22ABB0
#include "common.h"

s32 func_0022AB70(s32 arg0) {
    s32 rem;
    s32 q;

    rem = arg0 % 64;
    if (rem != 0) {
        if (arg0 < 0) {
            q = (arg0 + 0x3F) >> 6;
        } else {
            q = arg0 >> 6;
        }
        arg0 = (q + 1) << 6;
    }
    return arg0;
}
