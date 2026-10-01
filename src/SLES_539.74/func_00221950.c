// range: 0x221950 0x2219A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002F6010(s32, s32, M2C_UNK *);         /* extern */
extern M2C_UNK D_003C8228 __attribute__((section(".data")));

void func_00221950(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_002F6010(arg0, var_s0, &D_003C8228);
        var_s0 += 1;
    } while (var_s0 < 0x10);
}
