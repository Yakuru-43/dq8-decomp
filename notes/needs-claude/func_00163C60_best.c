// range: 0x163C60 0x163E10
// best attempt score=72 CLASS structural, 2026-11-04 factory-1 (not committed as src)
#include "common.h"

typedef struct {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 pool_off;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ u32 count;
} NamePool;

extern s32 func_00133BE0(char *a0, char *a1);
extern u32 func_001341D8(char *);

s32 func_00163C60(u8 *arg0, NamePool *arg1, char *arg2) {
    char buf[0x40];
    char *dst;
    s32 ret;
    char *name;
    u8 *out;
    s32 idx;
    char *pool;
    s32 c;
    u32 n;

    dst = buf;
    n = 0x40;
    if (dst != 0) {
        do {
            *dst = 0;
            n = n - 1;
            dst = dst + 1;
        } while (n != 0);
    }
    out = arg0;
    name = arg2;
    ret = 1;
    dst = buf;
    while (1) {
        c = *name;
        while (c != '/' && c != '.' && c != 0 && c != '_' && c != '-') {
            *dst = c;
            dst = dst + 1;
            name = name + 1;
            c = *name;
        }
        if (c != 0) {
            if (name[1] == 0) {
                *dst = c;
                dst = dst + 1;
            }
        }
        *dst = 0;
        idx = 0;
        pool = (char *)arg1 + arg1->pool_off;
        while (idx < arg1->count) {
            if (func_00133BE0(buf, pool) == 0) {
                goto found;
            }
            pool = pool + func_001341D8(pool) + 1;
            idx = idx + 1;
        }
        idx = -1;
    found:
        if (idx < 0) {
            ret = 0;
            break;
        }
        if (idx < 0x80) {
            *out = idx;
            out = out + 1;
        } else {
            *out = (idx & 0x7F) | 0x80;
            out = out + 1;
            *out = idx >> 7;
            out = out + 1;
        }
        c = *name;
        if (c == 0) {
            break;
        }
        buf[0] = c;
        dst = buf + 1;
        name = name + 1;
        c = *name;
        if (c == 0) {
            break;
        }
        *dst = c;
        dst = dst + 1;
        name = name + 1;
    }
    *out = 0;
    return ret;
}
