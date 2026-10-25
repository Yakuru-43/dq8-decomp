// range: 0x310490 0x310520
#include "common.h"

struct Item {
    char pad0[0x10];
    s16 kind;
};

struct Node {
    char pad0[0x18];
    struct Node *next;
    struct Item *item;
};

extern M2C_UNK D_003D0870 __attribute__((section(".data")));

extern void func_00300CB0(s32 arg0, M2C_UNK *arg1, s32 arg2);
extern s32 func_00297090(void *arg0);

struct Node *func_00310490(struct Node *node) {
    if (node == NULL) {
        func_00300CB0(0, &D_003D0870, 0x8B);
        return NULL;
    }
    for (;;) {
        node = node->next;
        if (node == NULL) {
            break;
        }
        if (node->item == NULL) {
            continue;
        }
        if (func_00297090(node->item) <= 0) {
            continue;
        }
        if (node->item->kind < 2) {
            continue;
        }
        break;
    }
    return node;
}
