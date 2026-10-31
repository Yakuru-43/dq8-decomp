// range: 0x2DE240 0x2DE280
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE240(char *arg0) {
    s32 temp_v0;
    temp_v0 = func_002DE490(arg0, 9);
    if (!temp_v0) {
        return 0;
    }
    return *(s32 *)(arg0 + 0x2C);
}
