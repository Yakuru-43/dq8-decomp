// range: 0x46A950 0x46AA70
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

typedef struct {
    u128 pad0;
    char pad10[0x14B];
    s8 unk15B;
    char pad15C[4];
} MenuWindow;

s32 func_202530(void);                                   /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_3715B0(void *);                                 /* extern */
M2C_UNK func_3766A0(void *, s32, s32);                    /* extern */
M2C_UNK func_3768A0(void *);                              /* extern */
M2C_UNK func_379760(void *, M2C_UNK *, s32, s32, s32);    /* extern */
void func_37CEE0(s32);                                    /* extern */
M2C_UNK func_37CF20(M2C_UNK);                             /* extern */
s32 func_0046AA70(void);                                  /* extern */
extern M2C_UNK D_00479350 __attribute__((section(".data")));
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_0046A950(struct Menu *menu, s32 arg1) {
    MenuWindow buf;
    s32 count;
    s32 r;

    count = func_202530();
    if (count < 2) {
        func_2D38E0(arg1, 0x18703, 0, -1);
        func_3768A0(&buf);
        func_3766A0(&buf, 0x3E9, 0);
        func_379760(&buf, &D_00479350, 0, 0, 1);
    } else {
        func_2D6A80(arg1, func_3715B0(menu->f18) + 0x2AF8, 0x18703, -0xE, 0x12,
                    0, D_003DF744);
        r = func_0046AA70();
        if (r == 4) {
            func_37CF20(5);
        } else {
            func_37CF20(func_0046AA70());
        }
        func_37CEE0(1);
        menu->f18->fA = count - 1;
    }
    return 1;
}
