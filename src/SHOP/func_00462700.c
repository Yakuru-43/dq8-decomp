// range: 0x462700 0x462770
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00465260();                            /* extern */
M2C_UNK func_00465D20();                            /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_37D060(M2C_UNK);                       /* extern */

s32 func_00462700(s32 arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x17A3, 0, -1);
    func_2D38E0(arg1, 0x485, 0, -1);
    func_37D060(-1);
    func_00465D20();
    func_00465260();
    return 1;
}
