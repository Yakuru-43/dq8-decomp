// range: 0x2A2EC0 0x2A2F80
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0014E030(M2C_UNK);                     /* extern */
M2C_UNK func_003026A0(M2C_UNK *);                   /* extern */
M2C_UNK func_00302890(M2C_UNK *, s32, M2C_UNK, s32); /* extern */
M2C_UNK func_00302B00(M2C_UNK *);                   /* extern */
M2C_UNK func_00356E50(s32, M2C_UNK);                /* extern */
M2C_UNK func_467860(M2C_UNK);                       /* extern */
M2C_UNK func_4678A0(s32);                           /* extern */
extern s32 D_003DFF1C;
extern s32 D_003E0EC0;
extern M2C_UNK D_00421410 __attribute__((section(".data")));
extern M2C_UNK D_00421450 __attribute__((section(".data")));

void func_002A2EC0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_00302B00(&D_00421410);

    if (!(arg1 != 0)) {
        return;
    }

    func_0014E030(arg2);
    D_003DFF1C = -1;
    func_00131188(&D_00421450, 0, 0x2C);
    D_003E0EC0 = -1;
    func_003026A0(&D_00421410);
    func_00302890(&D_00421410, arg1, arg2, arg0);
    func_0014E030(arg2);
    func_467860(arg2);
    func_4678A0(arg1);
    func_00356E50(arg1, arg2);
}
