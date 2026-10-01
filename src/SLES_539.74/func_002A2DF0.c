// range: 0x2A2DF0 0x2A2E70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0029D180(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_003014F0(M2C_UNK *);                   /* extern */
s32 func_00302740(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_00302850(M2C_UNK *);                       /* extern */
M2C_UNK func_00302AC0(M2C_UNK *, s32, s32);         /* extern */
s32 func_00302BC0();                                /* extern */
extern s32 D_003E0EBC;
extern M2C_UNK D_00421410 __attribute__((section(".data")));
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

void func_002A2DF0(s32 arg0) {
    s32 temp_a2;
    s32 temp_s0;

    temp_a2 = func_00302BC0();
    D_003E0EBC = arg0;
    func_00302AC0(&D_00421410, arg0, temp_a2);
    func_003014F0(&D_00421410);
    temp_s0 = func_00302740(&D_00421410, 0);
    func_0029D180(&D_0042CDB0, temp_s0, func_00302850(&D_00421410));
}
