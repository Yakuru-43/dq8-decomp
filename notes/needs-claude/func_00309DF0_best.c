/* Best attempt (score 47, 528 = 528 bytes) — see the CLASS line and
 * "Remaining diff" notes in func_00309DF0.md. Compile-check with:
 *   tools/try_match.py <this file copied into src/SLES_539.74/> func_00309DF0 0x309DF0 --show -- -O3
 */
// range: 0x309DF0 0x30A000
#include "common.h"

struct Entry {
    /* 0x00 */ s16 inUse;
    /* 0x02 */ s16 ident;
    /* 0x04 */ s16 state;
    /* 0x06 */ s16 pad6;
    /* 0x08 */ s32 logId;
    /* 0x0C */ s32 fieldC;
    /* 0x10 */ s32 handle;
};

struct Pool {
    /* 0x00 */ struct Entry *entries;
    /* 0x04 */ s32 count;
    /* 0x08 */ s32 pad8;
    /* 0x0C */ s32 allocator;
    /* 0x10 */ s8 flag;
    /* 0x11 */ u8 pad11[3];
    /* 0x14 */ s32 sema;
    /* 0x18 */ s32 thread;
};

s32 PollSema(s32);                                      /* extern */
M2C_UNK SignalSema(s32);                                /* extern */
M2C_UNK DeleteSema(s32);                                /* extern */
M2C_UNK TerminateThread(s32);                           /* extern */
M2C_UNK DeleteThread(s32);                              /* extern */
s32 func_0015F450();                                    /* extern */
M2C_UNK func_00159810(s32, s32, s32);                   /* extern */

static inline s32 IdValid(s32 id) {
    return 0 <= id;
}

static inline u8 EntryBusy(struct Entry *entry) {
    return entry->inUse != 0 && entry->state == 1;
}

void func_00309DF0(struct Pool *pool) {
    struct Entry *entries;
    struct Entry *entry;
    s32 active;
    s32 total;
    s32 i;
    s32 handle;

    if (IdValid(pool->thread) == 0) {
        return;
    }
    if (0 <= pool->thread) {
        for (;;) {
            entries = pool->entries;
            if (entries == 0) {
                active = 0;
            } else if (IdValid(pool->thread) == 0) {
                active = 0;
            } else if (pool->sema < 0) {
                active = 0;
            } else {
                total = 0;
                for (i = 0; i < pool->count; i++) {
                    entry = &entries[i];
                    total += EntryBusy(entry);
                }
                active = 0 < total;
            }
            if (active == 0) {
                TerminateThread(pool->thread);
                DeleteThread(pool->thread);
                break;
            }
            if (IdValid(pool->thread) == 0) {
                continue;
            }
            if (pool->sema < 0) {
                continue;
            }
            if (PollSema(pool->sema) >= 0) {
                continue;
            }
            SignalSema(pool->sema);
        }
    }
    pool->thread = -1;
    if (0 <= pool->sema) {
        DeleteSema(pool->sema);
    }
    pool->sema = -1;
    for (i = 0; i < pool->count; i++) {
        entry = &pool->entries[i];
        if (entry->inUse != 0) {
            handle = entry->handle;
            if (handle != 0) {
                func_00159810(func_0015F450(), handle + 8, entry->ident);
            }
        }
        entry->inUse = 0;
        entry->handle = 0;
        entry->state = 0;
        entry->logId = -1;
    }
    pool->entries = 0;
    pool->count = 0;
    pool->allocator = 0;
    pool->flag = -1;
    pool->sema = -1;
    pool->thread = -1;
}
