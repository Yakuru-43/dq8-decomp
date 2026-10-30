// range: 0x291050 0x291170
#include "common.h"

typedef struct S_14C {
    char pad0[0x14C];
    s32 unk14C;
} S_14C;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_14C *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x128];
    s32 unk590[6];
} S_arg0;

extern s32 func_00297090(S_14C *arg0);

void func_00291050(S_arg0 *arg0) {
    S_Node *node;
    s32 best;
    s32 diff;
    s32 idx;
    s32 i;

    best = 0x10000;
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        if (node->unk3 != 0) {
            diff = func_00297090(node->unk1C) - node->unk1C->unk14C;
            if (diff < best) {
                best = diff;
            }
        }
    }

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
    }

    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        node->unk4 = node->unk3;
        if (node->unk3 != 0) {
            diff = func_00297090(node->unk1C) - node->unk1C->unk14C;
            if (diff != best) {
                node->unk3 = 0;
            } else {
                idx = node->unk10 >> 8;
                arg0->unk590[idx]++;
            }
        }
    }
}
