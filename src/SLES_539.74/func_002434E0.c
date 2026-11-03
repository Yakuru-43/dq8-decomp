// range: 0x2434E0 0x243630
#include "common.h"

s32 func_00164100(M2C_UNK *, s32);                  /* extern */
void func_0022AB50(s32);                             /* extern */
s32 func_002D6B20(void *, void *, void *, s32, s32); /* extern */
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));
extern M2C_UNK D_00416710 __attribute__((section(".data")));
extern s32 D_003DFC20;

s32 func_002434E0(void *arg0) {
    void *list;
    s32 *obj;
    s32 v;

    list = &D_00416710;
    obj = (s32 *)arg0;
    if (func_00164100(&D_003FAFB0, 0x1000) != 0 || func_00164100(&D_003FAFB0, 0x4000) != 0) {
        v = obj[0xAF3];
        if (v == 0) {
            obj[0xAF3] = 1;
        } else {
            obj[0xAF3] = 0;
        }
        func_002D6B20(list, (void *)0x1BAC, (void *)0x1BAD, -0x24, obj[0xAF3] * 25);
        func_0022AB50(0x28);
    }
    if (func_00164100(&D_003FAFB0, 0x244) != 0) {
        func_0022AB50(0);
    }
    if (func_00164100(&D_003FAFB0, 0x244) != 0) {
        if (obj[0xAF3] == 0) {
            return 1;
        }
    }
    if (func_00164100(&D_003FAFB0, D_003DFC20 | 0x101) != 0 ||
        (func_00164100(&D_003FAFB0, 0x244) != 0 && obj[0xAF3] == 1)) {
        return -1;
    }
    return 0;
}
