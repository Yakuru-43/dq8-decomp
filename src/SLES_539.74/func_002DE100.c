// range: 0x2DE100 0x2DE140
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE100(char *arg0) {
    s32 temp_v0;

    temp_v0 = func_002DE490(arg0, 0x13);
    if (temp_v0 != 0) {
        return *(s32 *)(arg0 + 0x2C);
    }
    return 0;
}
