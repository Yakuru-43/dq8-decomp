// range: 0x463700 0x463790
#include "common.h"

M2C_UNK func_3766A0(void *, s32, s32);            /* extern */
M2C_UNK func_376780(void *, s32, s8);             /* extern */
M2C_UNK func_3768A0(void *);                      /* extern */
M2C_UNK func_3793B0(s32, s32, s32, s32);          /* extern */
M2C_UNK func_3794C0(s32, void *, s32);            /* extern */

extern s8 D_003E19A8 __attribute__((section(".sdata")));
extern u8 D_003E19B0 __attribute__((section(".sdata")));

typedef struct {
    u128 q[22];
} ShopWindow;

void func_00463700(s32 arg0, s32 arg1) {
    ShopWindow buf;

    func_3768A0(&buf);
    func_376780(&buf, 0, D_003E19A8);
    func_3766A0(&buf, *(u16 *)0x415E98 + 0x15, 1);
    func_3794C0(0, &buf, 0);
    func_3793B0(arg0, arg1, 0, 0x17A3);
    D_003E19B0 = 0;
}
