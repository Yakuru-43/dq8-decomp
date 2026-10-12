// range: 0x166830 0x166840
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00166830(char *arg0, s128 *arg1) {
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) *arg1;
}
