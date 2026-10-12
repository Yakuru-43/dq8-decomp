// range: 0x14D380 0x14D3A0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014D380(char **arg0, s128 *arg1) {
    char *temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 != NULL) {
        *arg1 = M2C_FIELD(temp_v1, s128 *, 0x30);
    }
}
