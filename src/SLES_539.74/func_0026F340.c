// range: 0x26F340 0x26F370
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */

s32 func_0026F340(s32 arg0, s32 arg1, char **arg2) {
    char *temp_s0;

    temp_s0 = *arg2;
    M2C_FIELD(M2C_FIELD(temp_s0, char **, 0x24), s32 *, 0x78) = func_001667C0();
    return 1;
}
