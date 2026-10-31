// range: 0x1B9B70 0x1B9BD0
#include "common.h"

s32 func_001D6D30(s32, s32, s32, s32);

s32 func_001B9B70(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 val2;
    s32 val1;

    if (*(s32 *)arg0 == 1) {
        val1 = (s32)*(float *)(arg0 + 4);
    } else {
        val1 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        val2 = (s32)*(float *)(arg0 + 0xC);
    } else {
        val2 = *(s32 *)(arg0 + 0xC);
    }
    func_001D6D30(val1, val2, val1, arg3);
    return 1;
}
