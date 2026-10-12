// range: 0x15DDA0 0x15DDC0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern char *D_003E0298;

void func_0015DDA0(s128 *arg0) {
    char *temp_a1;

    temp_a1 = M2C_FIELD(D_003E0298, char **, 0x36B0);
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_a1, s128 *, 0x10) = (s128) *arg0;
    }
}
