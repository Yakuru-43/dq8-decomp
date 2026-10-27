// range: 0x1CB210 0x1CB260
#include "common.h"

char *func_001A2130(s32);

s32 func_001CB210(char *arg0) {
    s32 value;
    f32 tmp;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        value = (s32)tmp;
    } else {
        value = *(s32 *)(arg0 + 4);
    }
    if (func_001A2130(value) == 0) {
        return 0;
    }
    return 1;
}
