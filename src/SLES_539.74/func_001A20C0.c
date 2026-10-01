// range: 0x1A20C0 0x1A2130
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(char *, M2C_UNK *);           /* extern */
extern M2C_UNK D_003C3DE8 __attribute__((section(".data")));

void func_001A20C0(char *arg0) {
    s32 var_v1;
    char *temp_v0;

    var_v1 = 0;
    do {
        temp_v0 = arg0 + (var_v1 * 4);
        var_v1 += 1;
        M2C_FIELD(temp_v0, s32 *, 0xC0) = 0;
    } while (var_v1 < 6);
    M2C_FIELD(arg0, s8 *, 0xE0) = 1;
    M2C_FIELD(arg0, s8 *, 0xE1) = 0;
    M2C_FIELD(arg0, s32 *, 0xD8) = 0x200;
    M2C_FIELD(arg0, s32 *, 0xDC) = 0x1C0;
    func_001340C0(arg0, &D_003C3DE8);
    M2C_FIELD(arg0, s8 *, 0x80) = 0;
}
