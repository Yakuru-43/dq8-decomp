// range: 0x1B9900 0x1B9930
#include "common.h"

extern s32 D_003E0664;

s32 func_001B9900(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    *(s32 *)(D_003E0664 + 0x44B0) = result;
    return 1;
}
