// range: 0x2186F0 0x218710
// auto: m2c, verified byte-exact
#include "common.h"

void func_002186F0(void **arg0, void *arg1) {
    *arg0 = arg1;
    if (arg1 != NULL) {
        M2C_FIELD(arg1, void ***, 4) = arg0;
    }
}
