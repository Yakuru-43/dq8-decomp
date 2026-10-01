// range: 0x14EFF0 0x14F060
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013E180(char *, char *);              /* extern */
M2C_UNK func_0014A770(char *, char *);              /* extern */
M2C_UNK func_0014AE60(char *, s32);                 /* extern */
s32 func_0014D600(s32, M2C_UNK);                    /* extern */

void func_0014EFF0(char *arg0, char *arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s32 *, 0) = func_0014D600(M2C_FIELD(arg1, s32 *, 0), arg2);
    func_0014A770(arg0, arg1 + 0x20);
    func_0013E180(arg0 + 0x30, arg1 + 0x20);
    M2C_FIELD(arg0, s8 *, 0x2C) = 1;
    M2C_FIELD(arg0, u8 *, 0x24) = (u8) M2C_FIELD(arg1, u8 *, 0x1F);
    func_0014AE60(arg0, M2C_FIELD(arg1, s32 *, 0x14));
}
