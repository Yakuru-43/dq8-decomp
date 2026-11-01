// range: 0x1A3750 0x1A3870
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct Node {
    s32 state;
    char pad4[0xC];
    f32 pos[4];
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

void func_0010ADF8(f32 *, const f32 *);

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

void func_001A3750(NodePool *pool, const f32 *pos, s32 time) {
    s32 i;
    s32 t;
    Node *n = node_add(pool, &i);

    if (n != NULL) {
        n->state = 15;
        func_0010ADF8(n->pos, pos);
        if (time >= 0) {
            t = time * 50 / 60;
            n->time = (0 < t) ? t : 1;
        } else {
            n->time = time;
        }
    }
}
