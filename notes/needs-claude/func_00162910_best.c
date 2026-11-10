// range: 0x162910 0x162B20
// best attempt (score 65, reorder+register; 488 B version scored 41), NOT matched
#include "common.h"

typedef struct {
    /*0x00*/ void *vptr;
    /*0x04*/ u32 unk04;
    /*0x08*/ void *fp08;
    /*0x0C*/ void *fp0C;
    /*0x10*/ void *fp10;
} NodeVtbl;

typedef struct {
    /*0x00*/ NodeVtbl *vptr;
    /*0x08*/ u8 pad08[0xA8 - 0x08];
    /*0xA8*/ void *cb_a8;
    /*0xAC*/ u32 unkac;
    /*0xB0*/ u8 b0;
    /*0xB1*/ u8 b1;
    /*0xB2*/ u8 pad_b2[0xB4 - 0xB2];
    /*0xB4*/ u32 unk_b4;
    /*0xB8*/ u8 pad_b8[0xC8 - 0xB8];
    /*0xC8*/ u32 count_c8;
    /*0xCC*/ u8 pad_cc[0xD4 - 0xCC];
    /*0xD4*/ s32 d4;
    /*0xD8*/ u8 pad_d8[0xF0 - 0xD8];
    /*0xF0*/ u8 unk_f0;
    /*0xF1*/ u8 pad_f1[0x110 - 0xF1];
    /*0x110*/ u8 p110;
    /*0x111*/ u8 pad_111[0x118 - 0x111];
    /*0x118*/ u8 p118;
    /*0x119*/ u8 pad_119[0x11C - 0x119];
    /*0x11C*/ u32 state1c;
    /*0x120*/ u8 p120;
    /*0x121*/ u8 pad_121[0x128 - 0x121];
    /*0x128*/ u8 p128;
    /*0x129*/ u8 pad_129[0x170 - 0x129];
    /*0x170*/ f32 f170;
    /*0x174*/ u8 pad_174[0x1D4 - 0x174];
    /*0x1D4*/ f32 f1d4;
} Node;

extern s32 func_00160E20(u32, Node ***, s32, s32, u32);

