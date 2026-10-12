// range: 0x276EF0 0x276F20
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00276EF0(char *arg0, char *arg1) {
    M2C_FIELD(arg0, s128 *, 0) = (s128) M2C_FIELD(arg1, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x20) = (s128) M2C_FIELD(arg1, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) M2C_FIELD(arg1, s128 *, 0x30);
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(arg1, s128 *, 0x40);
    return arg0;
}
