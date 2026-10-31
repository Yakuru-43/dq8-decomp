// range: 0x310520 0x310580
#include "common.h"

struct Node {
    char pad0[0x18];
    struct Node *next;
    void *item;
};

extern void *func_00310580(void *arg0, s32 arg1);
extern s32 func_00297090(void *arg0);

struct Node *func_00310520(struct Node *node) {
    for (;;) {
        node = func_00310580(node, 0);
        if (node == NULL) {
            return NULL;
        }
        if (node->item == NULL) {
            return NULL;
        }
        if (func_00297090(node->item) > 0) {
            return node;
        }
    }
}
