// range: 0x1AE1B0 0x1AE200
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001AE260(char *, s32);                 /* extern */

void func_001AE1B0(char *arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_001AE260(arg0 + (var_s0 << 6), M2C_FIELD(arg0, s32 *, 0x300));
        var_s0 += 1;
    } while (var_s0 < 0xC);
}
