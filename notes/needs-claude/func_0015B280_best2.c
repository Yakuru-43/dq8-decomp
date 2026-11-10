// best (score 49, 2026-11-05 factory-1 retry): fetch-then still cold-placed
// range: 0x15B280 0x15B370
#include "common.h"

typedef struct FuncNode {
    struct FuncNode *self;
    struct FuncNode *next;
    s8 name[1];
} FuncNode;

typedef struct FuncMgr {
    u8 pad_0[0x30];
    FuncNode *buckets[101];
    u8 pad_1C4[0x14];
    FuncNode **entries;
    s32 capacity;
    s32 index;
} FuncMgr;

void func_0015B280(FuncMgr *mgr, FuncNode *obj) {
    FuncNode *entry;
    FuncNode *node;
    FuncNode **slot;
    s8 *p;
    u8 hash;
    s32 i;

    i = mgr->index;
    if (i < mgr->capacity) {
        mgr->index = i + 1;
        entry = mgr->entries[i];
    } else {
        entry = 0;
    }
    if (entry != 0) {
        entry->next = 0;
        p = obj->name;
        entry->self = obj;
        hash = 0;
        while (*p != 0) {
            hash = ((hash << 8) + *p) % 101;
            p++;
        }
        slot = &mgr->buckets[hash];
        node = *slot;
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
}
