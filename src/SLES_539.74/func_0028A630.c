// range: 0x28A630 0x28A660
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00166700(char *, s32);                 /* extern */
extern char *D_003E0E10;

s32 func_0028A630(s32 arg0) {
    func_00166700(D_003E0E10 + 0x100, arg0);
    M2C_FIELD(D_003E0E10, s32 *, 0x10C) = 0;
    return 1;
}
