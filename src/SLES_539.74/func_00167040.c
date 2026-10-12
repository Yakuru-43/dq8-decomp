// range: 0x167040 0x167060
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00167040(char *arg0, s128 *arg1) {
    M2C_FIELD(arg0, s128 *, 0xE0) = (s128) *arg1;
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) *arg1;
}
