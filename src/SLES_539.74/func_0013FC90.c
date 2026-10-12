// range: 0x13FC90 0x13FCB0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0013FC90(char *arg0, s128 *arg1) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(arg0, char **, 0xF20);
    if (temp_v1 != NULL) {
        *arg1 = M2C_FIELD(temp_v1, s128 *, 0x170);
    }
}
