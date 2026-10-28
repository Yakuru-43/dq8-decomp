// range: 0x1BDBB0 0x1BDBF0
#include "common.h"

extern s32 D_003E0664;

s32 func_001BDBB0(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    if (result == 0) {
        *(s8 *)(D_003E0664 + 0x55EC) = 1;
    } else {
        *(s8 *)(D_003E0664 + 0x55EC) = 0;
    }
    return 1;
}
