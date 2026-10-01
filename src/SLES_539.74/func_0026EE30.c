// range: 0x26EE30 0x26EE50
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0026EE30(s32 arg0, s32 arg1, char **arg2) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(*arg2, char **, 0x28);
    if (temp_v1 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_v1, s32 *, 0x38) = 1;
    return 1;
}
