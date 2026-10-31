// range: 0x15BF50 0x15BF80
#include "common.h"

u64 *func_0015BF50(u64 *dst, u64 *src) {
    u64 *d = dst;
    s32 i = 13;
    do {
        *d = *src;
        src++;
        d++;
        i--;
    } while (i > 0);
    return dst;
}
