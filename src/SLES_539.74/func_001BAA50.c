// range: 0x1BAA50 0x1BAA80
#include "common.h"

extern s32 D_003E0664;

s32 func_001BAA50(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    *(s8 *)(D_003E0664 + 0x6B04) = (s8) result;
    return 1;
}
