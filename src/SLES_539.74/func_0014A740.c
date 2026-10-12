// range: 0x14A740 0x14A770
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014A740(char *arg0, char *arg1) {
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(arg1, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x70) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(arg1, s128 *, 0x20);
    M2C_FIELD(arg0, s8 *, 0x29) = 1;
}
