// range: 0x309940 0x309A30
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

void func_001339E0(char *, char *, s32);             /* extern */
s32 func_0015F450();                                 /* extern */
s32 func_0015A970(s32, s32, char *, s32, s32, s32);  /* extern */
extern char D_003D0208[];

static inline s32 IdValid(s32 id) {
    return 0 <= id;
}

void func_00309940(struct Pool *pool) {
    char buf[0x20];
    struct Entry *entry;
    s32 i;

    if (pool->entries == 0) {
        return;
    }
    if (IdValid(pool->thread) == 0) {
        return;
    }
    if (pool->sema < 0) {
        return;
    }
    for (i = 0; i < pool->count; i++) {
        entry = &pool->entries[i];
        if (entry->inUse == 0) {
            continue;
        }
        if (entry->state != 2) {
            continue;
        }
        func_001339E0(buf, D_003D0208, entry->logId);
        entry->handle = func_0015A970(func_0015F450(), entry->ident, buf,
                                      entry->fieldC, 0, 0);
        entry->state = 3;
    }
}
