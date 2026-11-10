// range: 0x257200 0x257230
#include "common.h"

s32 func_00257200(s32 *arg0, s32 *arg1) {
    s32 b1 = arg1[1];
    s32 a1 = arg0[1];
    s32 one = 1;

    if (b1 < a1) {
        return one;
    }
    return -(one < b1);
}
