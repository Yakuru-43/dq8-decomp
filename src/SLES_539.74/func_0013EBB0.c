// range: 0x13EBB0 0x13EBD0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0013EBB0(char *arg0, s64 arg1, s64 arg2) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_v1, s64 *, 0) = arg2;
    M2C_FIELD(temp_v1, s64 *, 8) = arg1;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
