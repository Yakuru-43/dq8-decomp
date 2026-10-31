// range: 0x46A8A0 0x46A950
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

M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_370E00(void *, s32, s32);                                           /* extern */
s32 func_3715B0(void *);                                                     /* extern */
s32 func_0046AA70(void);                                                     /* extern */
M2C_UNK func_37CF20(M2C_UNK);                                                /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_0046A8A0(struct Menu *menu, s32 arg1) {
    s32 r;

    func_370E00(menu->f20, menu->f18->fA, 0);
    func_2D6A80(arg1, func_3715B0(menu->f18) + 0x2AF8, 0x18703, -0xE, 0x12, 0,
                D_003DF744);
    r = func_0046AA70();
    if (r == 4) {
        func_37CF20(5);
    } else {
        func_37CF20(func_0046AA70());
    }
    return 1;
}
