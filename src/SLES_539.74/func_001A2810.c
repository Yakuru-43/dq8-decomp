// range: 0x1A2810 0x1A2860
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, s32);                /* extern */
M2C_UNK func_001D5A10(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_003C3E00 __attribute__((section(".data")));
extern s32 D_003E0664;
extern M2C_UNK D_00410EE0 __attribute__((section(".data")));

void func_001A2810(s32 arg0, s32 arg1) {
    D_003E0664 = arg1;
    DebugPrintf(&D_003C3E00, arg0);
    func_001D5A10(&D_00410EE0, arg0);
}
