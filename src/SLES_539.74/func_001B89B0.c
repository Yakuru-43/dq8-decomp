// range: 0x1B89B0 0x1B89E0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0016AF30(char *, s32);                   /* extern */
extern char *D_003E0664;

s32 func_001B89B0(void) {
    M2C_FIELD(func_0016AF30(D_003E0664, M2C_FIELD(D_003E0664, s32 *, 0x44B4)), s128 *, 0x200) = 0;
    return 1;
}
