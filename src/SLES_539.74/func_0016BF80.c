// range: 0x16BF80 0x16BFC0
#include "common.h"

s32 func_0016BF80(s32 *list) {
    s32 i;

    for (i = 1; i < 14; i = i + 1) {
        if (list[i] == 0) {
            return i;
        }
    }
    return -1;
}
