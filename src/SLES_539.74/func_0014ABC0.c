// range: 0x14ABC0 0x14AC00
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014ABC0(char *arg0, char *arg1) {
    char *temp_v1;

    M2C_FIELD(arg0, char **, 0x18) = arg1;
    temp_v1 = M2C_FIELD(arg0, char **, 0x18);
    if ((temp_v1 != NULL) && (M2C_FIELD(temp_v1, s32 *, 0xC) == 0)) {
        M2C_FIELD(temp_v1, s32 *, 0xC) = 1;
    }
    M2C_FIELD(arg0, s8 *, 0x2B) = 1;
    M2C_FIELD(arg0, s8 *, 0x29) = 1;
}
