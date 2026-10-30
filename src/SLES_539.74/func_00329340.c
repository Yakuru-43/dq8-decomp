// range: 0x329340 0x3293C0
#include "common.h"

struct Node {
    struct Node *next;
    struct Node *field_4;
};

struct List {
    struct Node *field_0;
    struct Node *field_4;
    s32 field_8;
};

void func_00329340(struct List *arg0) {
    struct Node *node;
    struct Node *cur;

    node = arg0->field_4;
    if (node != NULL) {
        if (node != arg0->field_0) {
            arg0->field_4 = node->field_4;
        }
    } else {
        if (arg0->field_8 != 0) {
            arg0->field_8 = 0;
            cur = arg0->field_0;
            if (cur != NULL) {
                while (cur != NULL) {
                    node = cur->next;
                    if (node == NULL) {
                        break;
                    }
                    cur = node;
                }
                arg0->field_4 = cur;
            }
        }
    }
}
