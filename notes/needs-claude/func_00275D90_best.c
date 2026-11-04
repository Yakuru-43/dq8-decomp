// CLASS structural score=116 (100 words differ, 464 vs 528 bytes) — best attempt,
// 2026-11-04 factory-2. Everything above +0x1C is register/reuse diffs only.
// range: 0x275D90 0x275FA0
// Red-black rebalance after an insert: walks up from the new node through
// red parents, recolouring red uncles or rotating around the grandparent.
#include "common.h"

struct Node {
    struct Node *prev;
    struct Node *next;
    u32 flags;
};

void func_00275FA0(struct Node *arg0, struct Node **arg1);
void func_00276030(struct Node *arg0, struct Node **arg1);

static inline u32 IsRed(struct Node *n)
{
    return (n->flags & 1u) != 0u;
}

void func_00275D90(struct Node *node, struct Node *stop)
{
    struct Node *cur;
    struct Node *parent;
    struct Node *grand;
    struct Node *uncle;

    cur = node;
    cur->flags |= 1u;
    for (;;) {
        if (cur == stop) {
            break;
        }
        parent = (struct Node *)(cur->flags & ~1u);
        if (IsRed(parent) != 1u) {
            break;
        }
        grand = (struct Node *)(parent->flags & ~1u);
        if (parent == grand->prev) {
            uncle = grand->next;
            if (uncle == NULL || IsRed(uncle) != 1u) {
                if (cur == parent->next) {
                    cur = parent;
                    func_00275FA0(parent, &stop);
                }
                parent = (struct Node *)(cur->flags & ~1u);
                parent->flags &= ~1u;
                grand = (struct Node *)(parent->flags & ~1u);
                grand->flags |= 1u;
                func_00275FA0((struct Node *)(grand->flags & ~1u), &stop);
                continue;
            }
            parent->flags &= ~1u;
            uncle->flags &= ~1u;
            cur = (struct Node *)(parent->flags & ~1u);
            cur->flags |= 1u;
        } else {
            uncle = grand->prev;
            if (uncle == NULL || IsRed(uncle) != 1u) {
                if (cur == parent->prev) {
                    cur = parent;
                    func_00276030(parent, &stop);
                }
                parent = (struct Node *)(cur->flags & ~1u);
                parent->flags &= ~1u;
                grand = (struct Node *)(parent->flags & ~1u);
                grand->flags |= 1u;
                func_00275FA0((struct Node *)(grand->flags & ~1u), &stop);
                continue;
            }
            parent->flags &= ~1u;
            uncle->flags &= ~1u;
            cur = (struct Node *)(parent->flags & ~1u);
            cur->flags |= 1u;
        }
    }
    stop->flags &= ~1u;
}
