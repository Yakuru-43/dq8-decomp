// range: 0x1B2F00 0x1B2FB0
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, s32);                /* extern */
s32 func_001A2190(s32);
s32 func_001ADD10(s32);
void func_002E6BA0(void *, s32, s32);
extern M2C_UNK D_003C4508 __attribute__((section(".data")));

typedef struct {
    s32 field_00;
    f32 field_04;
    s32 field_08;
    f32 field_0C;
} S_arg0;

s32 func_001B2F00(S_arg0 *arg0) {
    s32 y;
    s32 a1;
    void *r;

    if (arg0->field_00 == 1) {
        a1 = (s32)arg0->field_04;
    } else {
        a1 = *(s32 *)&arg0->field_04;
    }
    if (arg0->field_08 == 1) {
        y = (s32)arg0->field_0C;
    } else {
        y = *(s32 *)&arg0->field_0C;
    }

    r = (void *)func_001A2190(a1);
    if (r == 0) {
        return 0;
    }

    if ((y = func_001ADD10(y)) == 0) {
        return 0;
    }

    DebugPrintf(&D_003C4508, y);
    func_002E6BA0(r, y, 0);
    return 1;
}
