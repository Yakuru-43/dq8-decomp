// range: 0x1E9EF0 0x1E9F20
#include "common.h"

void func_001E9EF0(char *arg0, char *arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x30) != 0) {
        M2C_FIELD(arg1, s128 *, 0) = 0;
        return;
    }
    M2C_FIELD(arg1, f32 *, 0) = M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(arg1, f32 *, 4) = M2C_FIELD(arg0, f32 *, 0x10);
    M2C_FIELD(arg1, f32 *, 8) = M2C_FIELD(arg0, f32 *, 0x14);
    M2C_FIELD(arg1, s32 *, 0xC) = 0;
}
