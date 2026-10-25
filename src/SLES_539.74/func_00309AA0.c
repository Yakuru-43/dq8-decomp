// range: 0x309AA0 0x309BA0
#include "common.h"

struct Entry {
    s16 inUse;
    s16 ident;
    s16 state;
    s16 pad6;
    s32 logId;
    s32 fieldC;
    s32 handle;
};

struct Pool {
    struct Entry *entries;
    s32 count;
    s32 pad8;
    s32 allocator;
    s32 pad10;
    s32 sema;
    s32 thread;
};

struct Pool *func_0017A770(void);                    /* extern */
M2C_UNK WaitSema(s32);                               /* extern */
s32 func_0030A180(struct Entry *, s32);              /* extern */

static inline s32 IdValid(s32 id) {
    return 0 <= id;
}

static inline struct Entry *GetEntry(struct Pool *pool, s32 i) {
    struct Entry *entries;

    entries = pool->entries;
    if (entries == 0) {
        return 0;
    }
    if (i < 0 || pool->count <= i) {
        return 0;
    }
    return &entries[i];
}

void func_00309AA0(void) {
    s32 i;
    struct Pool *pool;
    struct Entry *entry;
    s32 result;

    pool = func_0017A770();
    if (pool->sema < 0) {
        return;
    }
    while (IdValid(pool->thread) != 0) {
        WaitSema(pool->sema);
        for (i = 0; i < pool->count; i++) {
            entry = GetEntry(pool, i);
            if (entry->state == 1) {
                result = func_0030A180(entry, 0);
                if (result != 0) {
                    entry->state = 2;
                } else {
                    entry->inUse = 0;
                    entry->state = 0;
                }
            }
        }
    }
}
