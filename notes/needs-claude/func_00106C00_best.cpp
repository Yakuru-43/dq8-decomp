// range: 0x106C00 0x106C90
#include "common.h"

extern "C" {

struct Str {
    u32 f00;     /* 0x00: bit0 = heap flag; else byte 0 holds 2 * len */
    u32 heapLen; /* 0x04 */
    char *data;  /* 0x08 */
};

extern s32 func_00107730(struct Str *s, s32 from, s32 pos);

s32 func_00106C00(struct Str *s, s32 pos) {
    s32 len;
    char *base;
    s32 c;
    s32 r;
    u8 heap;

    heap = (s->f00 & 1) != 0;
    if (heap == false) {
        len = ((u8)s->f00 >> 1) & 0xFF;
    } else {
        len = s->heapLen;
    }
    if (len <= pos) {
        return -1;
    }
    if (heap != false) {
        base = s->data;
    } else {
        base = (char *)s + 1;
    }
    c = base[pos];
    if (c < 6) {
        return 1;
    }
    r = func_00107730(s, 0, pos + 1);
    return r != -1;
}

}
