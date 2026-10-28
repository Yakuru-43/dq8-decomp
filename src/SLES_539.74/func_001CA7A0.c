// range: 0x1CA7A0 0x1CA800
#include "common.h"

s32 func_001A2130(s32);
char *func_00151B40(s32);

s32 func_001CA7A0(char *arg0) {
    s32 value;
    f32 tmp;
    char *result;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        value = (s32)tmp;
    } else {
        value = *(s32 *)(arg0 + 4);
    }
    result = (char *)func_001A2130(value);
    if (result == 0) {
        return 0;
    }
    result = func_00151B40((s32)result);
    if (result == 0) {
        return 0;
    }
    if (*(s8 *)(result + 0x28) != 0) {
        *(s32 *)(result + 4) = 0;
    }
    return 1;
}
