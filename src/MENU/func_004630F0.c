// range: 0x4630F0 0x463160
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                       /* extern */
M2C_UNK func_37EA60(M2C_UNK);                       /* extern */
extern M2C_UNK D_00478FA8 __attribute__((section(".data")));

s32 func_004630F0(s32 arg0, M2C_UNK arg1) {
    func_37EA60(-1);
    func_2D38E0(arg1, 0x4A6, 0, -1);
    func_37CEA0(0);
    func_370C00(func_201CD0(), &D_00478FA8, 0);
    return 1;
}
