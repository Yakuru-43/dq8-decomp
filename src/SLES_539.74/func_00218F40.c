// range: 0x218F40 0x218F80
#include "common.h"

s32 func_00218F40(s32 base, s32 count) {
    s32 result = base;
    s32 i = 0;

    count = count - 1;
    while (i < count) {
        result = result * base;
        i = i + 1;
    }
    return result;
}
