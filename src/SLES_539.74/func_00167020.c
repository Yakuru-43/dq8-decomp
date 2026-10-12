// range: 0x167020 0x167040
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00167020(char *arg0, s128 *arg1) {
    M2C_FIELD(arg0, s128 *, 0xF0) = (s128) *arg1;
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) *arg1;
}
