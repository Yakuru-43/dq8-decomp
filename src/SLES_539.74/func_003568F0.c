// range: 0x3568F0 0x356910
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_003568F0(char *arg0, f32 fparg0) {
    M2C_FIELD(arg0, s8 *, 4) = 1;
    M2C_FIELD(arg0, f32 *, 0) = fparg0;
    return arg0;
}
