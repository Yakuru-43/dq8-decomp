// range: 0x1676B0 0x1676D0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001676B0(char *arg0) {
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(arg0, s128 *, 0xF0);
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(arg0, s128 *, 0xE0);
}
