// range: 0x29DE30 0x29DEC0
#include "common.h"

struct Target0029DE30 {
    char pad[0x140];
    s32 f140;
    s32 f144;
};

struct Node0029DE30 {
    char pad0[8];
    struct Node0029DE30 *prev;
    struct Node0029DE30 *next;
    char pad10[4];
    struct Node0029DE30 *f14;
    struct Node0029DE30 *f18;
    struct Target0029DE30 *f1C;
};

struct Owner0029DE30 {
    char pad[0x448];
    struct Node0029DE30 list;
};

void func_0029DE30(struct Owner0029DE30 *owner, struct Target0029DE30 *target, s32 flag)
{
    struct Node0029DE30 *node;
    struct Node0029DE30 *prev;
    struct Node0029DE30 *next;
    struct Node0029DE30 *f14;
    struct Node0029DE30 *f18;

    if (target == 0) {
        return;
    }
    if (flag != 0) {
        target->f140 = 0;
        target->f144 = 0;
    }
    node = &owner->list;
    while ((node = node->next) != 0) {
        if (node->f1C != target) {
            continue;
        }
        prev = node->prev;
        next = node->next;
        f14 = node->f14;
        f18 = node->f18;
        if (prev != 0) {
            prev->next = next;
        }
        if (next != 0) {
            next->prev = prev;
        }
        if (f14 != 0) {
            f14->f18 = f18;
        }
        if (f18 != 0) {
            f18->f14 = f14;
        }
        node->f1C = 0;
        break;
    }
}
