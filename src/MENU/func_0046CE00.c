// range: 0x46CE00 0x46CEB0
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
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_370E00(void *, s32, s32);                                           /* extern */
s32 func_3713C0();                                                           /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_0046CE00(struct Menu *menu, s32 arg1) {
    func_370E00(menu->f20, menu->f18->fA, 0);
    if (func_3713C0(menu, 1) != 0) {
        func_2D6A80(arg1, menu->f18->f12 + 0x2AF8, 0x18703, -0xE, 0x12, 0,
                    D_003DF744);
        func_2D6B20(arg1, menu->f18->f12 + 0x2AF8, 0x4A6, 0, 0);
    }
    return 1;
}
