// range: 0x0014E750 0x0014E860
#include "common.h"

typedef struct Blk {
    struct Blk *data; /* +0x00 */
    struct Blk *next; /* +0x04 */
    s32 size16;       /* +0x08 */
    s32 count;        /* +0x0C */
} Blk;

typedef struct Pool {
    char pad_00[0x10];
    s32 units10; /* 0x10 */
    char *base14; /* 0x14 */
    Blk *blk18;  /* 0x18 */
    Blk *list1C; /* 0x1C */
    s32 v20;     /* 0x20 */
    s32 v24;     /* 0x24 */
    s32 v28;     /* 0x28 */
    s32 v2C;     /* 0x2C */
    s32 idx30;   /* 0x30 */
    s32 v34;     /* 0x34 */
    char pad_38[4];
    s32 v3C;     /* 0x3C */
    s32 v40;     /* 0x40 */
    s32 v44;     /* 0x44 */
    s32 v48;     /* 0x48 */
    s32 v4C;     /* 0x4C */
} Pool;

static inline void pool_clear(Pool *pool) {
    pool->units10 = 0;
    pool->base14 = 0;
    pool->blk18 = 0;
    pool->v28 = 0;
    pool->v2C = 0;
    pool->v34 = 0;
    pool->v20 = 0;
    pool->v4C = 0;
    pool->v48 = 0;
    pool->v44 = 0;
    pool->v40 = 0;
    pool->v24 = 0;
    pool->idx30 = -1;
    pool->v3C = 0;
}

void func_0014E750(Pool *pool, char *mem, s32 units) {
    pool_clear(pool);
    pool->base14 = mem;
    pool->units10 = units;
    if (mem == 0 || (u32)pool->units10 < 0x10) {
        pool_clear(pool);
        return;
    }
    pool->blk18 = (Blk *)mem;
    pool->blk18->data = (Blk *)(pool->base14 + (pool->units10 << 4) - 0x10);
    pool->blk18->next = 0;
    pool->blk18->size16 = 1;
    pool->blk18->count = 0;
    pool->list1C = pool->blk18->data;
    pool->list1C->next = pool->blk18;
    pool->list1C->data = 0;
    pool->list1C->size16 = 1;
    pool->list1C->count = 0;
    pool->v24 = 0;
}
