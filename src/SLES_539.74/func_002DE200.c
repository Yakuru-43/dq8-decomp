// range: 0x2DE200 0x2DE240
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE200(char *arg0) {
    if (func_002DE490(arg0, 0xD) != 0) {
        return *(s32 *)(arg0 + 0x2C);
    }
    return 0;
}
