// range: 0x2202A0 0x2202E0
#include "common.h"

s32 func_002202A0(s32 *list, s32 key) {
    s32 i;

    if (key == 0) {
        return -1;
    }
    for (i = 0; i < 16; i = i + 1) {
        if (list[i + 1] == key) {
            return i;
        }
    }
    return -1;
}
