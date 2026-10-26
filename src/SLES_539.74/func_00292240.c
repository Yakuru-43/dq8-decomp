// range: 0x292240 0x292370
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

extern s64 func_00296F60(void *arg0);
extern s32 func_00296F20(void *arg0, s32 arg1);

/* recount the running nodes, dropping the ones whose owner is free: a node
   whose flag bit is clear, or whose kind does not equal the wanted one, is
   still running and bumps its counter; the rest are retired */
void func_00292240(S_arg0 *arg0, s32 arg1, s32 arg2) {
    S_Node *node;
    s64 mask;
    s32 want;
    s32 i;

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
    }
    mask = (s64)1 << (arg1 & 0xFF);
    want = arg2 & 0xFF;
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            return;
        }
        node->unk4 = node->unk3;
        if (node->unk3 != 0) {
            if (node->unk1C != 0 && node->unk1C->unk560 == 1) {
                node->unk3 = 0;
            } else if ((mask & func_00296F60(node->unk1C)) == 0
                       || (func_00296F20(node->unk1C, arg1) & 0xFF) != want) {
                arg0->unk590[node->unk10 >> 8]++;
            } else {
                node->unk3 = 0;
            }
        }
    }
}
