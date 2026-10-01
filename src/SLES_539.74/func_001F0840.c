// range: 0x1F0840 0x1F0860
// auto: m2c, verified byte-exact
#include "common.h"

void func_001F0840(void **arg0, void *arg1) {
    *arg0 = arg1;
    if (arg1 != NULL) {
        M2C_FIELD(arg1, void ***, 4) = arg0;
    }
}
