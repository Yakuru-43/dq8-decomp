// range: 0x14B240 0x14B280
#include "common.h"

s32 func_0014B240(s32 arg0, char *arg1, s128 *arg2) {
    *(s128 *)arg1 = 0;
    *(s32 *)arg1 = 0x60000001;
    *(s32 *)(arg1 + 8) = 0x01000101;
    *(s32 *)(arg1 + 0xC) = 0x6C010058;
    *(s128 *)(arg1 + 0x10) = *arg2;
    return 2;
}
