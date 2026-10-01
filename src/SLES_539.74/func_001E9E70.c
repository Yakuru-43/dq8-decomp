// range: 0x1E9E70 0x1E9EC0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0013E090(void *);                      /* extern */

void func_001E9E70(void *arg0, void *arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x30) != 0) {
        func_0013E090(arg1);
        return;
    }
    M2C_FIELD(arg1, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0x18);
    M2C_FIELD(arg1, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0x1C);
    M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x20);
    M2C_FIELD(arg1, s32 *, 0xC) = 0;
}
