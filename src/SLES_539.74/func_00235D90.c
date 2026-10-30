// range: 0x235D90 0x235E10
#include "common.h"

extern void func_0013D290(char *);

void func_00235D90(char *arg0) {
    s32 i;
    char *p;

    *(s16 *)arg0 = 0;
    *(s16 *)(arg0 + 2) = -1;

    i = 0;
    do {
        p = arg0 + (i * 4);
        i += 1;
        *(s32 *)(p + 4) = 0;
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x10) = 0;
    } while (i < 3);

    *(s32 *)(arg0 + 0x28) = 0;

    i = 0;
    do {
        p = arg0 + (i * 4);
        i += 1;
        *(s32 *)(p + 0x30) = 0;
    } while (i < 3);

    i = 0;
    do {
        p = arg0 + (i * 4);
        i += 1;
        *(s32 *)(p + 0x3C) = 0;
    } while (i < 4);

    func_0013D290(arg0 + 0x50);
}
