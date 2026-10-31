// range: 0x2DE180 0x2DE1C0
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE180(char *arg0) {
    s32 temp_v0;
    s32 result;
    temp_v0 = func_002DE490(arg0, 0xB);
    if (temp_v0 != 0) {
        result = *(s32 *)(arg0 + 0x2C);
    } else {
        result = 0;
    }
    return result;
}
