// range: 0x2D3970 0x2D39C0
#include "common.h"

typedef struct Node {
    char pad[0x78];
    struct Node *prev;
    struct Node *next;
} Node;

s32 func_002D3970(s32 arg0, Node *arg1, Node *arg2) {
    if (arg1 == NULL) {
        return 0;
    }
    if (arg2 == NULL) {
        return 0;
    }
    if (arg1->prev == NULL) {
        arg2->next = arg1;
        arg1->prev = arg2;
    } else {
        func_002D3970(arg0, arg1->prev, arg2);
    }
    return 1;
}
