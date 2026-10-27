// range: 0x1487A0 0x148830
#include "common.h"

extern char *func_001428D0(void);
extern s32 func_00148A80(char *, char *);
extern void func_0014E130(char *, s32);
extern void func_00141CA0(char *, char *);

void func_001487A0(char *arg0) {
    char *s1;
    char *s0;
    s32 v0;

    s1 = func_001428D0();
    if (s1 == 0) {
        return;
    }
    s0 = *(char **)((char *)s1 + 0x28) + (*(s32 *)((char *)s1 + 0x2C) << 4);
    if (s0 == 0) {
        return;
    }
    v0 = func_00148A80(arg0, s0);
    if (v0 <= 0) {
        return;
    }
    func_0014E130(s1, v0);
    func_00141CA0(arg0, s0);
}
