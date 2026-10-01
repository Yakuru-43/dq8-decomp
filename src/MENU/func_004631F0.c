// range: 0x4631F0 0x463260
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_004632A0(s16, M2C_UNK);                /* extern */
s32 func_202530();                                  /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_3710B0(char *, M2C_UNK, s32);          /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                       /* extern */

s32 func_004631F0(char *arg0, M2C_UNK arg1) {
    func_3710B0(arg0, 1, func_202530() - 1);
    func_2D38E0(arg1, 0x4A6, 1, -1);
    func_37CEA0(1);
    func_004632A0(M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0x12), 1);
    return 1;
}
