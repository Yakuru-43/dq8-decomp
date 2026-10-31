// range: 0x24BAD0 0x24BB10
#include "common.h"

extern int func_00131188(char *buf, s32 flags, s32 size);

int func_0024BAD0(char *arg0) {
    int result;

    result = func_00131188(arg0, 0, 0x240);
    arg0[0x6C] = 0;
    *(s32 *)(arg0 + 0x5C) = 0;
    return result;
}
