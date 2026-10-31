// range: 0x1AF720 0x1AF770
#include "common.h"

s32 func_001AF720(s32 *arg0, s32 arg1, s128 *arg2, f32 fparg0) {
    if (arg0[0] >= 0) {
        arg0[0] = -1;
        arg0[1] = -1;
        arg0[4] = 0;
        arg0[5] = 0;
        arg0[6] = 0;
        arg0[7] = 0x3F800000;
    }
    arg0[0] = 3;
    arg0[1] = arg1;
    *(s128 *)&arg0[4] = *arg2;
    *(f32 *)&arg0[8] = fparg0;
    return 1;
}
