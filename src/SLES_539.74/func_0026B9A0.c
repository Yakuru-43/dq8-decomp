// range: 0x26B9A0 0x26B9D0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0026AE60(s32, s32);                    /* extern */

s32 func_0026B9A0(s32 arg0, s32 arg1, char **arg2) {
    char *temp_v0;

    temp_v0 = *arg2;
    func_0026AE60(M2C_FIELD(temp_v0, s32 *, 0x24), M2C_FIELD(temp_v0, s32 *, 0x20));
    return 1;
}
