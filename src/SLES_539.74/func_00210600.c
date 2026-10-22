// range: 0x210600 0x210660
#include "common.h"

s32 func_00210600(void *a0) {
    char *base = (char *)a0;
    s32 w;
    s32 h;
    s32 d;

    w = (*(s32 *)(base + 0x6768) + 0x3FF) / 0x400;
    h = (*(s32 *)(base + 0x676C) + 0x3FF) / 0x400;
    d = (*(s32 *)(base + 0x6770) + 0x3FF) / 0x400;
    return w + 1 + h + d;
}
