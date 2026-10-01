// range: 0x15DED0 0x15DF10
// auto: m2c draft, verified byte-exact
#include "common.h"

extern char *D_003E0298;

void func_0015DED0(s8 arg0, s8 arg1, s8 arg2, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(D_003E0298, char **, 0x36B4);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, f32 *, 0) = fparg0;
        M2C_FIELD(temp_v1, f32 *, 4) = fparg1;
        M2C_FIELD(temp_v1, s8 *, 8) = arg0;
        M2C_FIELD(temp_v1, s8 *, 9) = arg1;
        M2C_FIELD(temp_v1, s8 *, 0xA) = arg2;
        M2C_FIELD(temp_v1, f32 *, 0x14) = fparg2;
        M2C_FIELD(temp_v1, f32 *, 0x18) = fparg3;
    }
}
