// range: 0x20D8E0 0x20D920
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
M2C_UNK func_002106B0(s32);                         /* extern */
extern M2C_UNK D_003C7808 __attribute__((section(".data")));
extern s32 D_003E08D0;

void func_0020D8E0(void) {

    if (!(D_003E08D0 != 0)) {
        return;
    }

    func_002106B0(D_003E08D0);
    D_003E08D0 = 0;
    DebugPrintf(&D_003C7808);
}
