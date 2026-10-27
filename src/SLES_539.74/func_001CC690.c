// range: 0x1CC690 0x1CC6F0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_0022F500(void);
s32 func_001CC690(char *arg0) {
    s32 temp_a0;

    if (func_0022F500() == 0) {
        return 0;
    }
    temp_a0 = *(s32 *) func_0022F500();
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, char **, 4), s32 *, 4) = temp_a0;
    }
    return 1;
}
