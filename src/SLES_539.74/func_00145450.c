// range: 0x145450 0x145460
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00145450(char *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, char **, 0x270), s32 *, 4);
}
