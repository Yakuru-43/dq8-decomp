// range: 0x18A640 0x18A670
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0018A640(char *arg0, s32 arg1, char *arg2, f32 fparg0) {
    M2C_FIELD(arg0, s8 *, 0x68B4) = 1;
    M2C_FIELD(arg0, f32 *, 0x68BC) = fparg0;
    M2C_FIELD(arg0, s32 *, 0x68B8) = arg1;
    M2C_FIELD(arg0, f32 *, 0x68C0) = (f32) M2C_FIELD(arg2, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0x68C4) = (f32) M2C_FIELD(arg2, f32 *, 4);
}
