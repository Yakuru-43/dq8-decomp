// range: 0x2E66D0 0x2E6710
#include "common.h"

s32 func_002E66D0(char *arg0, s32 arg1) {
    s32 sum;
    s32 i;

    sum = 0;
    for (i = 0; i < arg1; i++) {
        sum += *(s32 *)(arg0 + 0xFC);
        sum += *(s32 *)(arg0 + (i * 4) + 0x17E8);
    }
    return sum;
}
