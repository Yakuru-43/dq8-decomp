// range: 0x1CC500 0x1CC530
#include "common.h"

extern s32 D_003E0664;

s32 func_001CC500(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    *(s32 *)(D_003E0664 + 0x6B18) = result;
    return 1;
}
