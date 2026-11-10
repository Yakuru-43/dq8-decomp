// range: 0x242590 0x242750
#include "common.h"

struct Node {
    /* 0x00 */ u32 pad0[2];
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ u32 pad10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ u32 pad18[3];
    /* 0x24 */ s32 f24;
    /* 0x28 */ u32 pad28[71];
    /* 0x144 */ struct Node *f144;
};

struct Board {
    /* 0x00 */ u32 pad0[6];
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C[4];
    /* 0x2C */ struct Node *f2C[64];
    /* 0x12C */ u32 pad12C[(0x1934 - 0x12C) / 4];
    /* 0x1934 */ struct Node *f1934;
};

extern void func_00241600(struct Board *, struct Node *);
M2C_UNK DebugPrintf(M2C_UNK *);                       /* extern */
extern M2C_UNK D_003C8AC0 __attribute__((section(".data")));

void func_00242590(struct Board *board, s32 key, s32 *dst, s32 max) {
    struct Node *node;
    struct Node *next;
    s32 i;
    s32 n;

    node = board->f1934;
    if (node != 0) {
        do {
            if (node->f24 == key) {
                next = node->f144;
                func_00241600(board, node);
                node = next;
            } else {
                node = node->f144;
            }
        } while (node != 0);
    }
    n = 0;
    for (i = 0; i < 64; i++) {
        node = board->f2C[i];
        if (node != 0) {
            if (node->f14 == key) {
                if (dst != 0) {
                    if (node->fC != 0) {
                        if (n < max) {
                            dst[n] = node->f8;
                            n++;
                        }
                    }
                }
                if (board->f2C[i]->fC != 0) {
                    board->f18--;
                }
                board->f2C[i] = 0;
            }
        }
    }
    if (key > 0 && key < 4) {
        board->f18 -= board->f1C[key];
        board->f1C[key] = 0;
    }
    if (board->f18 < 0) {
        board->f18 = 0;
    }
    if (dst == 0) {
        return;
    }
    if (n < max) {
        dst[n] = -1;
        return;
    }
    DebugPrintf(&D_003C8AC0);
    dst[n - 1] = -1;
}
