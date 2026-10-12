// range: 0x167690 0x1676B0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00167690(char *arg0) {
    M2C_FIELD(arg0, s128 *, 0xF0) = (s128) M2C_FIELD(arg0, s128 *, 0x60);
    M2C_FIELD(arg0, s128 *, 0xE0) = (s128) M2C_FIELD(arg0, s128 *, 0x50);
}
