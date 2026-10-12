// range: 0x1EDD70 0x1EDD90
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_001EDD70(char *arg0, char *arg1) {
    M2C_FIELD(arg0, s128 *, 0) = (s128) M2C_FIELD(arg1, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    return arg0;
}
