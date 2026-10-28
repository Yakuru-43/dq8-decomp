// range: 0x1F2140 0x1F21E0
#include "common.h"

s32 func_0015F450(void);
s32 func_0015F490(void);
s32 func_0015AEF0(s32, char *, s32);
extern char D_00414FB0[];

void func_001F2140(void) {
    s32 i;
    s32 s0;
    char *s2;

    i = 0;
    do {
        func_0015F490();
        s0 = func_0015F450();
        s2 = D_00414FB0 + (i * 0x5C);
        *(s32 *)(s2 + 0x54) = func_0015AEF0(s0, s2, -1);
        *(s32 *)(s2 + 0x58) = func_0015AEF0(s0, s2 + 0x20, -1);
        i++;
    } while (i < 8);
}
