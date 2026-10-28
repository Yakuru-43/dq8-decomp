// range: 0x145360 0x145390
#include "common.h"

s32 func_00145360(char *arg0) {
    char *temp_a0;
    s32 temp_v0;

    temp_a0 = M2C_FIELD(arg0, char **, 0x270);
    temp_v0 = M2C_FIELD(temp_a0, s32 *, 4);
    return M2C_FIELD(temp_a0, s32 *, 0xC) - temp_v0 / 2;
}
