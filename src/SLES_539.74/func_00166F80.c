// range: 0x166F80 0x166F90
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00166F80(char *arg0, s128 *arg1) {
    M2C_FIELD(arg0, s128 *, 0x120) = (s128) *arg1;
}
