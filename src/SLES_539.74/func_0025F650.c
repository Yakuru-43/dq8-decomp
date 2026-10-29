// range: 0x25F650 0x25F6B0
#include "common.h"

s32 func_0025F650(char *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s8 c;

    arg0 += 0x10;
    i = 0;
    while (i < 4) {
        c = *(s8 *)arg0;
        if (0 < c) {
            if (c == arg1) {
                if (*(s32 *)(arg0 + 4) == arg2) {
                    return 1;
                }
            }
        }
        i++;
        arg0 += 0xF0;
    }
    return 0;
}
