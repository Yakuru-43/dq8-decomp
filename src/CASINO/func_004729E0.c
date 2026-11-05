// range: 0x4729E0 0x472AD0
#include "common.h"

extern void func_131188(char *, s32, s32);

void func_004729E0(char *self) {
    s32 *slot;
    char *row;
    char *grp;
    char *rec;
    s32 i;
    s32 j;
    s32 k;

    i = 0;
    do {
        slot = (s32 *)(self + (i << 2));
        i = i + 1;
        *slot = 0;
    } while (i < 0x14);
    j = 0;
    do {
        row = self + (j << 2);
        j = j + 1;
        *(s32 *)(row + 0x550) = 0;
        *(s32 *)(row + 0x5A0) = 0;
        *(s32 *)(row + 0x5F0) = 0;
    } while (j < 0x14);
    k = 0;
    do {
        grp = self + k * 0xB00;
        i = 0;
        do {
            rec = grp + i * 88;
            func_131188(rec + 0x640, 0, 0x58);
            *(s32 *)(rec + 0x640) = 0;
            i = i + 1;
        } while (i < 0x20);
        k = k + 1;
    } while (k < 0x14);
}
