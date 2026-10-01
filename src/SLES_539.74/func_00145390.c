// range: 0x145390 0x1453A0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00145390(char *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, char **, 0x270), s32 *, 0x10);
}
