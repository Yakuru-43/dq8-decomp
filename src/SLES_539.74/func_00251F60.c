// range: 0x251F60 0x2520C0
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct AllocNode {
    /* 0x0 */ u32 size;
    /* 0x4 */ u32 base;
    /* 0x8 */ u32 pos;
    /* 0xC */ struct AllocNode *next;
    /* 0x10 */ struct AllocNode *prev;
} AllocNode;

typedef struct AllocPool {
    /* 0x00 */ s32 count;
    /* 0x04 */ AllocNode *slots;
    /* 0x08 */ u8 pad08[0x1C];
    /* 0x24 */ AllocNode *nodes;
} AllocPool;

static inline u8 IsFree(AllocNode *p) {
    return !p->size;
}

static inline AllocNode *FindFree(AllocNode *slots, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        if (IsFree(&slots[i])) {
            return &slots[i];
        }
    }
    return 0;
}

AllocNode *func_00251F60(AllocPool *pool, u32 arg1, u32 arg2) {
    AllocNode *node;
    AllocNode *slot;
    u32 pos;
    u32 rem;

    node = pool->nodes;
    if (node == 0) {
        return 0;
    }
    while (node->next != 0) {
        node = node->next;
    }
    if (pool->slots == 0) {
        slot = 0;
    } else {
        slot = FindFree(pool->slots, pool->count);
    }
    if (slot == 0) {
        return 0;
    }
    slot->prev = 0;
    slot->next = 0;
    slot->size = 0;
    slot->pos = 0;
    slot->base = 0;
    while (node != 0) {
        pos = node->pos;
        rem = pos % arg2;
        if (rem != 0) {
            pos = pos - rem;
        }
        if ((pos < node->base) || ((pos - node->base) < arg1)) {
            node = node->prev;
            continue;
        }
        slot->size = pos - arg1;
        slot->base = pos;
        slot->pos = node->pos;
        node->pos = slot->size;
        slot->next = node->next;
        if (slot->next != 0) {
            slot->next->prev = slot;
        }
        node->next = slot;
        slot->prev = node;
        return slot;
    }
    return 0;
}
