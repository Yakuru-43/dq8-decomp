// range: 0x29D430 0x29D4F0
#include "common.h"

struct Node0029D430 {
    char pad0[0x10];
    u16 kind;
    char pad12[4];
    struct Node0029D430 *next;
};

struct Owner0029D430 {
    char pad0[0x448];
    struct Node0029D430 list;
    char pad1[0x5C0 - 0x448 - sizeof(struct Node0029D430)];
    s32 counts[6];
};

extern s32 func_0029CCC0(struct Owner0029D430 *owner, struct Node0029D430 *node);
extern s32 func_0029CD30(struct Owner0029D430 *owner, struct Node0029D430 *node);

void func_0029D430(struct Owner0029D430 *owner) {
    s32 i;
    struct Node0029D430 *node;

    for (i = 0; i < 6; i++) {
        owner->counts[i] = 0;
    }
    node = &owner->list;
    while ((node = node->next) != 0) {
        if (node->kind == 0xFFFF) {
            return;
        }
        if (func_0029CCC0(owner, node) || func_0029CD30(owner, node)) {
            owner->counts[node->kind >> 8] += 1;
        }
    }
}
