// range: 0x46A3F0 0x46A520
#include "common.h"

extern s32 func_15F450(s32);
extern s32 func_15AEF0(s32, void *, s32);
extern M2C_UNK D_0047E760 __attribute__((section(".data")));
extern u32 D_003E17B0 __attribute__((section(".sdata")));

/* paints the arg0-th card cell of the 2 x 5 casino grid with a fixed tile byte */
s32 func_0046A3F0(s32 arg0) {
    s32 obj;
    s32 cell;
    s32 tile;
    s32 row;
    s32 col;
    s32 i0;
    s32 i1;
    s32 j0;
    s32 j1;
    s32 i;
    s32 j;
    u8 *src;
    u8 *dst;
    s32 base;

    obj = func_15F450(arg0);
    cell = func_15AEF0(obj, &D_0047E760, -1);
    tile = func_15AEF0(obj, &D_0047E760, -1);
    dst = *(u8 **)(tile + 0x50);
    base = *(s32 *)(cell + 0x50);
    if (arg0 <= 4) {
        row = 0;
        col = arg0;
    } else {
        row = 1;
        col = arg0 - 5;
    }
    src = (u8 *)(base + 0x27B95 +
                 (*(s32 *)(D_003E17B0 + arg0 * 0x40 + 0x20) % 5) * 0x10);
    i0 = col * 0x30 + 9;
    i1 = i0 + 0x30;
    j0 = row * 0x30 + 9;
    j1 = j0 + 0x30;
    i = i0;
    if (i < i1) {
        do {
            j = j0;
            if (j < j1) {
                do {
                    dst[j + *(s16 *)(tile + 2) * (*(s16 *)(tile + 4) - i)] =
                        *src;
                } while (++j < j1);
            }
        } while (++i < i1);
    }
    return 1;
}
