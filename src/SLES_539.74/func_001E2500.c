// range: 0x1E2500 0x1E2520
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001E2500(char *arg0, char *arg1) {
    M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x10);
    M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
}
