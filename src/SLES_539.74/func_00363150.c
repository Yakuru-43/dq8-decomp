// range: 0x363150 0x363190
#include "common.h"

extern s16 D_003E142C;
extern s32 D_003E1430;
extern s32 D_003E1434;
extern s32 D_004586C0[8];

void func_00363150(void) {
    s32 i;
    s32 *p;

    D_003E142C = 0;
    i = 0;
    D_003E1434 = 0;
    D_003E1430 = 0;
    do {
        p = &D_004586C0[i * 2];
        i += 1;
        p[0] = 0;
        p[1] = 0;
    } while (i < 4);
}
