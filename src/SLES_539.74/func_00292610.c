// range: 0x292610 0x2926D0
#include "common.h"

typedef struct S_560 {
    char pad0[0x560];
    u8 unk560;
} S_560;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_560 *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x128];
    s32 unk590[6];
} S_arg0;

void func_00292610(S_arg0 *arg0, s32 arg1) {
    S_Node *node;
    s32 i;

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
    }
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            return;
        }
        node->unk4 = node->unk3;
        if (node->unk3 != 0) {
            if (node->unk1C != 0 && node->unk1C->unk560 == 1) {
                node->unk3 = 0;
            } else {
                if ((node->unk10 >> 8) == arg1) {
                    node->unk3 = 0;
                } else {
                    arg0->unk590[node->unk10 >> 8]++;
                }
            }
        }
    }
}
