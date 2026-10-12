// range: 0x2BE180 0x2BE1B0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002BE180(char *arg0, char *arg1) {
    M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x60);
    M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
    M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x80);
    M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x90);
}
