// range: 0x30C2B0 0x30C310
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0029C6D0(M2C_UNK *);                   /* extern */
M2C_UNK func_0030C310(M2C_UNK *, s32);              /* extern */
s32 func_00340B80(M2C_UNK *);                       /* extern */
M2C_UNK func_00356910(s32, s32);                    /* extern */

void func_0030C2B0(s32 arg0, void *arg1) {
    M2C_UNK sp3C;

    func_0029C6D0(&sp3C);
    func_0030C310(&sp3C, M2C_FIELD(arg1, s32 *, 0x158));
    func_00356910(arg0, func_00340B80(&sp3C));
}
