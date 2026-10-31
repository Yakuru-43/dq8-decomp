// range: 0x466790 0x466830
#include "common.h"

s32 func_1814D0();                                        /* extern */
M2C_UNK func_308030(s32);                                 /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);             /* extern */
M2C_UNK func_3766A0(void *, s32, s32);                    /* extern */
M2C_UNK func_3768A0(void *);                              /* extern */
M2C_UNK func_3795E0();                                    /* extern */
M2C_UNK func_3795F0(s32);                                 /* extern */
M2C_UNK func_379760(void *, M2C_UNK *, s32, void (*)(void), s32); /* extern */
void func_004680F0(void);

extern s32 D_003E0A38 __attribute__((section(".data")));
extern M2C_UNK D_00473840 __attribute__((section(".data")));

typedef struct {
    u128 pad0;
    char pad10[0x14B];
    s8 unk15B;
    char pad15C[4];
} ShopWindow;

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

void func_00466790(S_arg0 *arg0) {
    ShopWindow buf;

    func_3768A0(&buf);
    if (func_308030(func_1814D0()) < D_003E0A38) {
        func_3766A0(&buf, 0x3323, 1);
        func_379760(&buf, 0, 1, func_004680F0, 1);
        func_3795F0(0xFFFF);
        func_3795E0();
    } else {
        func_370C00(arg0->unk20, &D_00473840, 1);
    }
}
