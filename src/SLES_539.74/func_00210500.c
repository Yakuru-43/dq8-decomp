// range: 0x210500 0x210550
#include "common.h"

u64 func_00210500(void *a0) {
    u64 best;
    s32 i;
    u64 cur;

    best = 0;
    for (i = 0; i < 30; i++) {
        cur = *(u64 *)((char *)a0 + 0x6C30 + i * 0x50);
        if (best < cur) {
            best = cur;
        }
    }
    return best;
}
