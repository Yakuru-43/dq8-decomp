// range: 0x15DD80 0x15DDA0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern char *D_003E0298;

void func_0015DD80(s128 *arg0) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(D_003E0298, char **, 0x36B0);
    if (temp_v1 != NULL) {
        *arg0 = M2C_FIELD(temp_v1, s128 *, 0x10);
    }
}
