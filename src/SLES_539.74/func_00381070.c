// range: 0x381070 0x3810E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00220F00(s32, M2C_UNK);                /* extern */
M2C_UNK func_00225D70(s32, M2C_UNK);                /* extern */
M2C_UNK func_0036D380(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK D_0042D390 __attribute__((section(".data")));
extern s8 D_004590A0 __attribute__((section(".data")));
extern s8 D_004590BA __attribute__((section(".data")));
extern s32 D_004590BC __attribute__((section(".data")));
extern s32 D_004590C8 __attribute__((section(".data")));

void func_00381070(void) {
    func_0036D380(&D_0042D390, 0);
    D_004590A0 = 2;
    func_00225D70(D_004590BC, 1);
    func_00220F00(D_004590BC, 1);
    func_00225D70(D_004590C8, 1);
    D_004590BA = 1;
}
