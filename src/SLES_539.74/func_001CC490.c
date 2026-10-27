// range: 0x1CC490 0x1CC4C0
#include "common.h"

extern s32 D_003E0664;

s32 func_001CC490(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    *(s32 *)(D_003E0664 + 0x44B8) = result;
    return 1;
}
