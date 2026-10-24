// range: 0x309A30 0x309AA0
#include "common.h"

struct Pool {
    void *entries;
    s32 count;
    s32 pad8;
    s32 allocator;
    s32 pad10;
    s32 sema;
    s32 thread;
};

s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */

static inline s32 IdValid(s32 id) {
    return 0 <= id;
}

void func_00309A30(struct Pool *pool) {
    s32 sema;

    if (IdValid(pool->thread) == 0) {
        return;
    }
    sema = pool->sema;
    if (sema < 0) {
        return;
    }
    if (PollSema(sema) < 0) {
        SignalSema(pool->sema);
    }
}
