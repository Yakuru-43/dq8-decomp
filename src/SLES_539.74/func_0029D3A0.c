// range: 0x29D3A0 0x29D430
#include "common.h"

struct Node0029D3A0 {
    u8 b0;
    u8 b1;
    char pad2[6];
    struct Node0029D3A0 *prev;
    struct Node0029D3A0 *next;
    char pad10[4];
    struct Node0029D3A0 *f14;
    struct Node0029D3A0 *f18;
};

struct Head0029D3A0 {
    char pad[0x448];
    struct Node0029D3A0 list;
};

extern u8 D_003CB150[];

extern void *func_0029D100(void *arg0, void *arg1);

void func_0029D3A0(struct Head0029D3A0 *owner)
{
    struct Node0029D3A0 *node;
    struct Node0029D3A0 *next;

    node = &owner->list;
    while (node != 0) {
        next = node->next;
        if (node->b1 != 0) {
            node->prev->next = next;
            node->next->prev = node->prev;
            node->f14->f18 = node->f18;
            node->f18->f14 = node->f14;
            func_0029D100(node, D_003CB150);
        }
        node = next;
    }
}
