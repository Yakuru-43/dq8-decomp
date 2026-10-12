// range: 0x148110 0x148140
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00148110(char *arg0, char *arg1) {
    M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x3A20);
    M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x3A30);
    M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x3A40);
    M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x3A50);
}
