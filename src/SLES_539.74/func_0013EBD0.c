// range: 0x13EBD0 0x13EBF0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0013EBD0(char *arg0, s64 arg1) {
    char *temp_a2;

    temp_a2 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_a2, s64 *, 0) = arg1;
    M2C_FIELD(temp_a2, s64 *, 8) = 0x3B;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
