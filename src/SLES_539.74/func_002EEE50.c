// range: 0x2EEE50 0x2EEEA0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern f32 D_003DF3B8;

void func_002EEE50(char *arg0, f32 fparg0, f32 fparg1) {
    if (fparg0 < 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x174) = 0.5f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x174) = fparg0;
    }
    if (fparg1 < 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x178) = (f32) D_003DF3B8;
    } else {
        M2C_FIELD(arg0, f32 *, 0x178) = fparg1;
    }
}
