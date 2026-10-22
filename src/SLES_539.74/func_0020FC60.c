// range: 0x20FC60 0x20FCE0
#include "common.h"

u32 func_001341D8(char *);                            /* extern */
s32 func_0020FCE0(s8);                                 /* extern */

void func_0020FC60(char *dst, char *src) {
    s32 len = func_001341D8(src);
    s32 i;

    for (i = 0; i < len; i++) {
        dst[i] = func_0020FCE0(src[i]);
    }
    dst[i] = 0;
}
