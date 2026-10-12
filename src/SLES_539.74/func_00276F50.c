// range: 0x276F50 0x276F80
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00276F50(char *arg0, char *arg1) {
    M2C_FIELD(arg0, s128 *, 0) = (s128) M2C_FIELD(arg1, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x20) = (s128) M2C_FIELD(arg1, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) M2C_FIELD(arg1, s128 *, 0x30);
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(arg1, s128 *, 0x40);
    return arg0;
}
