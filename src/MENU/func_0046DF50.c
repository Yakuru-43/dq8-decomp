// range: 0x46DF50 0x46DFE0
#include "common.h"

struct Entry {
    char pad[0xA];
    s16 fA;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
    char pad2[4];
    void *f20;
};

M2C_UNK func_0046E370(s32);                                                    /* extern */
M2C_UNK func_2D6710(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK,
                    M2C_UNK, f32);                                            /* extern */
s32 func_370E00(void *, s32, s32);                                             /* extern */
s32 func_3715D0(struct Entry *);                                               /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_0046DF50(struct Menu *menu, s32 arg1) {
    func_370E00(menu->f20, menu->f18->fA, 0);
    func_2D6710(arg1, 0x4B2, func_3715D0(menu->f18), 0x18703, -0x38, -2, 0,
                D_003DF744);
    func_0046E370(func_3715D0(menu->f18));
    return 1;
}
