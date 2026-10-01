// range: 0x1EA120 0x1EA1D0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001525C0();                            /* extern */
M2C_UNK func_001E7290();        /* extern */

void func_001EA120(char *arg0, char *arg1, M2C_UNK arg2) {
    func_001525C0();
    M2C_FIELD(arg1, s32 *, 0x1C0) = (s32) M2C_FIELD(arg0, s32 *, 0x1C0);
    M2C_FIELD(arg0, s32 *, 0x1C4) = 0xBF800000;
    M2C_FIELD(arg1, s32 *, 0x1C8) = (s32) M2C_FIELD(arg0, s32 *, 0x1C8);
    M2C_FIELD(arg1, s32 *, 0x1CC) = (s32) M2C_FIELD(arg0, s32 *, 0x1CC);
    M2C_FIELD(arg1, s32 *, 0x1D0) = (s32) M2C_FIELD(arg0, s32 *, 0x1D0);
    M2C_FIELD(arg1, f32 *, 0x1D4) = (f32) M2C_FIELD(arg0, f32 *, 0x1D4);
    M2C_FIELD(arg1, f32 *, 0x1D8) = (f32) M2C_FIELD(arg0, f32 *, 0x1D8);
    M2C_FIELD(arg1, s32 *, 0x1DC) = (s32) M2C_FIELD(arg0, s32 *, 0x1DC);
    M2C_FIELD(arg1, f32 *, 0x1E0) = (f32) M2C_FIELD(arg0, f32 *, 0x1E0);
    M2C_FIELD(arg1, f32 *, 0x1E4) = (f32) M2C_FIELD(arg0, f32 *, 0x1E4);
    M2C_FIELD(arg1, f32 *, 0x1E8) = (f32) M2C_FIELD(arg0, f32 *, 0x1E8);
    func_001E7290(arg0 + 0x1F0, arg1 + 0x1F0, arg2);
}
