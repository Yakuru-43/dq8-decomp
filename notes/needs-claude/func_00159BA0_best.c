// best attempt for func_00159BA0 (CLASS structural score=148, 772 vs 772 B)
// range would be: 0x159BA0 0x159EB0
#include "common.h"

extern s32 func_00130F38(void *a, void *b, s32 n);
extern void func_00131188(void *p, s32 val, s32 n);
extern void func_00130FD0(void *d, void *s, u32 n);
extern char D_003C20B0[];
extern char D_003C20B8[];
extern char D_003C20C0[];

typedef struct {
    /* 0x00 */ s8 tag[0x20];
    /* 0x20 */ u32 a;
    /* 0x24 */ u32 b;
    /* 0x28 */ u32 c;
    /* 0x2C */ u32 d;
    /* 0x30 */ u16 e;
    /* 0x32 */ u16 f;
    /* 0x34 */ u32 g;
    /* 0x38 */ u64 h;
} Rec;

typedef union {
    u64 w[8];
    Rec r;
} Pack;

void func_00159BA0(Pack *dst, s8 *src, s32 idx) {
    Pack buf;
    s32 kind;
    s32 i;
    s32 count;
    s32 stride;
    s8 *d;
    s8 *s;
    s32 j;

    func_00131188(buf.w, 0, 0x40);
    if (src == 0) {
        *dst = buf;
        return;
    }
    if (src == 0) {
        kind = 0;
    } else if (func_00130F38(src, D_003C20B0, 2) != 0) {
        kind = 0;
    } else if (func_00130F38(src, D_003C20B8, 3) == 0) {
        kind = 1;
    } else if (func_00130F38(src, D_003C20C0, 3) != 0) {
        kind = 0;
    } else {
        kind = 3;
    }
    if (kind == 0) {
        *dst = buf;
        return;
    }
    count = 0;
    stride = 0;
    if ((u32)(kind - 1) <= 1) {
        count = *(s32 *)(src + 4);
        stride = 0x30;
        src += 0x10;
    }
    if (kind == 3) {
        if (idx >= 0 && idx < *(s32 *)(src + 8)) {
            *dst = *(Pack *)(src + 0x10 + idx * 0x40);
            return;
        }
        *dst = buf;
        return;
    }
    for (i = 0; i < count; i++) {
        if (i == idx) {
            if (kind == 3) {
                d = buf.r.tag;
                s = src;
                for (j = 0x10; j > 0; j--) {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                }
                buf.r.a = *(u32 *)(src + 0x20);
                buf.r.b = *(u32 *)(src + 0x24);
                buf.r.c = *(u32 *)(src + 0x28);
                buf.r.d = *(u32 *)(src + 0x2C);
                buf.r.e = *(u16 *)(src + 0x30);
                buf.r.f = *(u16 *)(src + 0x32);
                buf.r.g = *(u32 *)(src + 0x34);
                buf.r.h = *(u64 *)(src + 0x38);
            } else if (kind == 1) {
                func_00130FD0(buf.r.tag, src, 0x20);
                buf.r.b = *(u32 *)(src + 0x20);
            } else if (kind == 2) {
                buf.r.c = 1;
                func_00130FD0(buf.r.tag, src, 0x20);
                buf.r.b = *(u32 *)(src + 0x20);
            }
        }
        src += stride;
    }
    *dst = buf;
}
