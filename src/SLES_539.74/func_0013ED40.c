// range: 0x13ED40 0x13EDA0
#include "common.h"

void func_0013ED40(char *arg0, s32 *arg1) {
    char *temp_t2;

    temp_t2 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_t2, s64 *, 0) =
        (s64) arg1[2] << 32 |
        ((s64) (arg1[0] + M2C_FIELD(arg0, s32 *, 0x120)) |
         ((s64) (arg1[1] + M2C_FIELD(arg0, s32 *, 0x124)) << 16));
    M2C_FIELD(temp_t2, s64 *, 8) = 0xD;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
