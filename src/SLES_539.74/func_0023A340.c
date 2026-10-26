// range: 0x23A340 0x23A370
#include "common.h"

extern s32 D_003E0B24;

s32 func_0023A340(char *arg0) {
    s32 result;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    *(s32 *)(D_003E0B24 + 0x134) = result;
    return 1;
}
