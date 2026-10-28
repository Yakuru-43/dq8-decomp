// range: 0x28EDF0 0x28EE90
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00167550(char *, f32, f32);
M2C_UNK func_00170520();                            /* extern */
extern M2C_UNK D_003DEAF0 __attribute__((section(".data")));

char *func_0028EDF0(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    func_00170520();
    M2C_FIELD(arg0, M2C_UNK **, 0xC0) = &D_003DEAF0;
    M2C_FIELD(arg0, s32 *, 0x2A0) = 0;
    M2C_FIELD(arg0, s32 *, 0x2A4) = 0;
    M2C_FIELD(arg0, s32 *, 0x2A8) = 0;
    M2C_FIELD(arg0, f32 *, 0x288) = fparg2;
    M2C_FIELD(arg0, f32 *, 0x28C) = fparg2;
    M2C_FIELD(arg0, f32 *, 0x280) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x284) = fparg1;
    M2C_FIELD(arg0, s32 *, 0x290) = 1;
    M2C_FIELD(arg0, s128 *, 0x270) = 0;
    func_00167550(arg0, fparg3, -1.0f);
    return arg0;
}