s32 func_00162910(char *arg0, s32 arg1, f32 *arg2) {
    Node **list;
    s32 cnt;
    Node **cur;
    Node *n;
    Node *p;
    char *sub;
    s32 s7;
    u8 b1;
    u32 st;
    s32 s0;
    f32 f2;
    f32 f0;

    list = *(Node ***)(arg0 + 8);
    cnt = 0;
    cur = list[0];
    while (cur != 0) {
        n = (Node *)cur[2];
        if (n->b0 != 0) {
            s7 = n->b0 & 0x3F;
            if (0 <= s7) {
                if (s7 < 0x41) {
                    b1 = n->b1;
                    if (((s32 (*)(Node *, u32))((NodeVtbl *)n->vptr)->fp08)(n, b1) != 0) {
                        cnt++;
                    }
                }
            }
        }
        cur = (Node **)cur[0];
    }
    p = cur;
    if (p != 0) {
        return 0;
    }
    n = list[2];
    sub = (char *)n + 0x120;
    s0 = (s32)n->f1d4;
    if (arg1 == 0) {
        if (((s32 (*)(Node *, u32))((NodeVtbl *)n->vptr)->fp08)(n, n->b1) != 0) {
            cnt--;
        }
        switch (n->state1c) {
        case 0:
            ((void (*)(char *, u8, void *, u32))n->cb_a8)(sub, n->unk_f0, n->fp0C, n->unkac);
            ((void (*)(char *, u8, void *, u32))n->fp10)(sub + 8, n->unk_f0, n->fp10, n->unk04);
            *arg2 = n->f170;
            *(s32 *)(arg2 + 1) = 0x1644;
            ((void (*)(char *, s32, u32, u32))n->cb_a8)(sub - 8, 3, n->unk_b4, n->p118);
            ((void (*)(char *, s32, u32, u32))n->fp0C)(sub - 8, 4, n->unk_b4, n->p118);
            ((void (*)(char *, u8, void *, u32))n->fp10)(sub - 0x10, n->p110, n->fp0C, n->unkac);
            break;
        case 1:
            ((void (*)(char *, u8, void *, u32))n->cb_a8)(sub, n->unk_f0, n->fp0C, n->unkac);
            ((void (*)(char *, u8, void *, u32))n->fp10)(sub + 8, n->unk_f0, n->fp10, n->unk04);
            *arg2 = n->f170;
            *(s32 *)(arg2 + 1) = 0x1644;
            break;
        case 2:
            f2 = n->f170;
            ((void (*)(char *, s32, void *, u32))n->cb_a8)(sub - 8, 3, n->cb_a8, n->p118);
            ((void (*)(char *, s32, void *, u32))n->fp10)(sub, n->unk_f0, n->fp0C, n->unkac);
            *arg2 = f2;
            *(s32 *)(arg2 + 1) = 0x1644;
            f0 = n->f170;
            ((void (*)(char *, s32, u32, u32))n->fp0C)(sub - 8, 4, n->unk_b4, n->p118);
            ((void (*)(char *, s32, u32, u32))n->cb_a8)(sub - 8, 5, n->unk_b4, n->p118);
            ((void (*)(char *, u8, void *, u32))n->fp10)(sub - 0x10, n->p110, n->fp0C, n->unkac);
            break;
        case 3:
            f0 = n->f170;
            ((void (*)(char *, s32, void *, u32))n->cb_a8)(sub - 8, 3, n->cb_a8, n->p118);
            ((void (*)(char *, s32, void *, u32))n->fp10)(sub, n->unk_f0, n->fp0C, n->unkac);
            *arg2 = n->f170;
            *(s32 *)(arg2 + 1) = 0x1644;
            f0 = n->f170;
            ((void (*)(char *, s32, u32, u32))n->fp0C)(sub - 8, 4, n->unk_b4, n->p118);
            ((void (*)(char *, s32, u32, u32))n->cb_a8)(sub - 8, 5, n->unk_b4, n->p118);
            ((void (*)(char *, u8, void *, u32))n->fp10)(sub - 0x10, n->p110, n->fp0C, n->unkac);
            break;
        }
    } else if (arg1 != 4) {
        s7 = 0;
    } else {
        s7 = 4;
    }
    st = n->state1c & 0xFF;
    if (st <= 4) {
        if (func_00160E20(st, &list, 0, 0, 0) == 0) {
            if (arg1 != 0) {
                if (((s32 (*)(Node *, u32))((NodeVtbl *)n->vptr)->fp08)(n, n->b1) != 0) {
                    cnt--;
                }
                switch (st) {
                case 1:
                    ((void (*)(char *, u8, void *, u32))n->cb_a8)(sub, n->unk_f0, n->fp0C, n->unkac);
                    ((void (*)(char *, u8, void *, u32))n->fp10)(sub + 8, n->unk_f0, n->fp10, n->unk04);
                    *arg2 = n->f170;
                    *(s32 *)(arg2 + 1) = 0x1644;
                    break;
                case 2:
                    f2 = n->f170;
                    ((void (*)(char *, s32, void *, u32))n->cb_a8)(sub - 8, 3, n->cb_a8, n->p118);
                    ((void (*)(char *, s32, void *, u32))n->fp10)(sub, n->unk_f0, n->fp0C, n->unkac);
                    *arg2 = f2;
                    *(s32 *)(arg2 + 1) = 0x1644;
                    f0 = n->f170;
                    ((void (*)(char *, s32, u32, u32))n->fp0C)(sub - 8, 4, n->unk_b4, n->p118);
                    ((void (*)(char *, s32, u32, u32))n->cb_a8)(sub - 8, 5, n->unk_b4, n->p118);
                    ((void (*)(char *, u8, void *, u32))n->fp10)(sub - 0x10, n->p110, n->fp0C, n->unkac);
                    break;
                case 3:
                    f0 = n->f170;
                    ((void (*)(char *, s32, void *, u32))n->cb_a8)(sub - 8, 3, n->cb_a8, n->p118);
                    ((void (*)(char *, s32, void *, u32))n->fp10)(sub, n->unk_f0, n->fp0C, n->unkac);
                    *arg2 = n->f170;
                    *(s32 *)(arg2 + 1) = 0x1644;
                    f0 = n->f170;
                    ((void (*)(char *, s32, u32, u32))n->fp0C)(sub - 8, 4, n->unk_b4, n->p118);
                    ((void (*)(char *, s32, u32, u32))n->cb_a8)(sub - 8, 5, n->unk_b4, n->p118);
                    ((void (*)(char *, u8, void *, u32))n->fp10)(sub - 0x10, n->p110, n->fp0C, n->unkac);
                    break;
                case 4:
                    ((void (*)(char *, u8, void *, u32))n->cb_a8)(sub, n->unk_f0, n->fp0C, n->unkac);
                    ((void (*)(char *, u8, void *, u32))n->fp10)(sub + 8, n->unk_f0, n->fp10, n->unk04);
                    *arg2 = n->f170;
                    *(s32 *)(arg2 + 1) = 0x1644;
                    break;
                }
            }
            *(s32 *)(arg2 + 1) = s7;
            ((void (*)(char *, s32, u32, u32))n->fp0C)(sub - 8, 4, n->unk_b4, n->p118);
            ((void (*)(char *, s32, u32, u32))n->cb_a8)(sub - 8, 5, n->unk_b4, n->p118);
            ((void (*)(char *, u8, void *, u32))n->fp10)(sub - 0x10, n->p110, n->fp0C, n->unkac);
        }
    }
    return cnt;
}
