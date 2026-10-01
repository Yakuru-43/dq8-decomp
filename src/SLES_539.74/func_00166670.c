// range: 0x166670 0x1666E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
M2C_UNK func_001666E0(s32, s64 *);                  /* extern */
extern M2C_UNK D_003C2760 __attribute__((section(".data")));

void func_00166670(void *arg0, s64 arg1) {
    s64 sp28;
    s32 temp_v1;

    sp28 = arg1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_v1 >= M2C_FIELD(arg0, s32 *, 0x10)) {
        DebugPrintf(&D_003C2760);
        return;
    }
    func_001666E0(M2C_FIELD(arg0, s32 *, 0x14) + (temp_v1 * 8), &sp28);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
}
