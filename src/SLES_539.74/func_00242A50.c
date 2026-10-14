// range: 0x242A50 0x242B70
#include "common.h"

struct Board {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C[4];
    s32 f2C[64];
    s32 f12C;
    s32 f130[0xC0][8];
    s32 f1930;
    s32 f1934;
    s32 f1938;
};

extern s32 D_003E0B1C;

extern void func_00239080(void);
extern s32 func_0015F450(void);
extern void func_00159630(s32 arg0, s32 arg1);

/* clears the board, remembers the caller's request, then hands every slot of
 * the requested range to the deal routine */
void func_00242A50(struct Board *board, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 deal;
    s32 col;
    s32 row;
    s32 index;
    s32 slot;

    board->f0 = arg1;
    board->f8 = 0;
    board->f4 = 0;
    board->fC = 0;
    for (index = 0; index < 64; index = index + 1) {
        board->f2C[index] = 0;
    }
    board->f12C = 0;
    for (row = 0; row < 0xC0; row = row + 1) {
        for (col = 0; col < 8; col = col + 1) {
            board->f130[row][col] = 0;
        }
    }
    board->f1930 = 0;
    board->f10 = arg2;
    board->f14 = arg3;
    board->f18 = 0;
    board->f1938 = 0;
    board->f1934 = 0;
    D_003E0B1C = arg4;
    func_00239080();
    for (index = 0; index < 4; index = index + 1) {
        board->f1C[index] = 0;
    }
    deal = func_0015F450();
    slot = board->f10;
    while (slot < board->f10 + board->f14) {
        func_00159630(deal, slot);
        slot = slot + 1;
    }
}
