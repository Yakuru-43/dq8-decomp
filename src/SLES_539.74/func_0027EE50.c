// range: 0x27EE50 0x27EEF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
M2C_UNK func_0012EB08(M2C_UNK);                     /* extern */
M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_0014E130(M2C_UNK, s32);                    /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
M2C_UNK func_0027ED60(s32);                         /* extern */
extern M2C_UNK D_003CA180 __attribute__((section(".data")));
extern M2C_UNK D_003CA1A0 __attribute__((section(".data")));
extern s32 D_003E0DE4;

void func_0027EE50(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;
    s32 temp_v0;

    if (func_001629F0(&D_003CA180, arg0, &sp3C) != 0) {
        if (sp3C >= 0x2000) {
            DebugPrintf(&D_003CA1A0);
            func_0012EB08(1);
        }
        temp_v0 = func_0014E130(arg1, (sp3C >> 4) + 1);
        D_003E0DE4 = temp_v0;
        func_00130FD0(temp_v0, arg0, sp3C);
    }
    func_0027ED60(arg0);
}
