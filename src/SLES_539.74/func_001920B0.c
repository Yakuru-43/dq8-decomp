// range: 0x1920B0 0x1920F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, s32);                /* extern */
M2C_UNK func_001920F0(s32 *, s32);                  /* extern */
extern M2C_UNK D_003C35D0 __attribute__((section(".data")));
extern s32 D_0040FBD0 __attribute__((section(".data")));

void func_001920B0(s32 arg0) {
    func_001920F0(&D_0040FBD0, arg0);
    DebugPrintf(&D_003C35D0, D_0040FBD0);
}
