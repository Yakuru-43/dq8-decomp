// CLASS reorder+register score=4 (4 words differ, 168 vs 168 bytes) — best attempt, 2026-11-05 factory-6
// range: 0x46CEB0 0x46CF60
#include "common.h"

struct Entry {
    char pad[0xA];
    s16 fA;
    char pad2[6];
    s16 f12;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
    char pad2[4];
    void *f20;
};

M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);               /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);                    /* extern */
s32 func_202530(void);                                                       /* extern */
void func_37CEA0(s32);                                                       /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_0046CEB0(struct Menu *menu, s32 arg1) {
    s32 n = func_202530();
    f32 scale = D_003DF744;

    menu->f18->fA = n - 1;
    func_2D6A80(arg1, menu->f18->f12 + 0x2AF8, 0x18703, -0xE, scale, 0x12, 0);
    func_2D38E0(arg1, 0x4A6, 1, -1);
    func_2D6B20(arg1, menu->f18->f12 + 0x2AF8, 0x4A6, 0, 0);
    func_37CEA0(1);
    return 1;
}
