// range: 0x13EFF0 0x13F010
#include "common.h"

void func_0013EFF0(char *arg0, u128 *arg1) {
    u128 temp_a2;
    char *temp_a1;

    temp_a2 = *arg1;
    temp_a1 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (temp_a1 + 0x10);
    M2C_FIELD(temp_a1, u128 *, 0) = temp_a2;
}
