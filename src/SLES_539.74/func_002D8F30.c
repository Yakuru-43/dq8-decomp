// range: 0x2D8F30 0x2D8F40
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002D8F30(char *arg0, s128 *arg1) {
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) *arg1;
}
