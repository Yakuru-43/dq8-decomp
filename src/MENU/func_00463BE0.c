// range: 0x463BE0 0x463C40
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00464360();                            /* extern */
M2C_UNK func_22A920(M2C_UNK);                       /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_37AD10();                                  /* extern */
M2C_UNK func_37AD80(M2C_UNK);                       /* extern */
M2C_UNK func_37E170(s32, M2C_UNK);                  /* extern */

s32 func_00463BE0(s32 arg0, M2C_UNK arg1) {
    func_00464360();
    func_37E170(func_37AD10(), 0);
    func_22A920(0);
    func_2D38E0(arg1, 0x485, 0, -1);
    func_37AD80(0);
    return 1;
}
