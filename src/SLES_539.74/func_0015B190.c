// range: 0x15B190 0x15B280
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
    s32 count;
} FuncMgr;

void func_0015B190(FuncMgr *mgr, FuncNode *node) {
    FuncNode **slot;
    FuncNode *cur;
    FuncNode *prev;
    FuncNode *found;
    s8 *p;
    u8 hash;

    if (node == NULL) {
        return;
    }
    p = node->name;
    hash = 0;
    while (*p != 0) {
        hash = ((hash << 8) + *p) % 101;
        p++;
    }
    slot = (FuncNode **)((u8 *)mgr->buckets + hash * 4);
    prev = NULL;
    found = NULL;
    for (cur = *slot; cur != NULL; cur = cur->next) {
        if (cur->self == node) {
            found = cur;
            break;
        }
        prev = cur;
    }
    if (found == NULL) {
        return;
    }
    if (prev != NULL) {
        prev->next = found->next;
    } else {
        *slot = found->next;
    }
    if (mgr->count > 0) {
        mgr->count--;
        mgr->entries[mgr->count] = found;
    }
}
