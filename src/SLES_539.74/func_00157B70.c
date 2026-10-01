// range: 0x157B70 0x157B80
// auto: m2c, verified byte-exact
#include "common.h"

void func_00157B70(void *arg0, s64 *arg1) {
    M2C_FIELD(arg0, s64 *, 0x10) = (s64) *arg1;
}
