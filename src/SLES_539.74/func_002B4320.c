// range: 0x2B4320 0x2B43A0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0035E8F0(char *, s32);                 /* extern */
extern s32 D_0042CDB4 __attribute__((section(".data")));

void func_002B4320(s32 arg0, char *arg1) {
    s32 var_a0;
    char *temp_s0;

    var_a0 = arg0;
    M2C_FIELD(arg1, s32 *, 0xE0) = var_a0;
    temp_s0 = arg1 + 0xE0;
    if ((var_a0 < 0) || (var_a0 >= 0x2BA)) {
        var_a0 = 0;
    }
    M2C_FIELD(temp_s0, s32 *, 0x288) = (s32) (D_0042CDB4 + (var_a0 * 0x50));
    func_0035E8F0(temp_s0, M2C_FIELD(temp_s0, s32 *, 0x288));
    M2C_FIELD(temp_s0, s32 *, 0x60) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x64) = 1;
    M2C_FIELD(temp_s0, s8 *, 0x68) = 0;
}
