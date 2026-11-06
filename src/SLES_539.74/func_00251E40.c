// range: 0x251E40 0x251F00
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

M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
extern M2C_UNK D_003C8F50 __attribute__((section(".data")));

void func_00251E40(AllocPool *pool, u32 size) {
    AllocNode *node;
    AllocNode *prev;
    AllocNode *next;

    if (size == 0) {
        return;
    }
    node = pool->nodes;
    prev = 0;
    if (node == 0) {
        return;
    }
    while (node != 0) {
        if (node->size == size) {
            break;
        }
        prev = node;
        node = node->next;
    }
    if (node == 0) {
        DebugPrintf(&D_003C8F50);
        while (1) {}
    }
    prev->pos = node->pos;
    prev->next = node->next;
    next = prev->next;
    if (next != 0) {
        next->prev = prev;
    }
    node->prev = 0;
    node->next = 0;
    node->size = 0;
    node->pos = 0;
    node->base = 0;
}
