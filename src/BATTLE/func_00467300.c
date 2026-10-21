// range: 0x467300 0x467320
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00467300(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    M2C_FIELD(arg0, f32 *, 0) = fparg0;
    M2C_FIELD(arg0, f32 *, 4) = fparg1;
    M2C_FIELD(arg0, f32 *, 8) = fparg2;
    M2C_FIELD(arg0, f32 *, 0xC) = fparg3;
    return arg0;
}
