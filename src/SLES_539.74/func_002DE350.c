// range: 0x2DE350 0x2DE390
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE350(char *arg0) {
    s32 ret;

    ret = func_002DE490(arg0, 3);
    if (ret) {
        return *(s32 *)(arg0 + 0x2C);
    }
    return 0;
}
