// range: 0x2DE450 0x2DE490
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE450(char *arg0) {
    s32 temp_v0;

    temp_v0 = func_002DE490(arg0, 1);
    if (temp_v0 != 0) {
        return *(s32 *)(arg0 + 0x2C);
    }
    return 0;
}
