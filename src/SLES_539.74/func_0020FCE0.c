// range: 0x20FCE0 0x20FD40
#include "common.h"

extern s8 D_003A53D0[];                                /* accent -> ascii pairs */
extern s8 D_003A53D1[];

s32 func_0020FCE0(s32 c) {
    s32 i;

    for (i = 0; D_003A53D0[2 * i] != 0; i++) {
        if ((s8)c == D_003A53D0[2 * i]) {
            return D_003A53D1[2 * i];
        }
    }
    return c;
}
