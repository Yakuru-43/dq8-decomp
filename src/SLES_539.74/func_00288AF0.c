// range: 0x288AF0 0x288B40
#include "common.h"

typedef struct {
    s32 field_00;
    char pad4[0x4];
    s32 field_08;
    char padC[0x14];
} Node;

typedef struct {
    char pad0[0x20C];
    s32 count;
    Node *entries;
} Container;

Node *func_00288AF0(Container *arg0, s32 arg1, s32 arg2) {
    Node *node;
    s32 count;
    s32 matchCount;
    s32 i;

    node = arg0->entries;
    if (node == NULL) {
        return NULL;
    }
    count = arg0->count;
    matchCount = -1;
    i = 0;
    while (i < count) {
        if (node->field_08 == arg1) {
            matchCount += 1;
        }
        if (matchCount == arg2) {
            return node;
        }
        i += 1;
        node = (Node *)((char *)node + 0x20);
    }
    return NULL;
}
