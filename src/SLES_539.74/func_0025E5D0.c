// range: 0x25E5D0 0x25E610
#include "common.h"

s32 func_0025E5D0(M2C_UNK *arg0) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (*(s32 *)((char *)arg0 + i * 80) != 0) {
            count++;
        }
    } while (++i < 4);
    return count;
}
