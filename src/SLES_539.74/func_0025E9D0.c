// range: 0x25E9D0 0x25EA10
#include "common.h"

extern int func_00131188(char *buf, s32 flags, s32 size);

int func_0025E9D0(char *arg0) {
    int result;

    result = func_00131188(arg0, 0, 0x170);
    *(s32 *)(arg0 + 0x140) = 0;
    *(u128 *)(arg0 + 0x150) = 0;
    return result;
}
