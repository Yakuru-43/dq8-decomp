// range: 0x29D560 0x29D5C0
#include "common.h"

typedef struct {
    char pad0[0x140];
    s32 count;
} S_ref;

typedef struct S_node {
    char pad0[0x8];
    struct S_node *next;
    char padC[0x1C - 0xC];
    S_ref *ref;
} S_node;

typedef struct {
    char pad0[0x488];
    S_node *node;
} S_owner;

void func_0029D560(S_owner *arg0) {
    S_node *node;
    S_ref *ref;

    node = arg0->node;
    if (node != 0) {
        ref = node->ref;
        if (ref != 0) {
            ref->count -= 1;
            node = arg0->node;
            if (node->ref->count < 2) {
                arg0->node = node->next;
            }
        } else {
            arg0->node = node->next;
        }
    }
}
