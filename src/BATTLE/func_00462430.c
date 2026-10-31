// range: 0x462430 0x462530
#include "common.h"

M2C_UNK func_13EBF0();                                   /* extern */
M2C_UNK func_13EE00();                                   /* extern */

typedef struct {
    s16 x;
    s16 y;
} GlyphOfs;

typedef struct {
    s32 x;
    s32 y;
} BattlePos;

extern GlyphOfs D_00482B30[];

void func_00462430(void *win, s32 idx, s32 count, BattlePos *origin, s32 row,
                   s32 dx, s32 dy) {
    GlyphOfs *ofs = &D_00482B30[idx];
    s32 x = ofs->x + count * 22;

    func_13EBF0(win, x, ofs->y);
    func_13EE00(win, origin->x + row * 16 - dx, origin->y + 0xE0 - dy, 0);
    func_13EBF0(win, x + 0x15, ofs->y + 0x22);
    func_13EE00(win, dx + (origin->x + (row + 0x10) * 16),
                dy + (origin->y + 0x260), 0);
}
