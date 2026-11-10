// range: 0x0015B280 0x0015B370
#include "common.h"

typedef struct FuncNode {
    /* 0x00 */ void *self;
    /* 0x04 */ struct FuncNode *next;
    /* 0x08 */ s8 name[8];
} FuncNode;

typedef struct FuncMgr {
    /* 0x00 */ u8 pad_00[0x30];
    /* 0x30 */ FuncNode *buckets[101];
    /* 0x1C4 */ u8 pad_1C4[0x14];
    /* 0x1D8 */ FuncNode **entries;
    /* 0x1DC */ s32 capacity;
    /* 0x1E0 */ s32 index;
} FuncMgr;

void func_0015B280(FuncMgr *mgr, FuncNode *obj) {
    FuncNode *entry;
    FuncNode *node;
    FuncNode **slot;
    s8 *p;
    u8 hash;
    s32 c;
    s32 i;

    i = mgr->index;
    if (i < mgr->capacity) {
        entry = mgr->entries[i];
        mgr->index = i + 1;
    } else {
        entry = 0;
    }
    if (entry == 0) {
        return;
    }
    entry->next = 0;
    entry->self = obj;
    hash = 0;
    p = obj->name;
    while ((c = *p) != 0) {
        hash = ((hash << 8) + c) % 101;
        p = p + 1;
    }
    node = mgr->buckets[hash];
    slot = &mgr->buckets[hash];
    if (node == 0) {
        *slot = entry;
    } else {
        while (node != 0) {
            if (node->next == 0) {
                node->next = entry;
                return;
            }
            node = node->next;
        }
    }
}
