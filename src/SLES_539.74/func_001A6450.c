// range: 0x1A6450 0x1A6580
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct Node {
    s32 state;
    char pad4[0xC];
    f32 pos[4];
    char pad20[0x10];
    s32 time;
    char pad34[0x28];
    struct Node *next;
} Node;

typedef struct {
    Node *items;
    s32 count;
    char pad8[0x18];
    Node *head;
    Node *tail;
} NodePool;

void func_0010AD00(f32, f32 *, f32 *);
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

void func_001A6450(NodePool *pool, const f32 *pos, s32 time) {
    s32 i;
    Node *n = node_add(pool, &i);

    if (n == NULL) {
        return;
    }
    if (time > 0) {
        time = time * 50 / 60;
        if (time <= 0) {
            time = 1;
        }
    }
    n->state = 33;
    func_0010ADF8(n->pos, pos);
    n->time = time;
    if (time <= -1) {
        func_0010AD00(n->time, n->pos, n->pos);
    }
    n->pos[0] = 0.0f;
    n->pos[2] = 0.0f;
}
