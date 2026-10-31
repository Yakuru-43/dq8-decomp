// range: 0x1F2670 0x1F2760
#include "common.h"

typedef struct Node {
    struct Node *next;
    s32 unk4[3];
    struct Node *item;
    s32 unk14[12];
    s32 active;
    s32 hit;
    s32 unk4C[3];
    f32 lo;
    f32 hi;
} Node;

typedef struct {
    s32 unk0;
    Node **table;
    Node *cur;
} NodeList;

static inline Node *NodeList_Next(NodeList *list) {
    Node *n = list->cur;
    if (n == NULL) {
        return NULL;
    }
    list->cur = n->next;
    return n->item;
}

static inline s32 InRange(f32 v, f32 lo, f32 hi) {
    if (!(hi <= lo)) {
        if (v < lo) {
            return 0;
        }
        if (v >= hi) {
            return 0;
        }
        return 1;
    }
    if (lo <= hi) {
        return 1;
    }
    if (v >= lo) {
        return 1;
    }
    if (v < hi) {
        return 1;
    }
    return 0;
}

s32 func_001F2670(NodeList *list, s32 index, f32 *val) {
    Node *n;
    s32 mark;
    s32 count;

    list->cur = NULL;
    if (list->table != NULL && index >= 0 && index < 11) {
        list->cur = list->table[index];
    }
    count = 0;
    for (;;) {
        n = NodeList_Next(list);
        if (n == NULL) {
            list->cur = NULL;
            return count;
        }
        if (!n->active) {
            mark = 0;
        } else if (val == NULL) {
            mark = 1;
        } else {
            mark = InRange(*val, n->lo, n->hi);
        }
        n->hit = mark;
        if (mark != 0) {
            count++;
        }
    }
}
