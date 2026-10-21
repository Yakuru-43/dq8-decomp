// range: 0x2FE090 0x2FE120
#include "common.h"

s32 func_002FE090(u16 *arg0, u16 *arg1, s32 arg2) {
    u16 val;
    s32 i;
    s32 count;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    i = 0;
    count = 0;
    while ((val = arg0[i]) != 0) {
        if (val == 0xFF01) {
            break;
        }
        arg1[count] = val;
        count++;
        i++;
    }
    if (arg2 != 0) {
        arg1[count] = 0xFF01;
        count++;
    }
    return count;
}
