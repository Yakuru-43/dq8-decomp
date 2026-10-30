// range: 0x2C7F60 0x2C7FE0
#include "common.h"

extern s32 func_0014E130(void *a0, s32 a1);
extern s32 D_003E1064;

void func_002C7F60(void *a0) {
    s32 *p;
    s32 i, j;

    if (a0 == 0) {
        D_003E1064 = 0;
        return;
    }

    D_003E1064 = func_0014E130(a0, 0x60);
    p = (s32 *)D_003E1064;

    for (i = 0; i < 32; i++) {
        p[0] = 0;
        p[1] = 0;
        *(s16 *)((char *)p + 0x2C) = 0;
        for (j = 0; j < 4; j++) {
            p[j + 3] = 0;
            *(s32 *)((char *)p + 0x1C + (j << 2)) = 0;
        }
        p = (s32 *)((char *)p + 0x30);
    }
}
