// range: 0x21BFF0 0x21C2B0
#include "common.h"

struct Ent {
    u32 w0;
    u32 w1;
    s32 n;
};

s32 func_0021BFF0(s32 arg0, s32 arg1, s32 arg2, struct Ent *arg3, u16 *arg4,
                  s32 *arg5) {
    s32 end;
    s32 best;
    s32 cnt;
    s32 idx;
    s32 w;
    s32 words;
    u16 *p;
    u16 *h1;
    u16 *h2;
    u8 *b1;
    u8 *b2;
    u32 *d1;
    u32 *d2;

    best = 0;
    p = arg4;
    cnt = arg2;
    while (cnt > 0) {
        idx = *arg4;
        w = arg3[idx].n;
        arg4 = arg4 + 1;
        if (best < w) {
            best = w;
        }
        cnt = cnt - 1;
    }
    if (best == 1) {
        words = arg2 / 4;
        if (arg2 % 4 != 0) {
            words = words + 1;
        }
        *(u32 *)arg0 = 0x01000102;
        *(u32 *)(arg0 + 4) = 0x62000000 | ((arg1 | 0x8000) | (arg2 << 16));
        end = arg0 + 8 + words * 4;
        *(u32 *)end = 0x62000000 | (((arg1 + 1) | 0xC000) | (arg2 << 16));
        b1 = (u8 *)(arg0 + 8);
        b2 = (u8 *)(end + 4);
        while (arg2 > 0) {
            idx = *p;
            arg2 = arg2 - 1;
            p = p + 1;
            *b1 = *(s8 *)&arg3[idx].w0;
            b1 = b1 + 1;
            *b2 = *(u8 *)((char *)&arg3[idx].w0 + 4);
            b2 = b2 + 1;
        }
        end = end + words * 4 + 4;
    } else if (best < 3) {
        words = arg2 / 2;
        if (arg2 % 2 != 0) {
            words = words + 1;
        }
        *(u32 *)arg0 = 0x01000102;
        *(u32 *)(arg0 + 4) = 0x66000000 | ((arg1 | 0x8000) | (arg2 << 16));
        end = arg0 + 8 + words * 4;
        *(u32 *)end = 0x66000000 | (((arg1 + 1) | 0xC000) | (arg2 << 16));
        h1 = (u16 *)(arg0 + 8);
        h2 = (u16 *)(end + 4);
        while (arg2 > 0) {
            idx = *p;
            arg2 = arg2 - 1;
            p = p + 1;
            *h1 = *(s16 *)&arg3[idx].w0;
            h1 = h1 + 1;
            *h2 = *(s16 *)((char *)&arg3[idx].w0 + 4);
            h2 = h2 + 1;
        }
        end = end + words * 4 + 4;
    } else {
        *(u32 *)arg0 = 0x01000102;
        *(u32 *)(arg0 + 4) = 0x6E000000 | ((arg1 | 0x8000) | (arg2 << 16));
        end = arg0 + 8 + arg2 * 4;
        *(u32 *)end = 0x6E000000 | (((arg1 + 1) | 0xC000) | (arg2 << 16));
        d1 = (u32 *)(arg0 + 8);
        d2 = (u32 *)(end + 4);
        while (arg2 > 0) {
            idx = *p;
            p = p + 1;
            *d1 = arg3[idx].w0;
            d1 = d1 + 1;
            *d2 = arg3[idx].w1;
            d2 = d2 + 1;
            w = arg3[idx].n;
            if (best < w) {
                best = w;
            }
            arg2 = arg2 - 1;
        }
        end = (s32)d2;
    }
    *arg5 = best;
    return (end - arg0) / 4;
}
