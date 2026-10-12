// range: 0x1E9F20 0x1E9F50
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001E9F20(char *arg0, char *arg1) {

    if (!(M2C_FIELD(arg0, s16 *, 0x30) == 0)) {
        return;
    }

    M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) M2C_FIELD(arg1, f32 *, 8);
}
