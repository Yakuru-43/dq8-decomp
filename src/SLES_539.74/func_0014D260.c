// range: 0x14D260 0x14D2A0
#include "common.h"

s32 func_0014D260(s32 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0[3];
    if (temp_v1 == 0) {
        return 0;
    }
    if (arg1 >= 0) {
        if (arg1 < arg0[1]) {
            return temp_v1 + (arg0[2] * arg1);
        }
    }
    return 0;
}
