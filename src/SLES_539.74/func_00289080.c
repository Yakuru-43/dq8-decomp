// range: 0x289080 0x2891A0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013E090();                         /* extern */
M2C_UNK func_001526D0();                 /* extern */
M2C_UNK func_001EA0B0();                            /* extern */

void func_00289080(char *arg0) {
    s32 var_a0;
    s32 var_a1;
    char *temp_v0;
    char *temp_v1;

    func_001EA0B0();
    M2C_FIELD(arg0, s128 *, 0x480) = 0;
    func_0013E090(arg0 + 0x4A0);
    M2C_FIELD(arg0, s128 *, 0x490) = 0;
    M2C_FIELD(arg0, s8 *, 0x4B0) = 0;
    M2C_FIELD(arg0, s32 *, 0x448) = 0x3F800000;
    var_a1 = 0;
    M2C_FIELD(arg0, s32 *, 0x200) = 0;
    M2C_FIELD(arg0, s32 *, 0x470) = 0;
    M2C_FIELD(arg0, s32 *, 0x204) = 0;
    M2C_FIELD(arg0, s32 *, 0x208) = 0;
    M2C_FIELD(arg0, s32 *, 0x4D0) = 0;
    M2C_FIELD(arg0, s32 *, 0x4CC) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C8) = 0;
    M2C_FIELD(arg0, s32 *, 0x4DC) = -1;
    M2C_FIELD(arg0, s32 *, 0x220) = 0;
    M2C_FIELD(arg0, s32 *, 0x224) = 1;
    do {
        temp_v1 = arg0 + (var_a1 * 8);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x22C) = -1;
        M2C_FIELD(temp_v1, s32 *, 0x228) = -1;
        M2C_FIELD(temp_v1, s32 *, 0x24C) = -1;
        M2C_FIELD(temp_v1, s32 *, 0x248) = -1;
    } while (var_a1 < 4);
    M2C_FIELD(arg0, s32 *, 0x210) = 0;
    var_a0 = 0;
    M2C_FIELD(arg0, s32 *, 0x20C) = 0;
    do {
        temp_v0 = arg0 + (var_a0 * 4);
        var_a0 += 1;
        M2C_FIELD(temp_v0, s32 *, 0x468) = -1;
    } while (var_a0 < 2);
    M2C_FIELD(arg0, s32 *, 0x214) = 0;
    M2C_FIELD(arg0, s32 *, 0x218) = 0;
    M2C_FIELD(arg0, s32 *, 0x21C) = 0;
    func_001526D0(arg0 + 0x270, var_a1);
    M2C_FIELD(arg0, s32 *, 0x45C) = 0;
    M2C_FIELD(arg0, s32 *, 0x444) = 0;
    M2C_FIELD(arg0, s32 *, 0x430) = 0;
    M2C_FIELD(arg0, s32 *, 0x438) = 0;
    M2C_FIELD(arg0, s32 *, 0x434) = 0;
    M2C_FIELD(arg0, s32 *, 0x440) = 0;
    M2C_FIELD(arg0, s32 *, 0x43C) = 0;
    M2C_FIELD(arg0, s32 *, 0x464) = 0;
    M2C_FIELD(arg0, s32 *, 0x460) = 1;
    M2C_FIELD(arg0, s32 *, 0x44C) = 0;
    M2C_FIELD(arg0, s32 *, 0x450) = 1;
    M2C_FIELD(arg0, s32 *, 0x454) = 0;
    M2C_FIELD(arg0, s32 *, 0x458) = 0x3F800000;
}
