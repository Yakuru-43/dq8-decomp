// range: 0x15ADD0 0x15AEB0
// best draft of func_0015ADD0 (score=43, never matched; kept out of src/)
#include "common.h"

typedef struct Chain {
    u8 pad0[6];
    s16 type;    /* 0x06 */
    u8 pad8[0x28 - 8];
    u16 count;   /* 0x28 */
    u8 pad2A[0x36 - 0x2A];
    s16 mark;    /* 0x36 */
    u8 pad38[0x50 - 0x38];
    s32 ref;     /* 0x50 */
    u8 pad54[0x64 - 0x54];
    struct Chain *next; /* 0x64 */
} Chain;

typedef struct Pool {
    s32 total;   /* 0x00 */
    s32 base;    /* 0x04 */
    s32 unk8;    /* 0x08 */
    s32 count;   /* 0x0C */
    s32 start;   /* 0x10 */
    s32 end;     /* 0x14 */
    s32 unk18;   /* 0x18 */
    s32 entries; /* 0x1C */
} Pool;

s32 func_0015ADD0(Pool *pool, s32 idx) {
    s32 fits;
    s32 size;
    s32 remaining;
    s32 total;
    s32 mark;
    Chain *node;

    if (idx < 0 || idx >= pool->count) {
        return 0;
    }
    node = *(Chain **)(pool->entries + (idx << 4));
    total = pool->total;
    remaining = pool->end - pool->start;
    mark = pool->start;
    while (node != 0) {
        if (mark == 0 && node->type == 8 && node->ref != 0) {
            fits = 1;
            size = node->count * 4;
        } else {
            fits = 0;
        }
        if (fits != 0 && remaining >= size) {
            remaining -= size;
        } else {
            total += node->count;
        }
        if (node->type < 9) {
            total += 4;
        }
        node = node->next;
        mark = node->mark;
    }
    return pool->base - total;
}
