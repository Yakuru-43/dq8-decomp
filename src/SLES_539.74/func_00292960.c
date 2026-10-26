// range: 0x292960 0x292A90
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

extern s32 func_00292C60(S_arg0 *arg0);
extern s32 func_0029CCC0(S_arg0 *arg0, S_Node *node);
extern s32 func_0029CD30(S_arg0 *arg0, S_Node *node);

/* recount the running nodes like func_00292240, but the wanted kind comes
   from the table state: with flag clear CCC0 tests the node, with flag set
   CD30 does; a node that fails is retired, the rest bump their bucket */
void func_00292960(S_arg0 *arg0) {
    S_Node *node;
    s32 flag;
    s32 i;

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
    }
    flag = func_00292C60(arg0);
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            return;
        }
        node->unk4 = node->unk3;
        if (node->unk3 == 0) {
            continue;
        }
        if (node->unk1C != 0 && node->unk1C->unk560 == 1) {
            node->unk3 = 0;
            continue;
        }
        if (flag == 0) {
            if ((func_0029CCC0(arg0, node) & 0xFF) == 0) {
                node->unk3 = 0;
            } else {
                goto bump;
            }
        } else {
            if ((func_0029CD30(arg0, node) & 0xFF) == 0) {
                node->unk3 = 0;
            } else {
                goto bump;
            }
        }
        continue;
    bump:
        arg0->unk590[node->unk10 >> 8]++;
    }
}
