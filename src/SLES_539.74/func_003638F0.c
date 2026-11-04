// range: 0x3638F0 0x363A90
#include "common.h"

void func_00131188(void *, s32, s32);
u32 func_001341D8(char *);
s32 func_00134598(char *, char *, s32);

void func_003638F0(char **pos, char *buf, char *tag1, char *tag2, char *endTag) {
    char *cur;
    char *dst;
    s32 len1;
    s32 len2;
    s32 lenEnd;
    s32 skip;

    func_00131188(buf, 0, 0x180);
    func_00131188(buf + 0x180, 0, 0x180);
    func_00131188(buf + 0x300, 0, 0x180);
    len1 = 0;
    len2 = 0;
    lenEnd = 0;
    if (tag1 != 0) {
        len1 = func_001341D8(tag1);
    }
    if (tag2 != 0) {
        len2 = func_001341D8(tag2);
    }
    if (endTag != 0) {
        lenEnd = func_001341D8(endTag);
    }
    cur = *pos;
    dst = buf;
    while (*cur != 0) {
        skip = 0;
        if (*cur == '<') {
            if (func_00134598(cur, endTag, lenEnd) == 0) {
                cur += lenEnd;
                break;
            }
            if (func_00134598(cur, tag1, len1) == 0) {
                cur += len1;
                skip = 1;
                dst = buf + 0x180;
            } else if (func_00134598(cur, tag2, len2) == 0) {
                cur += len2;
                skip = 1;
                dst = buf + 0x300;
            }
        }
        if (skip == 0) {
            *dst = *cur;
            cur += 1;
            dst += 1;
        }
    }
    *pos = cur;
}
