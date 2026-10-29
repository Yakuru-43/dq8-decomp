// range: 0x275FA0 0x276030
#include "common.h"

struct Node {
    struct Node *prev;
    struct Node *next;
    u32 flags;
};

void func_00275FA0(struct Node *arg0, struct Node **arg1) {
    struct Node *temp_a3;
    struct Node *temp_a1;
    struct Node *temp_a1_2;

    temp_a3 = arg0->next;
    if (*arg1 == arg0) {
        *arg1 = temp_a3;
    }
    arg0->next = temp_a3->prev;
    temp_a1 = temp_a3->prev;
    if (temp_a1 != NULL) {
        temp_a1->flags = (u32)arg0 | (temp_a1->flags & 1);
    }
    temp_a3->flags = (arg0->flags & ~1u) | (temp_a3->flags & 1);
    temp_a1_2 = (struct Node *)(arg0->flags & ~1u);
    if (arg0 == temp_a1_2->prev) {
        temp_a1_2->prev = temp_a3;
    } else {
        temp_a1_2->next = temp_a3;
    }
    temp_a3->prev = arg0;
    arg0->flags = (u32)temp_a3 | (arg0->flags & 1);
}
