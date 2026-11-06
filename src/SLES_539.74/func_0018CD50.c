// range: 0x18CD50 0x18CDE0
#include "common.h"

void func_0018CD50(char *arg0, s32 arg1) {
    s32 i;
    char *slot;

    i = 0;
    do {
        if ((0 > arg1) || (i == arg1)) {
            slot = arg0 + (i * 0x18);
            M2C_FIELD(slot, f32 *, 0x53B0) = 6.0f;
            M2C_FIELD(slot, f32 *, 0x53B4) = 9.0f;
            M2C_FIELD(slot, f32 *, 0x53B8) = 17.0f;
            M2C_FIELD(slot, f32 *, 0x53BC) = 19.0f;
            M2C_FIELD(slot, f32 *, 0x53C0) = 1.0f;
            M2C_FIELD(slot, u8 *, 0x53C4) = 0;
        }
    } while (++i < 2);

    if (arg1 == -1) {
        M2C_FIELD(arg0, s32 *, 0x53AC) = 0;
    }
}
