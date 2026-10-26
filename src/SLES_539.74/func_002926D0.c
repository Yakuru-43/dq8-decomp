// range: 0x2926D0 0x292830
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
extern s32 func_0029CB00(S_arg0 *arg0, S_Node *node);
extern s32 func_0029CB80(S_arg0 *arg0, S_Node *node);
extern s32 func_0029CCC0(S_arg0 *arg0, S_Node *node);
extern s32 func_0029CD30(S_arg0 *arg0, S_Node *node);

/* recount the running nodes like func_00292830, but each side runs two
   limit checks and only a node that fails both is retired */
void func_002926D0(S_arg0 *arg0) {
    S_Node *node;
    s32 mode;
    s32 i;

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
    }
    mode = func_00292C60(arg0);
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
                if (mode == 0) {
                    if ((func_0029CCC0(arg0, node) & 0xFF) == 0 &&
                        (func_0029CB00(arg0, node) & 0xFF) == 0) {
                        node->unk3 = 0;
                        continue;
                    }
                } else if ((func_0029CD30(arg0, node) & 0xFF) == 0 &&
                           (func_0029CB80(arg0, node) & 0xFF) == 0) {
                    node->unk3 = 0;
                    continue;
                }
                arg0->unk590[node->unk10 >> 8]++;
            }
        }
    }
}
