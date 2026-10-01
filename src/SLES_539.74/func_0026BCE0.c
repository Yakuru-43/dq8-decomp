// range: 0x26BCE0 0x26BD00
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0026BCE0(s32 arg0, s32 arg1, char **arg2) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(*arg2, char **, 0x2C);
    if (temp_v1 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_v1, s8 *, 0x68) = 1;
    return 1;
}
