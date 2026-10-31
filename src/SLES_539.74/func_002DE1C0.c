// range: 0x2DE1C0 0x2DE200
#include "common.h"

s32 func_002DE490(char *arg0, s32 arg1);

s32 func_002DE1C0(char *arg0)
{
    s32 ret;

    ret = func_002DE490(arg0, 0xE);
    if (ret != 0) {
        return *(s32 *)(arg0 + 0x2C);
    }
    return 0;
}
