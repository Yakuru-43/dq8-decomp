// range: 0x468290 0x4683A0
// flags: -flag divbyzerocheck
#include "common.h"

M2C_UNK func_2D38E0(void *, s32, s32, s32);                                 /* extern */
void func_2D4EB0(void *, s32, s32, s32, s32);                               /* extern */
M2C_UNK func_2D5F70(void *, s32, s32, s32, s32);                             /* extern */
M2C_UNK func_2D6A80(void *, s32, s32, s32, s32, s32, f32);                   /* extern */
M2C_UNK func_2D6B20(void *, s32, s32, s32, s32);                             /* extern */
void *func_2D34C0(void);                                                     /* extern */

extern s8 D_003E1B04 __attribute__((section(".sdata")));

void func_00468290(s32 arg0, s32 arg1, s32 arg2) {
    void *win;
    s32 q;
    s32 r;

    win = func_2D34C0();
    func_2D4EB0(win, 0x4AA, 0, arg1, 1);
    q = arg0 / 3;
    r = arg0 % 3;
    func_2D6B20(win, 0x588, 0x4AA, q * 0x30, r * 0x30);
    func_2D38E0(win, 0x4AA, 1, -1);
    func_2D5F70(win, 0x4AA, 0, 0x26, 0x26);
    func_2D6A80(win, 0x594, 0x4AA, arg2 * 0x2E, 0, 0, 0.5f);
    D_003E1B04 = 1;
}
