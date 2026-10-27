// range: 0x46E8E0 0x46EA00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_1340C0(char *, M2C_UNK *);             /* extern */
extern M2C_UNK D_00484240 __attribute__((section(".data")));

void func_0046E8E0(char *arg0) {
    s32 var_a0;
    s32 var_s0;
    char *temp_a0;
    char *temp_s2;
    char *temp_v1;

    M2C_FIELD(arg0, s32 *, 0x2E08) = 0;
    var_s0 = 0;
    M2C_FIELD(arg0, s32 *, 0x2E0C) = 1;
    M2C_FIELD(arg0, s32 *, 0x2E1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E10) = 1;
    M2C_FIELD(arg0, s32 *, 0x2E14) = 1;
    M2C_FIELD(arg0, s32 *, 0x2E18) = 1;
    M2C_FIELD(arg0, s32 *, 0x2E28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E30) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E34) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E38) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E40) = 0;
    do {
        temp_s2 = arg0 + (var_s0 << 6);
        func_1340C0(temp_s2 + 0x2E64, &D_00484240);
        func_1340C0(temp_s2 + 0x2E84, &D_00484240);
        func_1340C0(arg0 + (var_s0 << 5) + 0x2FA4, &D_00484240);
        temp_a0 = arg0 + (var_s0 * 4);
        var_s0 += 1;
        M2C_FIELD(temp_a0, s32 *, 0x3044) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x3058) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x306C) = 0;
    } while (var_s0 < 5);
    var_a0 = 0;
    do {
        temp_v1 = arg0 + (var_a0 * 4);
        var_a0 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x30D0) = 0;
    } while (var_a0 < 8);
    M2C_FIELD(arg0, s32 *, 0x2E44) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E48) = 1;
    M2C_FIELD(arg0, s32 *, 0x2E4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E50) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E54) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E58) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E20) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E24) = 0;
    M2C_FIELD(arg0, s32 *, 0x2E60) = 0;
}
