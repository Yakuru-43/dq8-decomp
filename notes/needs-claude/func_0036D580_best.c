// Parked draft for func_0036D580 (needs-claude, factory-3 2026-11-05).
// This file is NOT compiled. See notes/needs-claude/func_0036D580.md.
// range: 0x36D580 0x36D640
#include "common.h"

typedef struct LNode {
    s16 unk0;
    char pad2[0x22];
    struct LNode *next;
} LNode;

typedef struct {
    char pad0[0x574];
    LNode *unk574;
    LNode *unk578;
    char pad57C[0x4];
    s8 unk580;
    s8 unk581;
    char pad582[0x2];
    s32 unk584;
    s16 unk588;
} S_arg0;

extern void func_0036D640(S_arg0 *arg0);

void func_0036D580(S_arg0 *arg0, s32 arg1, s32 arg2) {
    LNode *saved;
    s32 found;
    LNode *prev;

    if (arg0->unk588 == 3) {
        arg0->unk588 = 1;
    }
    saved = arg0->unk578;
    prev = 0;
    found = 0;
    arg0->unk578 = arg0->unk574;
    while (arg0->unk578 != 0) {
        if (*(s16 *)arg0->unk578 == arg1) {
            found = 1;
            if (arg2 == 0) {
                arg0->unk580 = 1;
                arg0->unk581 = 0;
                arg0->unk584 = arg1;
            } else {
                arg0->unk578 = prev;
                func_0036D640(arg0);
            }
            break;
        }
        prev = arg0->unk578;
        arg0->unk578 = prev->next;
    }
    if (found != 0) {
        arg0->unk578 = saved;
    }
}
