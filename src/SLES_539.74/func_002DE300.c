// range: 0x2DE300 0x2DE350
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002DE490(char *, s32);
s32 func_002DE300(char *arg0) {
    if (func_002DE490(arg0, 4) == 0) {
        if (func_002DE490(arg0, 0x16) == 0) {
            return 0;
        }
        goto block_3;
    }
block_3:
    return M2C_FIELD(arg0, s32 *, 0x2C);
}
