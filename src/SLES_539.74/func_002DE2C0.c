// range: 0x2DE2C0 0x2DE300
#include "common.h"

s32 func_002DE490(char *, s32);

s32 func_002DE2C0(char *arg0) {
    char *obj;
    s32 ret;
    obj = arg0;
    if (func_002DE490(arg0, 6) != 0) {
        ret = *(s32 *)(obj + 0x2C);
    } else {
        ret = 0;
    }
    return ret;
}
