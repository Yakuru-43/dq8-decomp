// range: 0x278080 0x278120
#include "common.h"

extern void *func_0014EB30(s32);

struct Node {
    struct Node *next;
    s32 value;
};

struct List {
    u8 pad[0x64];
    struct Node *head;
};

void func_00278080(struct List *arg0, s32 arg1, s32 arg2) {
    struct Node *node;
    struct Node *cur;

    if (arg2 == 0) {
        return;
    }

    node = func_0014EB30(8);
    if (node != NULL) {
        node->next = NULL;
    }
    if (node == NULL) {
        return;
    }
    node->value = arg2;
    cur = arg0->head;
    if (cur != NULL) {
        while (cur != NULL) {
            if (cur->next == NULL) {
                break;
            }
            cur = cur->next;
        }
        cur->next = node;
    } else {
        arg0->head = node;
    }
}
