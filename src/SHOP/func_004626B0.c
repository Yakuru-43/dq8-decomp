// range: 0x4626B0 0x462740
#include "common.h"

s32 func_2D34C0();                                        /* extern */
M2C_UNK func_3766A0(void *, s32, s32);                    /* extern */
M2C_UNK func_3768A0(void *);                              /* extern */
s32 func_2D3700(s32, s32);                                /* extern */
M2C_UNK func_3795E0();                                    /* extern */
M2C_UNK func_379760(void *, M2C_UNK *, s32, s32, s32);    /* extern */
void func_00461680();                                     /* extern */

extern M2C_UNK D_004736C0 __attribute__((section(".data")));

typedef struct {
    u128 pad0;
    char pad10[0x14B];
    s8 unk15B;
    char pad15C[4];
} ShopWindow;

void func_004626B0(void) {
    s32 temp_s0;
    ShopWindow buf;

    temp_s0 = func_2D34C0();
    func_3768A0(&buf);
    func_3766A0(&buf, *(u16 *)0x415E98 + 0x34, 0);
    if (func_2D3700(temp_s0, 0x2745) != 0) {
        func_00461680(&buf);
    }
    func_379760(&buf, &D_004736C0, 0, 0, 1);
    func_3795E0();
}
