// range: 0x1EA550 0x1EA5D0
#include "common.h"

extern f32 func_0013FCB0(s32, void *);
extern s32 func_0015F490(void);
extern void func_00149410(s32, void *, char *);

f32 func_001EA550(char *arg0) {
    u32 sp20[4];
    s32 temp_a0;

    if (*(s32 *)(arg0 + 0x1CC) == 0) {
        return 0.0f;
    }

    temp_a0 = *(s32 *)(arg0 + 4);
    if (temp_a0 == 0) {
        return func_0013FCB0(func_0015F490(), arg0 + 0x180);
    }

    func_00149410(temp_a0, sp20, arg0 + 0x180);
    return func_0013FCB0(func_0015F490(), sp20);
}
