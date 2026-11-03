// range: 0x241600 0x241740
#include "common.h"

struct Node {
    void *f0;
    void *f4;
    u32 pad8;
    void *fC;
    u32 pad10[6];
    void *f28;
    u32 pad2C[31];
    s32 fA8;
    s32 fAC;
    u32 padB0[36];
    struct Node *f140;
    struct Node *f144;
};

struct Tagged {
    void *f0;
};

struct Board {
    s32 f0;
    void *f4;
    u32 pad8[0x130 / 4 - 2];
    s32 f130[0xC0][8];
    struct Tagged *f1930;
    struct Node *f1934;
    struct Node *f1938;
};

extern void func_0014E500(void *, void *);

/* takes a node out of the board's slot list, drops the slot from the
 * placement grid and hands the node's buffers back to the allocator */
void func_00241600(struct Board *board, struct Node *node) {
    struct Tagged *tag;
    void *mgr;
    void *buf;

    if (node == 0) {
        return;
    }
    if (board->f4 == 0) {
        return;
    }
    if (node->f140 != 0) {
        node->f140->f144 = node->f144;
    } else {
        board->f1934 = node->f144;
        if (board->f1934 != 0) {
            board->f1934->f140 = 0;
        }
    }
    if (node->f144 != 0) {
        node->f144->f140 = node->f140;
    } else {
        board->f1938 = node->f140;
        if (board->f1938 != 0) {
            board->f1938->f144 = 0;
        }
    }
    tag = board->f1930;
    if (tag != 0) {
        if (node->f0 == tag->f0) {
            board->f1930 = 0;
        }
    }
    if (node->fAC >= 0) {
        board->f130[node->fA8][node->fAC] = 0;
    }
    mgr = board->f4;
    buf = node->f28;
    if (mgr != 0 && buf != 0) {
        func_0014E500(mgr, buf);
    }
    if (node->fC != 0) {
        func_0014E500(board->f4, node->fC);
    }
    if (node->f4 != 0) {
        func_0014E500(board->f4, node->f4);
    }
    func_0014E500(board->f4, node->f0);
}
