// range: 0x460C50 0x460C70
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00460C50(char *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    M2C_FIELD(arg0, s32 *, 0x231C) = arg1;

    if (!(arg1 != 0)) {
        return;
    }

    M2C_FIELD(arg0, f32 *, 0x2320) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x2324) = fparg1;
    M2C_FIELD(arg0, s32 *, 0x2328) = arg2;
    M2C_FIELD(arg0, s32 *, 0x232C) = arg3;
}
