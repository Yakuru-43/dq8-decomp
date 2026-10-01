// range: 0x22B800 0x22B820
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0022B800(char **arg0, f32 fparg0) {
    char *temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, f32 *, 0x15FC) = fparg0;
    }
}
