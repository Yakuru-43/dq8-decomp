// range: 0x156D00 0x156EA0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013D2B0(char *);                      /* extern */

void func_00156D00(char *arg0, char *arg1) {
    char *temp_s0;

    temp_s0 = arg0 + 0x14;
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 0x1C) = (f32) M2C_FIELD(arg1, f32 *, 8);
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) M2C_FIELD(arg1, f32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(arg1, f32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg1, f32 *, 0x14);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(arg1, f32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x30) = (f32) M2C_FIELD(arg1, f32 *, 0x1C);
    M2C_FIELD(arg0, f32 *, 0x34) = (f32) M2C_FIELD(arg1, f32 *, 0x20);
    M2C_FIELD(arg0, f32 *, 0x38) = (f32) M2C_FIELD(arg1, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) M2C_FIELD(arg1, f32 *, 0x28);
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) M2C_FIELD(arg1, f32 *, 0x2C);
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(arg1, f32 *, 0x30);
    func_0013D2B0(arg0 + 0x130);
    M2C_FIELD(arg0, f32 *, 0x130) = (f32) (M2C_FIELD(temp_s0, f32 *, 0x14) / 2.0f);
    M2C_FIELD(arg0, f32 *, 0x144) = (f32) (-M2C_FIELD(temp_s0, f32 *, 0x18) / 2.0f);
    M2C_FIELD(arg0, f32 *, 0x158) = (f32) ((M2C_FIELD(temp_s0, f32 *, 8) - M2C_FIELD(temp_s0, f32 *, 4)) / 2.0f);
    M2C_FIELD(arg0, f32 *, 0x168) = (f32) ((M2C_FIELD(temp_s0, f32 *, 4) + M2C_FIELD(temp_s0, f32 *, 8)) / 2.0f);
    M2C_FIELD(arg0, f32 *, 0x160) = (f32) M2C_FIELD(temp_s0, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0x164) = (f32) M2C_FIELD(temp_s0, f32 *, 0x28);
    M2C_FIELD(arg0, f32 *, 0x240) = (f32) (M2C_FIELD(temp_s0, f32 *, 0x14) / (M2C_FIELD(temp_s0, f32 *, 0x1C) - 8.0f));
    M2C_FIELD(arg0, f32 *, 0x244) = (f32) (M2C_FIELD(temp_s0, f32 *, 0x18) / (M2C_FIELD(temp_s0, f32 *, 0x20) - 8.0f));
    M2C_FIELD(arg0, f32 *, 0x248) = (f32) (1.0f / M2C_FIELD(arg0, f32 *, 0x240));
    M2C_FIELD(arg0, f32 *, 0x24C) = (f32) (1.0f / M2C_FIELD(arg0, f32 *, 0x244));
    M2C_FIELD(arg0, f32 *, 0x4D0) = (f32) (1.0f / M2C_FIELD(arg0, f32 *, 0x130));
    M2C_FIELD(arg0, f32 *, 0x4D4) = (f32) (1.0f / M2C_FIELD(arg0, f32 *, 0x144));
    M2C_FIELD(arg0, f32 *, 0x4D8) = (f32) (1.0f / M2C_FIELD(arg0, f32 *, 0x158));
    M2C_FIELD(arg0, f32 *, 0x4E0) = (f32) -M2C_FIELD(arg0, f32 *, 0x160);
    M2C_FIELD(arg0, f32 *, 0x4E4) = (f32) -M2C_FIELD(arg0, f32 *, 0x164);
    M2C_FIELD(arg0, f32 *, 0x4E8) = (f32) -M2C_FIELD(arg0, f32 *, 0x168);
}
