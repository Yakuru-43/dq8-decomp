// range: 0x17A4D0 0x17A510
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK func_00361CE0();                            /* extern */
extern M2C_UNK D_003C2CA0 __attribute__((section(".data")));
extern M2C_UNK D_003C2CB8 __attribute__((section(".data")));
extern s32 D_003E0498;

void func_0017A4D0(void) {

    if (!(D_003E0498 != 0)) {
        return;
    }

    func_00361CE0();
    DebugPrintf(&D_003C2CB8, &D_003C2CA0);
}
