// range: 0x192130 0x192140
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001920F0(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_0040FBB0 __attribute__((section(".data")));

void func_00192130(s32 arg0) {
    func_001920F0(&D_0040FBB0, arg0);
}
