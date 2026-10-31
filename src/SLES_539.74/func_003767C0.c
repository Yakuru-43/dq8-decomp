// range: 0x3767C0 0x3768A0
#include "common.h"

void func_00131188(char *, s32, s32);

void func_003767C0(char *arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    *(s32 *)arg0 = 0;
    *(s32 *)(arg0 + 4) = arg1;
    *(s8 *)(arg0 + 0x15B) = 0;
    *(s8 *)(arg0 + 0x15A) = 0;

    i = 0;
    do {
        *(s32 *)(arg0 + (i * 4) + 8) = -0x270F;
        i++;
    } while (i < 0x10);

    j = 0;
    do {
        *(s32 *)(arg0 + (j * 4) + 0x48) = -0x270F;
        *(s8 *)(arg0 + j + 0x88) = -1;
        j++;
    } while (j < 0x10);

    k = 0;
    do {
        *(s32 *)(arg0 + (k * 4) + 0x98) = 0;
        k++;
    } while (k < 0x10);

    m = 0;
    do {
        *(s8 *)(arg0 + m + 0xD8) = -1;
        func_00131188(arg0 + (m << 6) + 0xDA, 0, 0x40);
        m++;
    } while (m < 2);
}
