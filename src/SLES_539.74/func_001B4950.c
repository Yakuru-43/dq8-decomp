// range: 0x1B4950 0x1B4980
#include "common.h"

extern s32 D_003E0664;

s32 func_001B4950(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    *(s32 *)(D_003E0664 + 0x6B28) = result;
    return 1;
}
