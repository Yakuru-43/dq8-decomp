// range: 0x18A5F0 0x18A640
#include "common.h"

char * func_00130FD0(char *, const char *, u32);

void func_0018A5F0(char *arg0, s32 *arg1) {
    s32 buf[5];
    s32 *src;
    s32 *dst;
    s32 i;

    src = arg1;
    dst = buf;
    i = 5;
    do {
        i -= 1;
        *dst = *src;
        src += 1;
        dst += 1;
    } while (i > 0);

    *(s8 *)(arg0 + 0x68B4) = 1;
    func_00130FD0(arg0 + 0x68B8, (char *)buf, 0x14);
}
