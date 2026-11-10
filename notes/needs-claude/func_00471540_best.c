// range: 0x471540 0x471610
#include "common.h"

extern s32 func_308870(s32, s32);
extern s32 func_3089E0(s32, s32);

extern s32 D_003E0CAC __attribute__((section(".sdata")));

typedef struct S_Node {
    s32 kind;
    union {
        f32 value;
        s32 count;
        struct S_Node *next;
    } u;
} S_Node;

s32 func_00471540(S_Node *node) {
    s32 second;
    S_Node *self;
    s32 first;
    s32 kind;
    s32 ret;

    self = node;
    kind = self[0].kind;
    if (kind == 1) {
        first = (s32)self[0].u.value;
    } else {
        first = self[0].u.count;
    }
    kind = self[1].kind;
    if (kind == 1) {
        second = (s32)self[1].u.value;
    } else {
        second = self[1].u.count;
    }
    if (first == 0) {
        ret = func_3089E0(D_003E0CAC, second);
    }
    if (first == 1) {
        ret = func_308870(D_003E0CAC, second);
    }
    kind = self[2].kind;
    if (kind == 3) {
        self[2].u.next->u.count = ret;
    }
    return 1;
}
