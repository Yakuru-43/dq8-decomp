// range: 0x1A3900 0x1A3A10
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct Node {
    s32 state;
    char pad4[0x1C];
    s32 time;
    char pad24[0x28];
    struct Node *next;
} Node;

typedef struct {
    Node *items;
    s32 count;
    char pad8[0x8];
    Node *head;
    Node *tail;
} NodePool;

void DebugPrintf(const char *, const char *, ...);
extern char D_003C3E40[] __attribute__((section(".data")));
extern char D_003C3E58[] __attribute__((section(".data")));

static inline Node *node_add(NodePool *pool, s32 *index) {
    Node *n = pool->items;
    s32 i;

    for (i = 0; i < pool->count; i++, n++) {
        if (n->state == 0) {
            n->next = NULL;
            goto found;
        }
    }
    n = NULL;
found:
    *index = i;
    if (n == NULL) {
        return NULL;
    }
    if (pool->tail != NULL) {
        pool->tail->next = n;
    }
    pool->tail = n;
    n->next = NULL;
    if (pool->head == NULL) {
        pool->head = n;
    }
    return n;
}

void func_001A3900(NodePool *pool, s32 time) {
    s32 i;
    s32 t;
    Node *n = node_add(pool, &i);

    if (n != NULL) {
        n->state = 13;
        if (time >= 0) {
            t = time * 50 / 60;
            n->time = (0 < t) ? t : 1;
        } else {
            n->time = time;
        }
        DebugPrintf(D_003C3E58, D_003C3E40, n->time, i);
    }
}
