// range: 0x3098B0 0x309940
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

static inline s32 IdValid(s32 id) {
    return 0 <= id;
}

static inline u8 EntryBusy(struct Entry *entry) {
    return entry->inUse != 0 && entry->state == 1;
}

s32 func_003098B0(struct Pool *pool) {
    struct Entry *entry;
    s32 total;
    s32 i;

    if (pool->entries == 0) {
        return 0;
    }
    if (IdValid(pool->thread) == 0) {
        return 0;
    }
    if (pool->sema < 0) {
        return 0;
    }
    total = 0;
    for (i = 0; i < pool->count; i++) {
        entry = &pool->entries[i];
        total += EntryBusy(entry);
    }
    return 0 < total;
}
