// range: 0x2179E0 0x217A70
// auto: m2c, verified byte-exact
#include "common.h"

void func_002179E0(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg0, s16 *, 8) + 1);
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s16 *, 0xA) + 1);
    M2C_FIELD(arg1, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0xC)) - 1);
    M2C_FIELD(arg1, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s16 *, 0xA) + 1);
    M2C_FIELD(arg1, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s16 *, 8) + 1);
    M2C_FIELD(arg1, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, s16 *, 0xA) + M2C_FIELD(arg0, s16 *, 0xE)) - 1);
    M2C_FIELD(arg1, s32 *, 0x18) = (s32) ((M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0xC)) - 1);
    M2C_FIELD(arg1, s32 *, 0x1C) = (s32) ((M2C_FIELD(arg0, s16 *, 0xA) + M2C_FIELD(arg0, s16 *, 0xE)) - 1);
}
