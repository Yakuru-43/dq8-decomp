// range: 0x1FB380 0x1FB390
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001FB380(char *arg0, f32 fparg0, f32 fparg1) {
    M2C_FIELD(arg0, f32 *, 0x84) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x88) = fparg1;
}
