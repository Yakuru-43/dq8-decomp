// range: 0x363CF0 0x363E20
#include "common.h"

u32 func_001341D8(char *);
s32 func_00134598(char *, char *, s32);

void func_00363CF0(char **cursor, char **out, s32 mode, char **tags) {
    char *cur;
    char *dst;
    char *tag1;
    char *tag2;
    s32 len1;
    s32 len2;
    s32 skip;

    cur = *cursor;
    dst = *out;
    tag1 = *tags;
    tag2 = tags[1];
    len1 = func_001341D8(tag1);
    len2 = func_001341D8(tag2);
    while (*cur != 0) {
        skip = 0;
        if (*cur == '<') {
            if (func_00134598(cur, tag1, len1) == 0) {
                cur += len1;
                break;
            }
            if (func_00134598(cur, tag2, len2) == 0) {
                cur += len2;
                skip = 1;
                mode = (u8)!mode;
            }
        }
        if (skip == 0) {
            if (mode != 0) {
                *dst = *cur;
                dst += 1;
                cur += 1;
            } else {
                cur += 1;
            }
        }
    }
    *cursor = cur;
    *out = dst;
}
