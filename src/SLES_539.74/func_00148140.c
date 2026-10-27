// range: 0x148140 0x1481E0
#include "common.h"

extern char *func_001428D0(void);
extern s32 func_00148530(char *, char *, s32, s32);
extern void func_0014E130(char *, s32);
extern void func_00141C70(char *, s32);

void func_00148140(char *arg0, s32 arg1) {
    char *s0;
    char *s3;
    s32 v0;

    s0 = func_001428D0();
    if (s0 == 0) {
        return;
    }
    s3 = *(char **)((char *)s0 + 0x28) + (*(s32 *)((char *)s0 + 0x2C) << 4);
    if (s3 == 0) {
        return;
    }
    v0 = func_00148530(arg0, s3, arg1, 0);
    if (v0 <= 0) {
        return;
    }
    func_0014E130(s0, v0);
    func_00141C70(arg0, (s32)s3);
}
