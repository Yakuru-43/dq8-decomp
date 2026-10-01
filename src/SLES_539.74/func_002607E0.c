// range: 0x2607E0 0x260880
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(char *, M2C_UNK *);           /* extern */
extern M2C_UNK D_003C9708 __attribute__((section(".data")));

void func_002607E0(char *arg0) {
    s32 var_a1;
    char *temp_v1;

    M2C_FIELD(arg0, s16 *, 0x50) = 2;
    M2C_FIELD(arg0, s16 *, 0x52) = 0;
    M2C_FIELD(arg0, s16 *, 0x58) = 0;
    M2C_FIELD(arg0, s16 *, 0x64) = -1;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0x3F800000;
    func_001340C0(arg0 + 0x40, &D_003C9708);
    var_a1 = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x30) = 0x41000000;
    } while (var_a1 < 4);
}
