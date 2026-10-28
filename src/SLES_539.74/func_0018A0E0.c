// range: 0x18A0E0 0x18A150
#include "common.h"

s32 func_0015F490(void);
void func_001419A0(f32, s32, s16);
void func_001DFC40(s16 *, char *);

void func_0018A0E0(char *arg0, s16 *arg1) {
    s32 temp_v0;

    if (*(s8 *)(arg0 + 0x6932) != 0) {
        temp_v0 = func_0015F490();
        if (arg1 != NULL) {
            func_001419A0(1.0f, temp_v0, *arg1);
        }
        func_001DFC40(arg1, arg0 + 0x6934);
    }
}
