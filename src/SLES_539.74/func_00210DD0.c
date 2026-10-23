// range: 0x210DD0 0x210E10
#include "common.h"

s32 func_00210DD0(s32 base, s32 count) {
    s32 result = base;
    s32 i;

    count = count - 1;
    for (i = 0; i < count; i++) {
        result *= base;
    }
    return result;
}
