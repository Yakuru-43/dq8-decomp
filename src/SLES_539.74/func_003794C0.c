// range: 0x3794C0 0x379510
#include "common.h"

extern void func_00379840(char *);
extern s8 D_003E1574;

void func_003794C0(s8 arg0, s32 *arg1) {
    s32 buf[87];
    char *src;
    char *dst;
    s32 i;

    src = (char *)arg1;
    dst = (char *)buf;
    i = 87;
    do {
        i -= 1;
        *(s32 *)dst = *(s32 *)src;
        src += 4;
        dst += 4;
    } while (i > 0);

    D_003E1574 = arg0;
    func_00379840((char *)buf);
}
